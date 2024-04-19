#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    bool hooks::Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived(void *_this, Net::NetworkReceivedInfo *info)
    {
        if (features::network::protections_system_info(info))
            return false; // Drop the received data

        return g_hooking->m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook.call_original<bool>(_this, info);
    }
}