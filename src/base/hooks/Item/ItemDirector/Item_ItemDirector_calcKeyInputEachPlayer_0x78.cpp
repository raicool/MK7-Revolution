#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x78()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __item_rapidfire_block\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_rapidfire_block(sead::Controller *_this)
    {
        return features::item::item_rapidfire_block(_this);
    }
}