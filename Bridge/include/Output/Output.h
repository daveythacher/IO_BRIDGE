/* 
 * File:   Output.h
 * Author: David Thacher
 * License: GPL 3.0
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "Input/Input.h"

class Output {
    public:
        Output(Input *input);
        virtual ~Output();

        virtual void write() = 0;
    
    protected:
        Output();

        Input *_input;

    private:
};

#endif