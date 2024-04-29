#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    bool hooks::Item_ItemDirector_itemEventRecvHandler(Item::ItemDirector *_this, Net::NetworkItemEventDataMgr::SlotData *data)
    {
        if (features::network::protections_item(_this, data))
            return true;

        return g_hooking->m_Item_ItemDirector_itemEventRecvHandler_hook.call_original<bool>(_this, data);
    }
}