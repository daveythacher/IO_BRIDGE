/* 
 * File:   main.cpp
 * Author: David Thacher
 * License: GPL 3.0
 */

#include "pico/stdio_usb.h"
#include "pico/multicore.h"
#include "hardware/watchdog.h"
#include "hardware/timer.h"
#include "Input/BitBang/BitBang.h"
#include "Output/SPI/SPI.h"

static uint8_t vector0[32 * 1024];
static uint8_t vector1[32 * 1024];
static uint8_t vector2[32 * 1024];
static uint8_t vector3[32 * 1024];

static void __not_in_flash_func(loop)() {
    BitBang in0(vector0, sizeof(vector0), 1);
    BitBang in1(vector1, sizeof(vector1), 1);
    BitBang in2(vector2, sizeof(vector2), 1);
    BitBang in3(vector3, sizeof(vector3), 1);
    SPI out0(&in0);
    SPI out1(&in1);
    SPI out2(&in2);
    SPI out3(&in3);

    while (1) {
        out0.write();
        out1.write();
        out2.write();
        out3.write();

        watchdog_update();          // We are only interested in protecting core 0
    }
}

int main() {
    stdio_usb_init();               // Enable picotool to call bootsel mode
    busy_wait_ms(1000);             // Make time (1 second) for picotool before system loads
    watchdog_enable(100, false);    // Make sure picotool can never be disconnected
    loop();
}
