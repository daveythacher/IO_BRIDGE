add_library(BitBang INTERFACE)

target_sources(BitBang INTERFACE
    BitBang.cpp
)

target_link_libraries(BitBang INTERFACE
    Input
)
