#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    s32 hooks::Item_GetNumInItemType(Item::eItemType item_type)
    {
        if (auto const limit = features::item::item_limiters_num(item_type); limit != -1)
            return limit;

        return g_hooking->m_Item_GetNumInItemType_hook.call_original<s32>(item_type);
    }
}