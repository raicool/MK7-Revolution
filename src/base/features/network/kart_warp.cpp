#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/NetData.hpp>

#define WARP 0x20000

namespace base
{
    void features::network::kart_warp(Kart::NetData *_this)
    {
        if (g_menu->m_kart_warp_entry->IsActivated())
            _this->kart_data ^= WARP;
    }
}