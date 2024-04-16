#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::RaceSys_ModeManagerRace_calcCountDown_0x18()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __drive_during_sync_bottom_screen\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __drive_during_sync_bottom_screen(bool is_bottom_screen_sync)
    {
        return features::mode::drive_during_sync_bottom_screen(is_bottom_screen_sync);
    }
}