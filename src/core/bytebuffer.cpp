#include <cstring>

#include "core/bytebuffer.h"

namespace meh {

ByteBuffer::ByteBuffer(int length) :
    len(length) {
    dta = new unsigned char[length];
    // Reset the cursor position
    reset();
}

ByteBuffer::~ByteBuffer() {
    delete[] dta;
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
    if (length+crsor >= len) {
        return -1;
    }
    // Copy the data
    // memcpy(dta+crsor,data,length); XXX
    for (int i = 0; i < length; i++) {
        dta[crsor+i] = data[i];
    }
    crsor += length;
    return 0;
}

int ByteBuffer::write(char* data, int length) {
    return write((unsigned char*)data,length);
}

void ByteBuffer::resize(int newLength, bool saveData) {
    if (!saveData) {
        // Deletes the old buffer
        delete[] dta;
        // Allocates the new buffer
        dta = new unsigned char[newLength];
    } else {
        // Keep the data somewhere
        unsigned char* tmp = dta;
        // Allocates the new buffer
        dta = new unsigned char[newLength];
        // Do not copy too much if the new 
        // ByteBuffer if smaller
        int l = len;
        if (len > newLength) {
            l = newLength;
        }
        // Copy the data
        memcpy(dta,tmp,l);
        // Releases the old buffer
        delete[] tmp;
    }
    len = newLength;
    reset();
}

ByteBuffer* ByteBuffer::clone() {
    ByteBuffer* copy = new ByteBuffer(len);
    copy->write(dta, len);
    return copy;
}

}
