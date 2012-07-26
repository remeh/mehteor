#ifndef MEH_RESOURCES_MANAGER_H
#define MEH_RESOURCES_MANAGER_H

#include <map>
#include <string>

#include "graphics/texture.h"

using namespace std;

namespace meh {

class ResourcesManager {
    private:
        map<string, Texture*> mapTextures;

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
         * Retrieves a loaded Texture by its uniqueId.
         * Returns nullptr whether it isn't already loaded.
         *
         * \return the Texture found in the ResouresManager. Nullptr otherwise.
         */
        Texture* getTexture(string uniqueId);

        /**
         * Removes the Texture from this ResourcesManager and delete the memory
         * allocated for this Texture.
         *
         * \return whether the deletion succeed.
         */
        bool deleteTexture(string uniqueId);
        
        /**
         * Removes the Texture from this ResourcesManager but contrary to deleteTexture(string),
         * it doesn't delete the memory but returns the Texture. Returns nullptr whether
         * this uniqueId doesn't refer to any Texture.
         *
         * \return the Texture removed from the ResourcesManager.
         */
        Texture* removeTexture(string uniqueId);
};


}

#endif // MEH_RESOURCES_MANAGER_H

