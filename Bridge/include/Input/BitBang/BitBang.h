/* 
 * File:   BitBang.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef BITBANG_H
#define BITBANG_H

#include "hardware/pio.h"
#include "config.h"

class BitBang {
    public:
        BitBang(uint8_t *vector, PIO pio, uint8_t pin_range_index, int full_pin);

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
        bool _armed;
        int _dma_chan;
        int _full_pin;
        uint8_t _pin_range_index;
        PIO _pio;
        int _sm;

};

#endif