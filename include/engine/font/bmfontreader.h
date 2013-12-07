#ifndef MEH_BMFONTREADER_H
#define MEH_BMFONTREADER_H

#include <string>
#include <map>
#include <fstream>
#include "engine/font/bmglyphinfo.h"

using namespace std;

namespace meh {

/**
 * A BMFont text file reader.
 * @author Rémy 'remeh' MATHIEU
 */
class BMFontReader {
    private:
        /**
         * Path to the file.
         */
        string flepath;

    protected:
    public:
        /**
         * Constructs a reader for the givne file.
         * @param filepath      full path to the file to read
         */
        BMFontReader(string filepath);

        /**
         * Destructor.
         */
        ~BMFontReader();

        /**
         * Reads the file description to return a font renderer.
         * TODO font renderer
         */
        void read();

        /**
         * Reads the header of the BMFont descriptor.
         * @param &input        the input file
         */
        void readHeader(ifstream& input);

        /**
         * Reads the content of the descriptor file and write in a map every char information.
         * @param &input      the file to read
         * @return map<int, BMGlyphInfo>*   containing all the char information with char id as map index.
         */
        map<int, BMGlyphInfo>* readData(ifstream& input);

        /**
         * Returns the filepath.
         * @return string       the file path of the file to read.
         */
        string& filepath() {
            return flepath;
        }
};

} // namespace meh

#endif // MEH_BMFONTREADER_H

