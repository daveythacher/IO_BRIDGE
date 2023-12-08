add_library(Input INTERFACE)

target_sources(Input INTERFACE
    Input.cpp
)

add_subdirectory(BitBang)
