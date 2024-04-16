#include <base/features.hpp>

#include <base/menu.hpp>

namespace base
{
    bool features::mode::drive_during_sync_bottom_screen(bool is_bottom_screen_sync)
    {
        return g_menu->m_drive_during_sync_entry->IsActivated() ? false : is_bottom_screen_sync;
    }
}