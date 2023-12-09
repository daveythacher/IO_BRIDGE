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
        uint8_t _pin_range_index;
        PIO _pio;

};

#endif