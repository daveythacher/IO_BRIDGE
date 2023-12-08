/* 
 * File:   Input.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

class Input {
    public:
        Input(uint8_t *vector, uint16_t len, uint16_t size);

        bool canRead();
        void read(uint8_t **buf, uint16_t *len);
    
    protected:
        Input();

        bool hasFlowControl();
        void signalFull();

        uint8_t *_vector;
        uint16_t _len;
        uint16_t _size;

    private:

};

#endif