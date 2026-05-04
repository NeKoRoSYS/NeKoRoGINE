#pragma once
#include "Engine/ECS/ECS.h"
#include "Engine/ECS/Components/Transform.h"
#include "Engine/ECS/Components/Renderable.h"
#include "Engine/ECS/Components/Camera.h"
#include "Engine/Assets/AssetManager.h"
#include "Engine/Rendering/RenderCommand.h"
#include "Engine/Rendering/Shader.h"

namespace RenderSystem {
    inline void Update(Registry& registry) {
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
        
        auto cameraArrayPtr = registry.GetComponentArray<CameraComponent>();
        auto& cameras = cameraArrayPtr->GetPackedArray();
        
        for (size_t i = 0; i < cameraArrayPtr->GetValidSize(); ++i) {
            if (cameras[i].isPrimary) {
                view = cameras[i].viewMatrix;
                projection = cameras[i].projectionMatrix;
                break;
            }
        }

        auto renderArrayPtr = registry.GetComponentArray<RenderComponent>();
        auto& renderables = renderArrayPtr->GetPackedArray();
        auto& indexToEntity = renderArrayPtr->GetIndexToEntityMap();

        for (size_t i = 0; i < renderArrayPtr->GetValidSize(); ++i) {
            auto& renderable = renderables[i];
            
            VertexArray* vao = AssetManager::Get().meshes.Get(renderable.meshHandle);
            Shader* shader = AssetManager::Get().shaders.Get(renderable.shaderHandle);

            if (!vao || !shader) continue;

            Entity entity = indexToEntity[i];
            auto& transform = registry.GetComponent<TransformComponent>(entity);

            shader->Use();
            shader->SetMat4("u_View", view);
            shader->SetMat4("u_Projection", projection);
            shader->SetMat4("u_Model", transform.modelMatrix);

            vao->Bind();
            RenderCommand::DrawIndexed(vao);
        }
    }
}