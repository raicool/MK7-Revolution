#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <MenuEntryHelpers.hpp>

#include <Item/KartItem.hpp>
#include <Kart/Director.hpp>
#include <Kart/Unit.hpp>

#include <math/seadVector.h>

namespace base
{
    void features::item::item_rain(Item::KartItem *_this)
    {
        if (g_menu->m_item_rain_entry->IsActivated() && _this->isMaster() && !_this->isNetRecv())
        {
            auto const data = GetArg<menu_types::item_rain_data_t>(g_menu->m_item_rain_entry);
            auto const &item_rain = g_settings.m_options.item.item_rain;

            // Check that the delay has passed
            if (++data->count > item_rain.delay)
            {
                data->count = 0;

                // Lambda to spawn a randomized item
                auto const spawn_item = [&](auto const unit)
                {
                    // Choose one of the items
                    if (!item_rain.items.empty())
                    {
                        auto const player_id = item_rain.owned ? _this->m_info_proxy->m_vehicle->m_player_id : unit->m_vehicle->m_player_id;

                        // Choose a random item
                        auto const item = *std::next(item_rain.items.begin(), utils::random_u32(item_rain.items.size()));

                        // Generate a random position
                        auto const speed_offset = item_rain.speed.first ? (unit->m_vehicle->m_up * unit->m_vehicle->m_forward_speed * item_rain.speed.second) : sead::Vector3f::zero;
                        auto const width_offset = [item_rain]()
                        {
                            switch (item_rain.shape)
                            {
                            case 0:
                                return sead::Vector3f{utils::random_f32(-item_rain.width, item_rain.width), item_rain.height, utils::random_f32(-item_rain.width, item_rain.width)};
                            case 1:
                                auto const radius = std::sqrt(utils::random_f32()) * item_rain.width;
                                auto const angle = utils::random_f32(-std::numbers::pi, std::numbers::pi);
                                return sead::Vector3f{radius * std::cos(angle), item_rain.height, radius * std::sin(angle)};
                            };
                            return sead::Vector3f::zero;
                        }();
                        auto const position = *unit->m_vehicle->m_position + speed_offset + width_offset;

                        // Set velocity to (0, -1, 0) so that items won't pop up before falling down
                        auto const velocity = -sead::Vector3f::ey;

                        utils::emit_item(player_id, item, position, velocity);
                    }
                };

                auto const units = _this->m_info_proxy->m_vehicle->m_director->m_units;

                if (item_rain.multi)
                    std::for_each(units.begin(), units.end(), spawn_item);
                else
                    spawn_item(units[utils::random_u32(units.size())]);
            }
        }
    }
}