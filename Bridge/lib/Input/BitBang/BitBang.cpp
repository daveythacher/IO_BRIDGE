#include "hardware/dma.h"
#include "hardware/gpio.h"
#include "Input/BitBang/BitBang.h"

BitBang::BitBang() {
    // Do nothing
}

BitBang::BitBang(uint8_t *vector) {
    _vector = vector;
    _read_idex = 0;
    _write_index = 0;
    _isFull = false;
    _isEmpty = true;
    _dma_chan = dma_claim_unused_channel(true);

    gpio_init(full_pin);
    gpio_set_dir(full_pin, true);
    gpio_put(full_pin, false);
    
    // TODO:
}

bool BitBang::canRead() {
    return !_isEmpty;
}

void BitBang::read(uint8_t *buf) {

    if (_read_idex != _write_index) {
        // TODO:
    }

    if (dma_channel_get_irq0_status(_dma_chan)) {      
        // TODO:
        dma_hw->intr = 1 << _dma_chan;                                          // Clear the interrupt
    }

    if (hasFlowControl()) {
        signalFull();
    }
}

bool BitBang::hasFlowControl() {
    return true;
}

void BitBang::signalFull() {
    gpio_put(full_pin, _isFull);
}