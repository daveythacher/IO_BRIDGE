/* 
 * File:   main.cpp
 * Author: David Thacher
 * License: GPL 3.0
 */

#include "pico/stdio_usb.h"
#include "hardware/watchdog.h"
#include "hardware/timer.h"
#include "config.h"

int main() {
    stdio_usb_init();               // Enable picotool to call bootsel mode
    busy_wait_ms(1000);             // Make time (1 second) for picotool before system loads
    watchdog_enable(100, false);    // Make sure picotool can never be disconnected
    loop<DEFINE_INPUT, DEFINE_OUTPUT<DEFINE_INPUT>>();
}


