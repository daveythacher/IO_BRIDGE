/* 
 * File:   Input_Test.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef INPUT_TEST_H
#define INPUT_TEST_H

#include "hardware/pio.h"
#include "config.h"

class Input_Test {
    public:
        Input_Test(uint8_t *vector);

        bool read(uint8_t **buf);
    
    protected:
        Input_Test();

        bool hasFlowControl();
        void signalFull();

    private:
        uint8_t *_vector;
        uint16_t _read_idex;
        uint16_t _write_index;
        bool _isFull;
        bool _armed;
        int _dma_chan;

};

#endif