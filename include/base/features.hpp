#pragma once

#include <forward.hpp>

#include <Net/NetworkEventModule.hpp> // Net::NetworkEventModule::Slot
#include <Net/NetworkItemEventDataMgr.hpp> // Net::NetworkItemEventDataMgr::SlotData
#include <RaceSys/ModeManagerBase.hpp> // RaceSys::ModeManagerBase::ERaceState

#include <controller/seadController.h> // sead::Controller
#include <prim/seadBitFlag.h> // sead::BitFlag32

namespace base
{
	struct features
	{
		struct item
		{
			static bool blue_shell_battle_crash_fix(Item::ItemObjKouraR *);
			static void item_drop(Item::ItemObjBase *);
			static bool item_hang(Item::ItemObjBase *);
			static s32 item_limiters_extra_num(Item::eItemType);
			static s32 item_limiters_num(Item::eItemType);
			static void item_rain(Item::KartItem *);
			static sead::BitFlag32 item_rapidfire_block(sead::Controller *);
			static bool item_rapidfire_execute();
			static void item_wheel_calc(Item::KartItem *);
			static void item_wheel_init(Item::KartItem *);
			static void zero_gravity_shells(Item::ItemObjKouraG *);
		};

		struct kart
		{
			static void instant_miniturbo(Kart::Unit *);
			static void instant_respawn(Kart::Unit *);
			static bool intangibility(Kart::VehicleReact *);
			static bool invincibility(Kart::VehicleReact *);
			static void kart_statuses(Kart::Unit *);

			static constexpr s32 c_status_threshold = 1 << 2;
			static constexpr s32 c_respawn_threshold = 1;
		};

		struct mode
		{
			static void drive_during_sync_after(RaceSys::ModeManagerBase *, RaceSys::ModeManagerBase::ERaceState);
			static RaceSys::ModeManagerBase::ERaceState drive_during_sync_before(RaceSys::ModeManagerBase *);
			static bool drive_during_sync_bottom_screen(bool);
			static bool drive_during_sync_input(System::KDPadInputer *);
		};

		struct network
		{
			static u32 event_frame_modifier(Net::NetworkEventModule::Slot *);
			static void friend_info_modifier(Net::NetworkFriendsManager *);
			static void high_data_rate(u32 *);
			static void invisibility(Kart::NetData *);
			static void kart_warp(Kart::NetData *);
			static void no_disconnect(RaceSys::LapRankChecker *);
			static bool protections_item(Item::ItemDirector *, Net::NetworkItemEventDataMgr::SlotData *);
			static bool protections_system_info(Net::NetworkReceivedInfo *);
		};
	};
}