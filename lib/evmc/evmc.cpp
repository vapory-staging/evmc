/* EVMC: Ethereum Client-VM Connector API.
 * Copyright 2018 The EVMC Authors.
 * Licensed under the Apache License, Version 2.0. See the LICENSE file.
 */

#include <evmc/evmc.hpp>

namespace evmc
{
const evmc_host_interface host_interface::vtable{
    [](evmc_context * context, const evmc_address* address) noexcept {
        return static_cast<host_interface*>(context)->account_exists(*address);
}
, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
}
;
}
