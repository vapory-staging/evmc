# EVMC: Ethereum Client-VM Connector API.
# Copyright 2018 The EVMC Authors.
# Licensed under the Apache License, Version 2.0. See the LICENSE file.

add_library(cpp STATIC
    ${include_dir}/evmc/evmc.hpp
    evmc.cpp
)

add_library(evmc::cpp ALIAS cpp)
set_target_properties(cpp PROPERTIES
    OUTPUT_NAME evmc-cpp
    POSITION_INDEPENDENT_CODE TRUE
)
target_include_directories(cpp PUBLIC
    $<BUILD_INTERFACE:${include_dir}>$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(cpp PUBLIC evmc)

install(TARGETS cpp EXPORT evmcTargets DESTINATION ${CMAKE_INSTALL_LIBDIR})
