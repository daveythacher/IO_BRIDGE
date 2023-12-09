#include "hardware/dma.h"
#include "hardware/gpio.h"
#include "Input/BitBang/BitBang.h"

BitBang::BitBang() {
    // Do nothing
}

BitBang::BitBang(uint8_t *vector, PIO pio, uint8_t pin_range_index, int full_pin) {
    _vector = vector;
    _full_pin = full_pin;
    _pin_range_index = pin_range_index;
    _pio = pio;
    _read_idex = 0;
    _write_index = 0;
    _isFull = false;
    _isEmpty = true;
    _dma_chan = dma_claim_unused_channel(true);
    _sm = pio_claim_unused_sm(_pio, true);

    gpio_init(_full_pin);
    gpio_set_dir(_full_pin, true);
    gpio_put(_full_pin, false);

    // TODO:
}

bool BitBang::canRead() {
    return !_isEmpty;
}

void BitBang::read(uint8_t *buf) {
    // Read from FIFO
    if (_read_idex != _write_index) {
        buf = _vector + (packet_size * _read_idex);
        _read_idex = (_read_idex + 1) % (vector_size / packet_size);
        _isEmpty = _read_idex == _write_index;
    }

    // Check pending write to FIFO
    if (dma_channel_get_irq0_status(_dma_chan)) {      
        _write_index = (_write_index + 1) % (vector_size / packet_size);
        _isFull = _read_idex == _write_index;
        dma_hw->intr = 1 << _dma_chan;                                          // Clear the interrupt
    }
    
    // Start write to FIFO
    if (!_isFull) {
        // TODO:
    }

    if (hasFlowControl()) {
        signalFull();
    }
}

bool BitBang::hasFlowControl() {
    return true;
}

void BitBang::signalFull() {
    gpio_put(_full_pin, _isFull);
}