/* 
 * File:   SPI.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef SPI_H
#define SPI_H

#include "config.h"

template <typename T> class SPI {
    public:
        SPI(T *input);

        void write();
    
    protected:
        SPI();

    private:
        T *_input;

};

#endif