#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <MenuEntryHelpers.hpp>

#include <Item/eItemType.hpp>
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
            auto const &settings = g_settings.m_options["item"]["item_rain"];

            // Check that <delay> frames have passed
            if (++data->count > settings["delay"].get<u64>())
            {
                data->count = 0;

                // Lambda to spawn a randomized item
                auto const spawn_item = [_this, data, settings](auto const unit)
                {
                    // Choose one of the items
                    if (auto const &items = settings["items"].get<std::vector<Item::eItemType>>(); !items.empty())
                    {
                        auto const player_id = settings["owned"] ? _this->m_info_proxy->m_vehicle->m_player_id : unit->m_vehicle->m_player_id;

                        // Choose a random item
                        auto const item = items[utils::random_u32(items.size())];

                        // Generate a random position
                        auto const height = static_cast<float>(settings["height"].get<double>());
                        auto const width = static_cast<float>(settings["width"].get<double>());
                        auto const type = settings["type"].get<u64>();
                        auto const speed_offset = settings["speed"]["status"] ? (unit->m_vehicle->m_up * unit->m_vehicle->m_forward_speed * settings["speed"]["value"].get<double>()) : sead::Vector3f::zero;
                        auto const width_offset = [type, width, height]()
                        {
                            switch (type)
                            {
                            case 0:
                                return sead::Vector3f{utils::random_f32(-width, width), height, utils::random_f32(-width, width)};
                            case 1:
                                auto const radius = std::sqrt(utils::random_f32()) * width;
                                auto const angle = utils::random_f32(-std::numbers::pi, std::numbers::pi);
                                return sead::Vector3f{radius * std::cos(angle), height, radius * std::sin(angle)};
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

                if (settings["multi"])
                    std::for_each(units.begin(), units.end(), spawn_item);
                else
                    spawn_item(units[utils::random_u32(units.size())]);
            }
        }
    }
}