/* 
 * File:   SPI.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef SPI_H
#define SPI_H

#include "hardware/pio.h"
#include "config.h"

template <typename T> class SPI {
    public:
        SPI(T *input, PIO pio, uint8_t pin_range_index);

        void write();
    
    protected:
        SPI();

    private:
        T *_input;
        bool _armed;
        uint8_t _pin_range_index;
        int _dma_chan;
        PIO _pio;
        int _sm;

};

#endif