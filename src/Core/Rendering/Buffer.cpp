#include "Buffer.h"
#include "RendererAPI.h"
#include "OpenGL/OpenGLBuffer.h"
#include <stdexcept>

std::unique_ptr<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size) {
    switch (RendererAPI::GetAPI()) {
        case RendererAPIType::None:    
            throw std::runtime_error("RendererAPI::None is currently not supported!");
        case RendererAPIType::OpenGL:  
            return std::make_unique<OpenGLVertexBuffer>(vertices, size);
        case RendererAPIType::Vulkan:  
            throw std::runtime_error("Vulkan is not yet implemented!");
    }
    throw std::runtime_error("Unknown RendererAPI!");
}

std::unique_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count) {
    switch (RendererAPI::GetAPI()) {
        case RendererAPIType::None:    
            throw std::runtime_error("RendererAPI::None is currently not supported!");
        case RendererAPIType::OpenGL:  
            return std::make_unique<OpenGLIndexBuffer>(indices, count);
        case RendererAPIType::Vulkan:  
            throw std::runtime_error("Vulkan is not yet implemented!");
    }
    throw std::runtime_error("Unknown RendererAPI!");
}

std::unique_ptr<VertexArray> VertexArray::Create() {
    switch (RendererAPI::GetAPI()) {
        case RendererAPIType::None:    
            throw std::runtime_error("RendererAPI::None is currently not supported!");
        case RendererAPIType::OpenGL:  
            return std::make_unique<OpenGLVertexArray>();
        case RendererAPIType::Vulkan:  
            throw std::runtime_error("Vulkan is not yet implemented!");
    }
    throw std::runtime_error("Unknown RendererAPI!");
}