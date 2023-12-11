#include "hardware/dma.h"
#include "Output/Output_Test/Output_Test.h"
#include "Input/Input_Test/Input_Test.h"

template <typename T> Output_Test<T>::Output_Test() {
    // Do nothing
}

template <typename T> Output_Test<T>::Output_Test(T *input, PIO pio, uint8_t pin_range_index) {
    _input = input;
    _pin_range_index = pin_range_index;
    _pio = pio;
    _armed = false;
    _dma_chan = dma_claim_unused_channel(true);
    _sm = pio_claim_unused_sm(_pio, true);

    // TODO:
}

template <typename T> void Output_Test<T>::write() {
    uint8_t *buf;

    if (_armed) {
        if (dma_channel_get_irq0_status(_dma_chan)) {      
            dma_hw->intr = 1 << _dma_chan;                                      // Clear the interrupt
            _armed = false;
        }
        else {
            _input->read(nullptr);
            return;
        }
    }

    if (!_armed) {
        if (_input->read(&buf)) {
            // TODO:

            _armed = true;
        }
    }
}

template class Output_Test<BitBang>;