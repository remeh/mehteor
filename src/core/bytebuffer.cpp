#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "core/bytebuffer.h"

namespace meh {

ByteBuffer::ByteBuffer(int length) :
    len(length) {
    dta = (unsigned char*)malloc(length*sizeof(unsigned char));
    // Reset the cursor position
    reset();
}

ByteBuffer::~ByteBuffer() {
    free(dta);
}

unsigned char ByteBuffer::readUChar() {
    if (crsor >= len) {
        return -1;
    }
    char c = dta[crsor++];
    return c;
}

int ByteBuffer::writeUChar(unsigned char c) {
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

int ByteBuffer::write(unsigned char* data, int length) {
    if (length+crsor > len) {
        return -1;
    }
    // Copy the data
    dta = (unsigned char*)memcpy(dta+crsor,data,length*sizeof(unsigned char));
    crsor += length;
    return 0;
}

int ByteBuffer::write(char* data, int length) {
    return write((unsigned char*)data,length);
}

void ByteBuffer::resize(int newLength, bool saveData) {
    if (!saveData) {
        // Deletes the old buffer
        free(dta);
        // Allocates the new buffer
        dta = (unsigned char*)malloc(newLength*sizeof(unsigned char));
    } else {
        // Keep the data somewhere
        unsigned char* tmp = dta;
        // Allocates the new buffer
        dta = (unsigned char*)malloc(newLength*sizeof(unsigned char));
        // Do not copy too much if the new 
        // ByteBuffer if smaller
        int l = len;
        if (len > newLength) {
            l = newLength;
        }
        // Copy the data
        memcpy(dta,tmp,l*sizeof(unsigned char));
        // Releases the old buffer
        free(tmp);
    }
    len = newLength;
    reset();
}

ByteBuffer* ByteBuffer::clone() {
    ByteBuffer* copy = new ByteBuffer(len);
    copy->write(dta, len);
    return copy;
}

void ByteBuffer::setData(unsigned char* data, int length) {
    // resize the buffer if necessary
    if (length > len) {
        resize(length);
    }
    dta = data;
    len = length;
}

}
