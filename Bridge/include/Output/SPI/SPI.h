/* 
 * File:   SPI.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef SPI_H
#define SPI_H

#include "Output/Output.h"

class SPI : public Output {
    public:
        SPI(Input *input);

        void write();
    
    protected:
        SPI();

    private:

};

#endif