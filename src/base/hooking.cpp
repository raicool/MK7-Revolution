#include <base/hooking.hpp>

#include <base/pointers.hpp>

namespace base
{
    hooking::hooking()
	:
		m_Item_ItemDirector_hook("Item::ItemDirector", g_pointers->m_Item_ItemDirector, hooks::Director_count),
		m_Item_KartItem_hook("Item::KartItem", g_pointers->m_Item_KartItem, hooks::Director_count),
		m_Kart_Director_hook("Kart::Director", g_pointers->m_Kart_Director, hooks::Director_count),

		m_Item_ItemDirector_itemEventRecvHandler_hook("Item::ItemDirector::_itemEventRecvHandler", g_pointers->m_Item_ItemDirector_itemEventRecvHandler, reinterpret_cast<void *>(&hooks::Item_ItemDirector_itemEventRecvHandler)),
		m_Item_ItemObjBase_setStateSelfMove_hook("Item::ItemObjBase::setState_SelfMove", g_pointers->m_Item_ItemObjBase_setStateSelfMove, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_setStateSelfMove)),
		m_Item_ItemObjFlower_stateEquipHang_hook("Item::ItemObjFlower::stateEquip_Hang", g_pointers->m_Item_ItemObjFlower_stateEquipHang, reinterpret_cast<void *>(&hooks::Item_ItemObjFlower_stateEquipHang)),
		m_Item_ItemObjKouraB_stateEquipHang_hook("Item::ItemObjKouraB::stateEquip_Hang", g_pointers->m_Item_ItemObjKouraB_stateEquipHang, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraB_stateEquipHang)),
		m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook("Item::ItemObjKouraG::stateInitSelfMoveImpl", g_pointers->m_Item_ItemObjKouraG_stateInitSelfMoveImpl, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraG_stateInitSelfMoveImpl)),
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook("Item::ItemObjKouraR::stateInitComeBackDown", g_pointers->m_Item_ItemObjKouraR_stateInitComeBackDown, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraR_stateInitComeBackDown)),
		m_Effect_KartEffect_calcTireEffectWheelSpin_hook("Effect::KartEffect::_calcTireEffect_WheelSpin", g_pointers->m_Effect_KartEffect_calcTireEffectWheelSpin, reinterpret_cast<void *>(&hooks::Effect_KartEffect_calcTireEffectWheelSpin)),
		m_Kart_NetData_send_hook("Kart::NetData::send", g_pointers->m_Kart_NetData_send, reinterpret_cast<void *>(&hooks::Kart_NetData_send)),
		m_Kart_Unit_calcMove_hook("Kart::Unit::calcMove", g_pointers->m_Kart_Unit_calcMove, reinterpret_cast<void *>(&hooks::Kart_Unit_calcMove)),
		m_Kart_VehicleReact_reactAccidentCommon_hook("Kart::VehicleReact::reactAccidentCommon", g_pointers->m_Kart_VehicleReact_reactAccidentCommon, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_reactAccidentCommon)),
		m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook("Net::NetworkDataManager<Net::NetworkSystemSendFormat>::onReceived", g_pointers->m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived, reinterpret_cast<void *>(&hooks::Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived)),
		m_Net_NetworkEngine_sendUnreliableCore_hook("Net::NetworkEngine::sendUnreliableCore", g_pointers->m_Net_NetworkEngine_sendUnreliableCore, reinterpret_cast<void *>(&hooks::Net_NetworkEngine_sendUnreliableCore)),
		m_Net_NetworkFriendsManager_updateFriendInfo_hook("Net::NetworkFriendsManager::updateFriendInfo", g_pointers->m_Net_NetworkFriendsManager_updateFriendInfo, reinterpret_cast<void *>(&hooks::Net_NetworkFriendsManager_updateFriendInfo)),
		m_RaceSys_LapRankChecker_calcLapPosition_hook("RaceSys::LapRankChecker::calcLapPosition_", g_pointers->m_RaceSys_LapRankChecker_calcLapPosition, reinterpret_cast<void *>(&hooks::RaceSys_LapRankChecker_calcLapPosition)),
		m_System_KDPadInputer_calcInput_hook("System::KDPadInputer::calcInput", g_pointers->m_System_KDPadInputer_calcInput, reinterpret_cast<void *>(&hooks::System_KDPadInputer_calcState)),

		m_Item_GetExtraItemNum_0x8_hook("Item::GetExtraItemNum+0x8", g_pointers->m_Item_GetExtraItemNum_0x8, reinterpret_cast<void *>(&hooks::Item_GetExtraItemNum_0x8)),
		m_Item_GetNumInItemType_0x8_hook("Item::GetNum_InItemType+0x8", g_pointers->m_Item_GetNumInItemType_0x8, reinterpret_cast<void *>(&hooks::Item_GetNumInItemType_0x8)),
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook("Item::ItemDirector::_calcKeyInput_EachPlayer+0x78", g_pointers->m_Item_ItemDirector_calcKeyInputEachPlayer_0x78, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x78)),
		m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook("Item::ItemDirector::_calcKeyInput_EachPlayer+0xE8", g_pointers->m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcKeyInputEachPlayer_0xE8)),
		m_Kart_VehicleReact_calcReact_0x20_hook("Kart::VehicleReact::calcReact+0x20", g_pointers->m_Kart_VehicleReact_calcReact_0x20, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_calcReact_0x20)),
		m_Net_NetworkEventModule_calc_0xB4_hook("Net::NetworkEventModule::calc+0xB4", g_pointers->m_Net_NetworkEventModule_calc_0xB4, reinterpret_cast<void *>(&hooks::Net_NetworkEventModule_calc_0xB4)),
		m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook("RaceSys::ModeManagerRace::calcCountDown+0x18", g_pointers->m_RaceSys_ModeManagerRace_calcCountDown_0x18, reinterpret_cast<void *>(&hooks::RaceSys_ModeManagerRace_calcCountDown_0x18), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_BEFORE_CB)
	{
		m_Item_ItemDirector_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcBeforeStructure));
		m_Item_KartItem_hook.hook(hooks::Director_initBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_KartItem_initBeforeStructure));
		m_Item_KartItem_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_KartItem_calcBeforeStructure));
		m_Kart_Director_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Kart_Director_calcBeforeStructure));

		g_hooking = this;
	}

	hooking::~hooking()
	{
		g_hooking = nullptr;

		if (m_enabled)
			disable();
	}

    void hooking::enable()
	{
		m_Item_ItemDirector_hook.enable();
		m_Item_KartItem_hook.enable();
		m_Kart_Director_hook.enable();

		m_Item_ItemDirector_itemEventRecvHandler_hook.enable();
		m_Item_ItemObjBase_setStateSelfMove_hook.enable();
		m_Item_ItemObjFlower_stateEquipHang_hook.enable();
		m_Item_ItemObjKouraB_stateEquipHang_hook.enable();
		m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook.enable();
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook.enable();
		m_Effect_KartEffect_calcTireEffectWheelSpin_hook.enable();
		m_Kart_NetData_send_hook.enable();
		m_Kart_Unit_calcMove_hook.enable();
		m_Kart_VehicleReact_reactAccidentCommon_hook.enable();
		m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook.enable();
		m_Net_NetworkEngine_sendUnreliableCore_hook.enable();
		m_Net_NetworkFriendsManager_updateFriendInfo_hook.enable();
		m_RaceSys_LapRankChecker_calcLapPosition_hook.enable();
		m_System_KDPadInputer_calcInput_hook.enable();

		m_Item_GetExtraItemNum_0x8_hook.enable();
		m_Item_GetNumInItemType_0x8_hook.enable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook.enable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook.enable();
		m_Kart_VehicleReact_calcReact_0x20_hook.enable();
		m_Net_NetworkEventModule_calc_0xB4_hook.enable();
		m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook.enable();

		m_enabled = true;
	}

	void hooking::disable()
	{
		m_enabled = false;

		m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook.disable();
		m_Net_NetworkEventModule_calc_0xB4_hook.disable();
		m_Kart_VehicleReact_calcReact_0x20_hook.disable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook.disable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook.disable();
		m_Item_GetNumInItemType_0x8_hook.disable();
		m_Item_GetExtraItemNum_0x8_hook.disable();

		m_System_KDPadInputer_calcInput_hook.disable();
		m_RaceSys_LapRankChecker_calcLapPosition_hook.disable();
		m_Net_NetworkFriendsManager_updateFriendInfo_hook.disable();
		m_Net_NetworkEngine_sendUnreliableCore_hook.disable();
		m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook.disable();
		m_Kart_VehicleReact_reactAccidentCommon_hook.disable();
		m_Kart_Unit_calcMove_hook.disable();
		m_Kart_NetData_send_hook.disable();
		m_Effect_KartEffect_calcTireEffectWheelSpin_hook.disable();
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook.disable();
		m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook.disable();
		m_Item_ItemObjKouraB_stateEquipHang_hook.disable();
		m_Item_ItemObjFlower_stateEquipHang_hook.disable();
		m_Item_ItemObjBase_setStateSelfMove_hook.disable();
		m_Item_ItemDirector_itemEventRecvHandler_hook.disable();

		m_Kart_Director_hook.disable();
		m_Item_KartItem_hook.disable();
		m_Item_ItemDirector_hook.disable();
	}
}