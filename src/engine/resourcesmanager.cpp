#include "engine/resourcesmanager.h"
#include "graphics/texture.h"
#include "audio/sound.h"

namespace meh {

ResourcesManager::ResourcesManager() {
}

ResourcesManager::~ResourcesManager() {
    for (auto it = mapTextures.begin(); it != mapTextures.end(); it++) {
        delete it->second;
    }
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

Sound* ResourcesManager::loadSound(string uniqueId, string filepath) {
    Sound* sound = new Sound(filepath);
    if (sound) {
        addSound(uniqueId, sound);
    } else {
        printf("ERROR: while loading the texture %s\n",filepath.c_str());
    }
    return sound;
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

Sound* ResourcesManager::addSound(string uniqueId, Sound* sound) {
    if (sound == nullptr) {
        return nullptr;
    }
    if (mapSounds.count(uniqueId) == 1) {
        printf("WARN: the uniqueId '%s' for sound was already used, the old instance of the resource is deleted.",uniqueId.c_str());
        this->deleteSound(uniqueId);
    }
    mapSounds[uniqueId] = sound;
    return mapSounds[uniqueId];
}

Texture* ResourcesManager::getTexture(string uniqueId) {
    if (mapTextures.count(uniqueId) == 1) {
        return mapTextures[uniqueId];
    }
    return nullptr;
}

Sound* ResourcesManager::getSound(string uniqueId) {
    if (mapSounds.count(uniqueId) == 1) {
        return mapSounds[uniqueId];
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

bool ResourcesManager::deleteSound(string uniqueId) {
    auto it = mapSounds.find(uniqueId);
    if (it != mapSounds.end()) {
        delete it->second;
        mapSounds.erase(it);
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

Sound* ResourcesManager::removeSound(string uniqueId) {
    auto it = mapSounds.find(uniqueId);
    if (it != mapSounds.end()) {
        Sound* ret = it->second;
        mapSounds.erase(it);
        return ret;
    }
    return nullptr;
}

} // namespace meh
