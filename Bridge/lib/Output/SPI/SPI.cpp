#include "Output/SPI/SPI.h"
#include "Input/BitBang/BitBang.h"

template <typename T> SPI<T>::SPI() {
    // Do nothing
}

template <typename T> SPI<T>::SPI(T *input) {
    _input = input;

    // TODO:
}

template <typename T> void SPI<T>::write() {
    uint8_t buf[packet_size];

    if (_input->canRead()) {
        _input->read(buf);

        for (uint16_t i = 0; i < packet_size; i++) {
            // TODO:
        }
    }
}

template class SPI<BitBang>;