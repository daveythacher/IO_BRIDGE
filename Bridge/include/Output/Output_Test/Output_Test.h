/* 
 * File:   Output_Test.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef OUTPUT_TEST_H
#define OUTPUT_TEST_H

#include "hardware/pio.h"
#include "config.h"

template <typename T> class Output_Test {
    public:
        Output_Test(T *input, PIO pio, uint8_t pin_range_index);

        void write();
    
    protected:
        Output_Test();

    private:
        T *_input;
        bool _armed;
        uint8_t _pin_range_index;
        int _dma_chan;
        PIO _pio;
        int _sm;

};

#endif