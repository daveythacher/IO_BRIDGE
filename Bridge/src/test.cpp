#include "hardware/watchdog.h"
#include "config.h"

static uint8_t vectors[vector_size];

template <> void loop<BitBang_Input, Output_Test<BitBang_Input>>() {
    BitBang_Input in(vectors, pio0, 2, 10, 26);
    Output_Test<BitBang_Input> out(&in, pio1, 13);

    while (1) {
        out.write();

        watchdog_update();          // We are only interested in protecting core 0
    }
}

template <> void loop<Input_Test, SPI_Output<Input_Test>>() {
    Input_Test in(vectors);
    SPI_Output<Input_Test> out(&in, pio1, 13);

    while (1) {
        out.write();

        watchdog_update();          // We are only interested in protecting core 0
    }
}