#include "Input/BitBang/BitBang.h"

BitBang::BitBang() {
    _vector = nullptr;
    _len = 0;
    _size = 0;
    // Do nothing
}

BitBang::BitBang(uint8_t *vector, uint16_t len, uint16_t size) {
    _vector = vector;
    _len = len;
    _size = size;
    // TODO:
}

bool BitBang::canRead() {
    // TODO:
    return false;
}

void BitBang::read(uint8_t **buf, uint16_t *len) {
    // TODO:
}

bool BitBang::hasFlowControl() {
    return true;
}

void BitBang::signalFull() {
    // TODO:
}