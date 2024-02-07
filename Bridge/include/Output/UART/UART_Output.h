/* 
 * File:   UART_Output.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef UART_OUTPUT_H
#define UART_OUTPUT_H

#include "hardware/pio.h"
#include "config.h"

template <typename T> class UART_Output {
    public:
        UART_Output(T *input, PIO pio, uint8_t pin_range_index);

        void write();
    
    protected:
        UART_Output();

    private:
        T *_input;
        bool _armed;
        uint8_t _pin_range_index;
        int _dma_chan;
        PIO _pio;
        int _sm;

};

#endif