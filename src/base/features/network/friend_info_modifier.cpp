#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <Net/NetworkFriendsManager.hpp>

namespace base
{
    void features::network::friend_info_modifier(Net::NetworkFriendsManager *_this)
    {
        if (g_menu->m_friend_info_modifier_entry->IsActivated())
        {
            auto const &friend_info_modifier = g_settings.m_options.network.friend_info_modifier;

            if (friend_info_modifier.principal_id.enabled && _this->m_my_principal_id != 0)
            {
                switch (friend_info_modifier.principal_id.mode)
                {
                case decltype(friend_info_modifier.principal_id.mode)::Value:
                    _this->m_my_principal_id = friend_info_modifier.principal_id.value;
                    break;
                case decltype(friend_info_modifier.principal_id.mode)::Random:
                    _this->m_my_principal_id = utils::random_u32();
                    break;
                }

                if (friend_info_modifier.principal_id.notify)
                    CTRPluginFramework::OSD::Notify(std::format("{} (Principal ID): {:X}", g_menu->m_friend_info_modifier_entry->Name(), _this->m_my_principal_id));
            }
        }
    }
}