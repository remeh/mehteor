#ifndef MEH_JSONREADER_H
#define MEH_JSONREADER_H

#include <string>

#include "json/json.h"

using namespace std;

namespace meh
{

class JsonReader
{
    private:
        string filename;

        /**
         * The root value.
         */
        Json::Value root;

        /**
         * Reads the file.
         */
        void read();

    protected:
    public:
        /**
         * Default constructor.
         */
        JsonReader();
        ~JsonReader();

        /**
         * Reads a file as a JSON by its filename.
         * @param filename      the path to the file to read.
         * @return true if the read succeed.
         */
        bool read(string filename);
        
        /**
         * Returns the root node of the file.
         */
        Json::Value getRoot();
};

} // namespace meh

#endif // MEH_JSONREADER_H
