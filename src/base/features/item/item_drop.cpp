#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjBase.hpp>
#include <Kart/InfoProxy.hpp>
#include <Kart/Vehicle.hpp>
#include <Object/CharacterEngine.hpp>
#include <System/RootScene.hpp>
#include <System/RootSystem.hpp>
#include <System/SceneManager.hpp>

namespace base
{
    void features::item::item_drop(Item::ItemObjBase *_this)
    {
        if (g_menu->m_item_drop_entry->IsActivated() && _this->m_info_proxy->m_vehicle->m_is_master && !_this->m_info_proxy->m_vehicle->m_is_net_recv)
        {
            auto const &item_drop = g_settings.m_options.item.item_drop;

            switch (item_drop.mode)
            {
            case decltype(item_drop.mode)::Drop:
                _this->m_is_dropped = true;
                break;
            case decltype(item_drop.mode)::Pop:
                auto const item_director = g_pointers->m_root_system->m_scene_manager->m_root_scene->m_engine_holder.get_engine<Object::CharacterEngine>(Object::EEngineType::Character)->m_collection->m_item_director;
                g_pointers->m_Item_ItemDirector_dropEquip(item_director, _this->m_owner_player_id);
                break;
            }
        }
    }
}