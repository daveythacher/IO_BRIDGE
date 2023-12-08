#include "Output/Output.h"

Output::Output() {
    _input = nullptr;
}

Output::Output(Input *input) {
    _input = input;
}

Output::~Output() {
    // Do nothing
}