/* 
 * File:   BitBang.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef BITBANG_H
#define BITBANG_H

#include <stdint.h>

class BitBang {
    public:
        BitBang(uint8_t *vector, uint16_t len, uint16_t size);

        bool canRead();
        void read(uint8_t **buf, uint16_t *len);
    
    protected:
        BitBang();

        bool hasFlowControl();
        void signalFull();

    private:
        uint8_t *_vector;
        uint16_t _len;
        uint16_t _size;

};

#endif