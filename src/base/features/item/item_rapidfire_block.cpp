#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    sead::BitFlag32 features::item::item_rapidfire_block(sead::Controller *_this)
    {
        auto &hold = _this->mPadHold;

        if (g_menu->m_item_rapidfire_entry->IsActivated())
        {
            switch (g_settings.m_options.item.item_rapidfire.mode)
            {
                case 0: hold.resetBit(sead::Controller::cPadIdx_X); break;
                case 1: hold.resetBit(sead::Controller::cPadIdx_L); break;
            }
        }

        return hold;
    }
}