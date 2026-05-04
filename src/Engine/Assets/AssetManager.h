#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>

using AssetHandle = uint32_t;
constexpr AssetHandle INVALID_ASSET_HANDLE = 0;

template<typename T>
class AssetPool {
public:
    AssetHandle Add(std::unique_ptr<T> asset) {
        AssetHandle handle = ++nextHandle;
        assets[handle] = std::move(asset);
        return handle;
    }

    T* Get(AssetHandle handle) {
        auto it = assets.find(handle);
        if (it != assets.end()) {
            return it->second.get();
        }
        return nullptr;
    }

    void Remove(AssetHandle handle) {
        assets.erase(handle);
    }

private:
    std::unordered_map<AssetHandle, std::unique_ptr<T>> assets;
    AssetHandle nextHandle = 0;
};

class VertexArray; 
class Shader;

class AssetManager {
public:
    static AssetManager& Get() {
        static AssetManager instance;
        return instance;
    }

    AssetPool<VertexArray> meshes;
    AssetPool<Shader> shaders;
    // AssetPool<Texture> textures; // Add this later

private:
    AssetManager() = default;
};