#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>

namespace base
{
    bool features::network::protections_item(Item::ItemDirector *_this, Net::NetworkItemEventDataMgr::SlotData *data)
    {
        if (g_menu->m_protections_entry->IsActivated())
        {
            auto const &protections = g_settings.m_options.network.protections;

            auto const &kart_item = _this->m_kart_items.at(data->player_id);
            auto const &status_flags = kart_item->m_info_proxy->m_vehicle->m_status_flags;

            auto const killer_protection = [&]() { return protections.item.killer_items && status_flags.killer; };
            auto const tail_protection = [&]() { return protections.item.tail_items && status_flags.tail; };

            switch (data->event_type)
            {
                case Net::NetworkItemEventDataMgr::EEventType::SelfMove:
                case Net::NetworkItemEventDataMgr::EEventType::InitUse:
                {
                    if (killer_protection()) return true;

                    // TODO: it false flags this way, as it is possible to send InitUse while in Tail (e.g. dropped Stars).
                    // Dropped items might also send SelfMove on deflect.
                    if (tail_protection()) return true;

                    break;
                }
            }
        }

        return false;
    }
}