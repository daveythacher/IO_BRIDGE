#include "Output/SPI/SPI.h"
#include "Input/BitBang/BitBang.h"

template <typename T> SPI<T>::SPI() {
    _input = nullptr;
    // Do nothing
}

template <typename T> SPI<T>::SPI(T *input) {
    _input = input;
    // TODO:
}

template <typename T> void SPI<T>::write() {
    // TODO:
}

template class SPI<BitBang>;