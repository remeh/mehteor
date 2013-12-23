#include <fstream>

#include "json/json.h"
#include "core/jsonreader.h"

using namespace std;

namespace meh
{

JsonReader::JsonReader()
{
}

JsonReader::~JsonReader()
{
}

bool JsonReader::read(string filename)
{
    this->filename = filename;

    /*
     * open the file
     */
    
    ifstream input(filename);

    /*
     * parse it
     */

    Json::Reader reader;
    bool parsingSuccessful = reader.parse( input, this->root );

    input.close();

    return parsingSuccessful;
}

Json::Value JsonReader::getRoot()
{
    return root;
}

} // namespace meh
