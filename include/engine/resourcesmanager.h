#ifndef MEH_RESOURCES_MANAGER_H
#define MEH_RESOURCES_MANAGER_H

#include <map>
#include <string>

#include "graphics/texture.h"
#include "audio/sound.h"

using namespace std;

namespace meh {

class ResourcesManager {
    private:
        map<string, Texture*> mapTextures;
        map<string, Sound*> mapSounds;

    protected:
    public:
        /**
         * Default constructor.
         */
        ResourcesManager();
        /**
         * Destructor
         */
        ~ResourcesManager();

        /**
         * Returns a reference to the map of textures.
         *
         * \return a reference to the map of textures.
         */
        map<string, Texture*>& textures() {
            return mapTextures;
        }

        /**
         * Loads a Texture from a file and adds it to the ResourcesManager.
         *
         * <b>WARNING</b>
         *  - if the uniqueId is already used, the old Texture will be deleted
         *
         * @param uniqueId the unique name given to this Texture 
         * @param filepath the path to the texture 
         *
         * \return a pointer to the Texture added to the ResourcesManager
         */
        Texture* loadTexture(string uniqueId, string filepath);


        /**
         * Loads a Sound from a file and adds it to the ResourcesManager.
         *
         * <b>WARNING</b>
         *  - if the uniqueId is already used, the old Sound will be deleted
         *
         * @param uniqueId the unique name given to this Sound 
         * @param filepath the path to the texture 
         *
         * \return a pointer to the Sound added to the ResourcesManager
         */
        Sound* loadSound(string uniqueId, string filepath);

        /**
         * Adds an existing Texture into the ResourcesManager
         *
         * <b>WARNING</b>
         *  - the memory of the texture will be managed by the ResourcesManager
         *  - if the uniqueId is already used, the old Texture will be deleted
         *
         * @param uniqueId the unique id of this resource
         * @param texture the Texture to delegate to the ResourcesManager
         *
         * \return a pointer to the Texture added to the ResourcesManager
         */
        Texture* addTexture(string uniqueId, Texture* texture);

        /**
         * Adds an existing Sound into the ResourcesManager
         *
         * <b>WARNING</b>
         *  - the memory of the sound will be managed by the ResourcesManager
         *  - if the uniqueId is already used, the old Sound will be deleted
         *
         * @param uniqueId the unique id of this resource
         * @param sound the Sound to delegate to the ResourcesManager
         *
         * \return a pointer to the Sound added to the ResourcesManager
         */
        Sound* addSound(string uniqueId, Sound* sound);

        /**
         * Retrieves a loaded Texture by its uniqueId.
         * Returns nullptr whether it isn't already loaded.
         *
         * \return the Texture found in the ResouresManager. Nullptr otherwise.
         */
        Texture* getTexture(string uniqueId);

        /**
         * Retrieves a loaded Sound by its uniqueId.
         * Returns nullptr whether it isn't already loaded.
         *
         * \return the Sound found in the ResouresManager. Nullptr otherwise.
         */
        Sound* getSound(string uniqueId);

        /**
         * Removes the Texture from this ResourcesManager and delete the memory
         * allocated for this Texture.
         *
         * \return whether the deletion succeed.
         */
        bool deleteTexture(string uniqueId);

        /**
         * Removes the Sound from this ResourcesManager and delete the memory
         * allocated for this Sound.
         *
         * \return whether the deletion succeed.
         */
        bool deleteSound(string uniqueId);
        
        /**
         * Removes the Texture from this ResourcesManager but contrary to deleteTexture(string),
         * it doesn't delete the memory but returns the Texture. Returns nullptr whether
         * this uniqueId doesn't refer to any Texture.
         *
         * \return the Texture removed from the ResourcesManager.
         */
        Texture* removeTexture(string uniqueId);
        
        /**
         * Removes the Sound from this ResourcesManager but contrary to deleteSound(string),
         * it doesn't delete the memory but returns the Sound. Returns nullptr whether
         * this uniqueId doesn't refer to any Sound.
         *
         * \return the Sound removed from the ResourcesManager.
         */
        Sound* removeSound(string uniqueId);
};


}

#endif // MEH_RESOURCES_MANAGER_H

