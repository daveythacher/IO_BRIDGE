#include "Output/Output.h"

Output::Output() {
    _input = nullptr;
}

Output::Output(Input *input) {
    _input = input;
}

void Output::write() {
    // Not implemented, should be hidden
}