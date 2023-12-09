add_executable(bridge 
    ./main.cpp
)

target_include_directories(bridge PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../include
    ../include
)

target_compile_options(bridge PRIVATE 
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    -fno-exceptions 
    -fno-check-new 
    $<$<COMPILE_LANGUAGE:CXX>:-fno-enforce-eh-specs>
    -g 
    -ffunction-sections 
    -fdata-sections 
    -O3
    -funroll-loops 
    -Werror 
    -Wall
)

target_compile_definitions(bridge PRIVATE 
    PICO_HEAP_SIZE=2048
    PICO_STACK_SIZE=4096
    PICO_CORE1_STACK_SIZE=4096
    PICO_XOSC_STARTUP_DELAY_MULTIPLIER=64
)

pico_set_binary_type(bridge copy_to_ram)

# enable usb output, disable uart output
pico_enable_stdio_usb(bridge 1)
pico_enable_stdio_uart(bridge 0)
    
target_link_libraries(bridge 
    pico_stdio_usb
    pico_runtime
    ${DEFINE_OUTPUT}
    ${DEFINE_INPUT}
)

target_link_options(bridge 
    PRIVATE "LINKER:--print-memory-usage"
)

# create map/bin/hex file etc.
pico_add_extra_outputs(bridge)
pico_add_dis_output2(bridge)
