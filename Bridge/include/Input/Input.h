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
        virtual ~Input();

        virtual bool canRead() = 0;
        virtual void read(uint8_t **buf, uint16_t *len) = 0;
    
    protected:
        Input();
        
        virtual bool hasFlowControl() = 0;
        virtual void signalFull() = 0;

        uint8_t *_vector;
        uint16_t _len;
        uint16_t _size;

    private:

};

#endif