#pragma once
#include "Engine/Assets/AssetManager.h"

struct RenderComponent {
    AssetHandle meshHandle = INVALID_ASSET_HANDLE;
    AssetHandle shaderHandle = INVALID_ASSET_HANDLE;
    AssetHandle textureHandle = INVALID_ASSET_HANDLE; 
};