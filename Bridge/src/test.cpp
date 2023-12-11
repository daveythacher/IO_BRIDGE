#include "hardware/watchdog.h"
#include "config.h"

static uint8_t vectors[vector_size];

template <> void loop<BitBang, Output_Test<BitBang>>() {
    BitBang in(vectors, pio0, 2, 10, 26);
    Output_Test<BitBang> out(&in, pio1, 13);

    while (1) {
        out.write();

        watchdog_update();          // We are only interested in protecting core 0
    }
}

template <> void loop<Input_Test, SPI<Input_Test>>() {
    Input_Test in(vectors);
    SPI<Input_Test> out(&in, pio1, 13);

    while (1) {
        out.write();

        watchdog_update();          // We are only interested in protecting core 0
    }
}