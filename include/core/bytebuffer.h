#ifndef MEH_BYTEBUFFER_H
#define MEH_BYTEBUFFER_H

namespace meh {

class ByteBuffer {
    private:
        char* dta;
        int len;
        int crsor;

    protected:
    public:
        /**
         * Constructs a ByteBuffer of 1 byte.
         */
        ByteBuffer() : ByteBuffer(1) {};

        /**
         * Constructs a ByteBuffer of 'size' bytes.
         * Directly allocates the memory.
         */
        ByteBuffer(int length);
        ~ByteBuffer();

        /**
         * Direct pointer to the data of this buffer.
         */
        char* data() {
            return dta;
        }
        
        /**
         * Returns the length of this buffer.
         */
        int length() {
            return len;
        }

        /**
         * Returns how many bytes left before to reach the end of this buffer.
         */
        int leftLength() {
            return len-crsor;
        }

        /**
         * Releases the memory currently hold by this ByteBuffer and allocates
         * the new byte array. Could keep the data by using the parameter saveData.
         * Also resets the cursor.
         * @param newLength the new length of this ByteBuffer
         * @param saveData whether the data should be saved.
         */
        void resize(int newLength, bool saveData = false);

        /**
         * Returns the cursor position in the buffer.
         */
        int cursor() {
            return crsor;
        }

        /**
         * Reset the cursor position to the start of the buffer.
         */
        void reset();

        /**
         * Reads and returns a char in the ByteBuffer and move the cursor of 1 byte.
         * If the end of the ByteBuffer is already reached, the returned value is unknown.
         */
        char readChar();

        /**
         * Writes a char in the buffer at the current position and moves the cursor of 1 byte.
         * @return 0 if the write succeed, -1 whether the end of the buffer is reached.
         * @param c the char to write in the buffer. 
         */
        int writeChar(char c);

        /**
         * Writes data at the current position.
         * @param data the data to write.
         * @param len the length of the data to write.
         * @return 0 if everything is wrote, -1 otherwise.
         */
        int write(char* data, int len);
};

}

#endif // MEH_BYTEBUFFER_H
