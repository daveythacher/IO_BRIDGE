#include "Input/Input.h"

Input::Input() {
    _vector = nullptr;
    _len = 0;
    _size = 0;
}

Input::Input(uint8_t *vector, uint16_t len, uint16_t size) {
    _vector = vector;
    _len = len;
    _size = size;
}

Input::~Input() {
    // Do nothing
}