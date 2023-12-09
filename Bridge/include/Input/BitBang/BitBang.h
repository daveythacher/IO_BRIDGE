/* 
 * File:   BitBang.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef BITBANG_H
#define BITBANG_H

#include "config.h"

class BitBang {
    public:
        BitBang(uint8_t *vector);

        bool canRead();
        void read(uint8_t *buf);
    
    protected:
        BitBang();

        bool hasFlowControl();
        void signalFull();

    private:
        uint8_t *_vector;
        uint16_t _read_idex;
        uint16_t _write_index;
        bool _isEmpty;
        bool _isFull;
        int _dma_chan;

        const int full_pin = 22;

};

#endif