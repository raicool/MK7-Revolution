#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Net_NetworkFriendsManager_updateFriendInfo(Net::NetworkFriendsManager *_this)
    {
        g_hooking->m_Net_NetworkFriendsManager_updateFriendInfo_hook.call_original<void>(_this);

        features::network::friend_info_modifier(_this);
    }
}