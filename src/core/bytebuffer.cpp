#include <cstring>

#include "core/bytebuffer.h"

namespace meh {

ByteBuffer::ByteBuffer(int length) :
    len(length) {
    dta = new char[length];
    // Reset the cursor position
    reset();
}

ByteBuffer::~ByteBuffer() {
    delete[] dta;
}

char ByteBuffer::readChar() {
    if (crsor >= len) {
        return -1;
    }
    char c = dta[crsor++];
    return c;
}

int ByteBuffer::writeChar(char c) {
    if (crsor >= len) {
        return -1;
    }
    dta[crsor] = c;
    crsor++;
    return 0;
}

void ByteBuffer::reset() {
    crsor = 0;
}

int ByteBuffer::write(char* data, int length) {
    if (length+crsor >= len) {
        return -1;
    }
    for (int i = 0; i < length; i++) {
        dta[crsor+i] = data[i];
    }
    crsor += length;
    return 0;
}

void ByteBuffer::resize(int newLength, bool saveData) {
    if (!saveData) {
        // Deletes the old buffer
        delete[] dta;
        // Allocates the new buffer
        dta = new char[newLength];
    } else {
        // Keep the data somewhere
        char* tmp = dta;
        // Allocates the new buffer
        dta = new char[newLength];
        // Do not copy too much if the new 
        // ByteBuffer if smaller
        int l = len;
        if (len > newLength) {
            l = newLength;
        }
        // Copy the data
        for (int i = 0; i < l; i++) {
            dta[i] = tmp[i];
        }
        // Releases the old buffer
        delete[] tmp;
    }
    len = newLength;
    reset();
}

}
