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

bool Input::canRead() {
    // Not implemented, should be hidden
    return false;
}

void Input::read(uint8_t **buf, uint16_t *len) {
    // Not implemented, should be hidden
}

bool Input::hasFlowControl() {
    // Not implemented, should be hidden
    return false;
}

void Input::signalFull() {
    // Not implemented, should be hidden
}