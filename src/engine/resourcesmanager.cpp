#include "engine/resourcesmanager.h"
#include "graphics/texture.h"

namespace meh {

ResourcesManager::ResourcesManager() {
}

ResourcesManager::~ResourcesManager() {

}

Texture* ResourcesManager::loadTexture(string uniqueId, string filepath) {
    Texture* texture = new Texture(filepath);
    if (texture) {
        addTexture(uniqueId, texture);
    } else {
        printf("ERROR: while loading the texture %s\n",filepath.c_str());
    }
    return texture;
}

Texture* ResourcesManager::addTexture(string uniqueId, Texture* texture) {
    if (texture == nullptr) {
        return nullptr;
    }
    if (mapTextures.count(uniqueId) == 1) {
        printf("WARN: the uniqueId '%s' for texture was already used, the old instance of the resource is deleted.",uniqueId.c_str());
        this->deleteTexture(uniqueId);
    }
    mapTextures[uniqueId] = texture;
    return mapTextures[uniqueId];
}

Texture* ResourcesManager::getTexture(string uniqueId) {
    if (mapTextures.count(uniqueId) == 1) {
        return mapTextures[uniqueId];
    }
    return nullptr;
}

bool ResourcesManager::deleteTexture(string uniqueId) {
    auto it = mapTextures.find(uniqueId);
    if (it != mapTextures.end()) {
        delete it->second;
        mapTextures.erase(it);
        return true;
    }
    return false;
}

Texture* ResourcesManager::removeTexture(string uniqueId) {
    auto it = mapTextures.find(uniqueId);
    if (it != mapTextures.end()) {
        Texture* ret = it->second;
        mapTextures.erase(it);
        return ret;
    }
    return nullptr;
}

} // namespace meh
