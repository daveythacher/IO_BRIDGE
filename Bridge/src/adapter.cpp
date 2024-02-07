#include "hardware/watchdog.h"
#include "config.h"

static uint8_t vectors[3][vector_size];

template <> void loop<SPI_Input, UART_Output<SPI_Input>>() {
    SPI_Input in(vectors[0], pio0, 2, 10, 26);
    UART_Output<SPI_Input> out0(&in, pio1, 13);
    //UART_Output<SPI_Input> out1(&in1, pio1, 16);
    //UART_Output<SPI_Input> out2(&in2, pio1, 19);

    while (1) {
        out0.write();
        //out1.write();
        //out2.write();

        watchdog_update();          // We are only interested in protecting core 0
    }
}

template <typename Input, typename Output> void loop() {
    Input in0(vectors[0], pio0, 2, 10, 26);
    Input in1(vectors[1], pio0, 2, 11, 27);
    Input in2(vectors[2], pio0, 2, 12, 28);
    Output out0(&in0, pio1, 13);
    Output out1(&in1, pio1, 16);
    Output out2(&in2, pio1, 19);

    while (1) {
        out0.write();
        out1.write();
        out2.write();

        watchdog_update();          // We are only interested in protecting core 0
    }
}

template void loop<BitBang_Input, SPI_Output<BitBang_Input>>();