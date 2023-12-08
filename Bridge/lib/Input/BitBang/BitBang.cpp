#include "Input/BitBang/BitBang.h"

BitBang::BitBang() : Input() {
    // Do nothing
}

BitBang::BitBang(uint8_t *vector, uint16_t len, uint16_t size) : Input(vector, len, size) {
    // TODO:
}

BitBang::~BitBang() {
    // Do nothing
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