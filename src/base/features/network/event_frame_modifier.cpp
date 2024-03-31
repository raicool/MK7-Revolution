#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#define FRAME 0xF0

namespace base
{
    u32 features::network::event_frame_modifier(Net::NetworkEventModule::Slot *_this)
    {
        auto frame = _this->frame;

        if (g_menu->m_event_frame_modifier_entry->IsActivated())
            frame -= FRAME - g_settings.m_options["network"]["event_frame_modifier"]["value"].get<u64>();

        return frame;
    }
}