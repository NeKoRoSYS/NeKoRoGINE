#pragma once

enum class RendererAPIType {
    None = 0, OpenGL = 1, Vulkan = 2
};

class RendererAPI {
public:
    inline static RendererAPIType GetAPI() { return s_API; }
private:
    static RendererAPIType s_API;
};