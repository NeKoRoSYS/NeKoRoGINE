#include "Engine/Rendering/Mesh.h"
#include "Engine/Rendering/Shader.h"

struct RenderComponent {
    Mesh* mesh = nullptr;
    Shader* shader = nullptr;
    unsigned int textureID = 0; 
};