#pragma once

#include <forward.hpp>

#include <Kart/VehicleReact.hpp> // Kart::VehicleReact::EAcdType, Kart::VehicleReact::ECallType
#include <Net/NetworkItemEventDataMgr.hpp> // Net::NetworkItemEventDataMgr::SlotData
#include <RaceSys/LapRankChecker.hpp> // RaceSys::LapRankChecker::KartInfo

#include <math/seadVectorFwd.h>

namespace base
{
    struct hooks
    {
        static constexpr size_t Director_count = 34;
        static constexpr size_t Director_createBeforeStructure_index = 18;
        static constexpr size_t Director_initBeforeStructure_index = 20;
        static constexpr size_t Director_calcBeforeStructure_index = 22;
        static constexpr size_t ItemObj_stateEquipHang = 55;
        static constexpr size_t ItemObj_stateInitComeBackDown = 80;
        
        // VMT hooks
        static void Item_ItemDirector_calcBeforeStructure(Item::ItemDirector *);
        static void Item_KartItem_calcBeforeStructure(Item::KartItem *);
        static void Item_KartItem_initBeforeStructure(Item::KartItem *);
        static void Kart_Director_calcBeforeStructure(Kart::Director *);

        // Detour hooks
        static bool Item_ItemDirector_itemEventRecvHandler(Item::ItemDirector *, Net::NetworkItemEventDataMgr::SlotData *);
        static void Item_ItemObjBase_setStateSelfMove(Item::ItemObjBase *, sead::Vector2f *);
        static void Item_ItemObjFlower_stateEquipHang(Item::ItemObjFlower *);
        static void Item_ItemObjKouraB_stateEquipHang(Item::ItemObjKouraB *);
        static void Item_ItemObjKouraG_stateInitSelfMoveImpl(Item::ItemObjKouraG *);
		static void Item_ItemObjKouraR_stateInitComeBackDown(Item::ItemObjKouraR *);
        static void Effect_KartEffect_calcTireEffectWheelSpin(Effect::KartEffect *);
        static void Kart_NetData_send(Kart::NetData *, s32);
        static void Kart_Unit_calcMove(Kart::Unit *, bool, bool);
        static bool Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *, Kart::VehicleReact::ECallType, int, int, Kart::VehicleReact::EAcdType, sead::Vector3f *, sead::Vector3f *);
        static bool Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived(void *, Net::NetworkReceivedInfo *);
        static void Net_NetworkEngine_sendUnreliableCore(Net::NetworkEngine *, u32, Net::NetworkBuffer *);
        static void RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *, RaceSys::LapRankChecker::KartInfo *);
        static void System_KDPadInputer_calcState(System::KDPadInputer *);

        // Naked hooks
        static NAKED void Item_GetNumInItemType_0x8();
        static NAKED void Item_GetExtraItemNum_0x8();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0x78();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0xE8();
        static NAKED void Kart_VehicleReact_calcReact_0x20();
        static NAKED void Net_NetworkEventModule_calc_0xB4();
        static NAKED void RaceSys_ModeManagerRace_calcCountDown_0x18();
    };
}