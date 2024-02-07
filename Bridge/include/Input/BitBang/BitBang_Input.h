/* 
 * File:   BitBang_Input.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef BITBANG_INPUT_H
#define BITBANG_INPUT_H

#include "hardware/pio.h"
#include "config.h"

class BitBang_Input {
    public:
        BitBang_Input(uint8_t *vector, PIO pio, uint8_t pin_range_index, int clk_pin, int full_pin);

        bool read(uint8_t **buf);
    
    protected:
        BitBang_Input();

        bool hasFlowControl();
        void signalFull();

    private:
        uint8_t *_vector;
        uint16_t _read_idex;
        uint16_t _write_index;
        bool _isFull;
        bool _armed;
        int _dma_chan;
        int _full_pin;
        int _clk_pin;
        uint8_t _pin_range_index;
        PIO _pio;
        int _sm;

};

#endif