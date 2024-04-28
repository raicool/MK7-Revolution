#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_GetExtraItemNum_0x8()
    {
        asm volatile
        (
            "push {r1, r3, r4, lr}\n"
            "mov r4, r0\n"
            "bl __item_limiters_extra_num\n"
            "cmn r0, #1\n"
            "moveq r0, #0\n" // original
            "moveq r2, r4\n"
            "mvnne r2, #0\n"
            "pop {r1, r3, r4, pc}\n"
        );
    }

    extern "C" auto __item_limiters_extra_num(Item::eItemType item)
    {
        return features::item::item_limiters_extra_num(item);
    }
}