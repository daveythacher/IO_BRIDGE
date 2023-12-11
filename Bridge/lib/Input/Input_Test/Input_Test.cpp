#include "hardware/dma.h"
#include "Input/Input_Test/Input_Test.h"

Input_Test::Input_Test() {
    // Do nothing
}

Input_Test::Input_Test(uint8_t *vector) {
    _vector = vector;
    _read_idex = 0;
    _write_index = 0;
    _isFull = false;
    _armed = false;
    _dma_chan = dma_claim_unused_channel(true);

    // TODO: Hardware setup
}

bool Input_Test::read(uint8_t **buf) {
    bool result = false;

    // Read from FIFO
    if (_read_idex != _write_index && buf != nullptr) {
        *buf = _vector + (packet_size * _read_idex);
        _read_idex = (_read_idex + 1) % (vector_size / packet_size);
        result = true;
    }

    // Check pending write to FIFO
    if (dma_channel_get_irq0_status(_dma_chan)) {      
        _write_index = (_write_index + 1) % (vector_size / packet_size);
        _isFull = _read_idex == _write_index;
        dma_hw->intr = 1 << _dma_chan;                                          // Clear the interrupt
        _armed = false;
    }
    
    // Start write to FIFO
    if (!_isFull && !_armed) {
        // TODO: Start DMA

        _armed = true;
    }

    if (hasFlowControl()) {
        signalFull();
    }

    return result;
}

bool Input_Test::hasFlowControl() {
    return false;
}

void Input_Test::signalFull() {
    // Do nothing
}