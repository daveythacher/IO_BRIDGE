#include "Output/SPI/SPI.h"
#include "Input/BitBang/BitBang.h"

template <typename T> SPI<T>::SPI() {
    // Do nothing
}

template <typename T> SPI<T>::SPI(T *input, PIO pio, uint8_t pin_range_index) {
    _input = input;
    _pin_range_index = pin_range_index;
    _pio = pio;
    _sm = pio_claim_unused_sm(_pio, true);

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