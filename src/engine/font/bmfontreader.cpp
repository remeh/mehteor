#include <cstdio> // printf
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include "engine/font/bmfontreader.h"
#include "engine/font/bmglyphinfo.h"

namespace meh {

BMFontReader::BMFontReader(string filepath) :
    flepath(filepath) {
}

BMFontReader::~BMFontReader() {
}

map<int, BMGlyphInfo>* BMFontReader::read() {
    ifstream input(flepath.data());

    // first read the header of 4 lines
    readHeader(input);

    // store every char information into a map to access them easily by char id
    map<int, BMGlyphInfo>* infos = readData(input);

    // release the file resource
    input.close();

    return infos;
}

void BMFontReader::readHeader(ifstream& input) {
    string line;
    for (int i = 0; i < 4; i++) {
        getline(input, line);
        // TODO errors check and other use of the headers
    }
}

map<int, BMGlyphInfo>* BMFontReader::readData(ifstream& input) {
    int i = -1;
    int id, x , y, width, height, xoffset, yoffset, xadvance, page, channel;
    map<int, BMGlyphInfo>* infos = new map<int, BMGlyphInfo>();

    // read line by line and split with the separator =
    for( string line; getline( input, line, '='); )
    {
        stringstream stream(line);
        switch (i) {
            case 0:
                stream >> id;
                break;
            case 1:
                stream >> x;
                break;
            case 2:
                stream >> y;
                break;
            case 3:
                stream >> width;
                break;
            case 4:
                stream >> height;
                break;
            case 5:
                stream >> xoffset;
                break;
            case 6:
                stream >> yoffset;
                break;
            case 7:
                stream >> xadvance;
                break;
            case 8:
                stream >> page;
                break;
            case 9:
                stream >> channel;
                infos->insert( pair<int, BMGlyphInfo>( id, BMGlyphInfo(id, x, y, width, height, xoffset, yoffset, xadvance, page, channel) ) );
                i = -1;
                break;
        }
        i++;
    }

    return infos;
}

} // namespace meh
