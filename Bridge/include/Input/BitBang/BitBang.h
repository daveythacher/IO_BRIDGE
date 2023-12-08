/* 
 * File:   BitBang.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef BITBANG_H
#define BITBANG_H

#include <stdint.h>
#include "Input/Input.h"

class BitBang : public Input {
    public:
        BitBang(uint8_t *vector, uint16_t len, uint16_t size);

        bool canRead();
        void read(uint8_t **buf, uint16_t *len);
    
    protected:
        BitBang();
        
        bool hasFlowControl();
        void signalFull();

    private:

};

#endif