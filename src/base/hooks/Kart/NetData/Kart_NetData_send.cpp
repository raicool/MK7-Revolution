#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_NetData_send(Kart::NetData *_this, s32 sender_id)
    {
        features::network::invisibility(_this);
        features::network::kart_warp(_this);
        
        g_hooking->m_Kart_NetData_send_hook.call_original<void>(_this, sender_id);
    }
}