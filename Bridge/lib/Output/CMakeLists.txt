add_library(Output INTERFACE)

target_sources(Output INTERFACE
    Output.cpp
)

add_subdirectory(SPI)
