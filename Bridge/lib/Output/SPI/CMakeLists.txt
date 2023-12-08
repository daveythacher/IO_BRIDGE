add_library(SPI INTERFACE)

target_sources(SPI INTERFACE
    SPI.cpp
)

target_link_libraries(SPI INTERFACE
    Output
)