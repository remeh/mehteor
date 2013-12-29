#include <fstream>

#include "json/json.h"
#include "core/jsonwriter.h"

using namespace std;

namespace meh
{

JsonWriter::JsonWriter()
{
}

JsonWriter::~JsonWriter()
{
}

bool JsonWriter::write(string filename, Json::Value json, bool pretty)
{
    /*
     * prepare the file
     */
    
    ofstream output(filename);

    /*
     * write it
     */

    Json::Writer* writer = nullptr;

    if (pretty)
    {
        writer = new Json::FastWriter();
    }
    else
    {
        writer = new Json::StyledWriter();
    }


    if (!writer)
    {
        return false;
    }

    string textJson = writer->write(json);

    output.write(textJson.data(), textJson.length());

    output.close();

    if (writer)
    {
        delete writer;
    }

    return true;
}

} // namespace meh

