#include <base/features.hpp>

#include <base/menu.hpp>

#include <Item/ItemObj/ItemObjKouraG.hpp>
#include <Kart/InfoProxy.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
    void features::item::zero_gravity_shells(Item::ItemObjKouraG *_this)
    {
        if (g_menu->m_zero_gravity_shells_entry->IsActivated() && !_this->m_info_proxy->m_vehicle->m_is_net_recv)
            _this->m_gravity = 0;
    }
}