#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Net/eNetworkBufferType.hpp>
#include <Net/NetworkReceivedInfo.hpp>

namespace base
{
    bool features::network::protections_system_info(Net::NetworkReceivedInfo *info)
    {
        return g_menu->m_protections_entry->IsActivated() && g_settings.m_options["network"]["protections"]["network"] && info->size != g_pointers->m_network_buffer_sizes[std::to_underlying(Net::eNetworkBufferType::SystemInfo)];
    }
}