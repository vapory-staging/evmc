/* EVMC: Ethereum Client-VM Connector API.
 * Copyright 2018 The EVMC Authors.
 * Licensed under the Apache License, Version 2.0. See the LICENSE file.
 */

/// @file
/// EVMC C++ API - wrappers and bindings for C++.

#include <evmc/evmc.h>
#include <initializer_list>
#include <utility>

namespace evmc
{
class host_interface : public evmc_context
{
public:
    host_interface() noexcept : evmc_context{&vtable} {}

    virtual bool account_exists(const evmc_address& address) noexcept = 0;

private:
    static const evmc_host_interface vtable;
};

class vm
{
public:
    explicit vm(evmc_instance* instance) noexcept : m_instance{instance} {}
    ~vm() noexcept { m_instance->destroy(m_instance); }

    vm(evmc_instance* instance, std::initializer_list<std::pair<const char*, const char*>> options)
      : m_instance{instance}
    {
        for (auto option : options)
            set_option(option.first, option.second);
    }

    evmc_set_option_result set_option(const char name[], const char value[]) noexcept
    {
        return m_instance->set_option(m_instance, name, value);
    }

    evmc_result execute(host_interface& host,
                        evmc_revision rev,
                        const evmc_message& msg,
                        const uint8_t* code,
                        size_t code_size) noexcept
    {
        return m_instance->execute(m_instance, &host, rev, &msg, code, code_size);
    }

private:
    evmc_instance* const m_instance = nullptr;
};
}  // namespace evmc
