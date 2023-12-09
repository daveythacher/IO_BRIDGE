/* 
 * File:   main.cpp
 * Author: David Thacher
 * License: GPL 3.0
 */

#include "pico/stdio_usb.h"
#include "hardware/watchdog.h"
#include "hardware/timer.h"
#include "Input/BitBang/BitBang.h"
#include "Output/SPI/SPI.h"
#include "config.h"

static uint8_t vectors[3][vector_size];

template <typename Input, typename Output> static void loop() {
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

int main() {
    stdio_usb_init();               // Enable picotool to call bootsel mode
    busy_wait_ms(1000);             // Make time (1 second) for picotool before system loads
    watchdog_enable(100, false);    // Make sure picotool can never be disconnected
    loop<DEFINE_INPUT, DEFINE_OUTPUT<DEFINE_INPUT>>();
}


