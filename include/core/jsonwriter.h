#ifndef MEH_JSONWRITER_H
#define MEH_JSONWRITER_H

#include <string>

#include "json/json.h"

using namespace std;

namespace meh
{

class JsonWriter
{
    private:
    protected:
    public:
        /**
         * Default constructor.
         */
        JsonWriter();
        ~JsonWriter();

        /**
         * Reads a file as a JSON by its filename.
         * @param filename      the path to the file to write.
         * @param json          the json to write.
         * @param pretty        whether the generated file should be human-readable.
         * @return true if the write succeed.
         */
        bool write(string filename, Json::Value json, bool pretty);
};

} // namespace meh

#endif // MEH_JSONREADER_H
