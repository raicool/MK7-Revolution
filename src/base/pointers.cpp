#include <base/pointers.hpp>

#include <base/memory/all.hpp>
#include <CTRPluginFramework.hpp>

#include <base/hooks.hpp>

#define TEXT_BASE 0x100000

namespace base
{
	pointers::pointers()
	{
		memory::batch batch;

		batch.add("sead::Random", "00 00 54 E3 04 00 85 E5 04 00 A0 11 00 40 A0 03", [this](memory::handle handle)
		{
			m_random = *handle.add(0x20).as<decltype(m_random) *>();
		});

		batch.add("System::RootSystem", "00 20 95 E5 70 40 BD E8", [this](memory::handle handle)
		{
			m_root_system = *handle.add(0x20).as<decltype(m_root_system) *>();
		});

		batch.add("Item::ItemDirector", "20 41 80 E5 24 41 80 E5 28 41 80 E5 10 80 BD E8", [this](memory::handle handle)
		{
			m_Item_ItemDirector = handle.add(0x10).as<decltype(m_Item_ItemDirector)>();
		});

		batch.add("Item::ItemObjFlower", "00 30 92 E5 F8 31 80 E5 04 30 92 E5 FC 31 80 E5", [this](memory::handle handle)
		{
			auto Item_ItemObjFlower_vtbl = *handle.add(0x30).as<void ***>();
			auto Item_ItemObjFlower_stateEquipHang_hnd = memory::handle(Item_ItemObjFlower_vtbl[hooks::ItemObj_stateEquipHang]);

			m_Item_ItemObjFlower_stateEquipHang = Item_ItemObjFlower_stateEquipHang_hnd.as<decltype(m_Item_ItemObjFlower_stateEquipHang)>();
		});

		batch.add("Item::ItemObjKouraB", "C4 12 80 E4 00 10 A0 E3 00 30 80 E5 01 20 A0 E3", [this](memory::handle handle)
		{
			auto Item_ItemObjKouraB_vtbl = *handle.add(0x30).as<void ***>();
			auto Item_ItemObjKouraB_stateEquipHang_hnd = memory::handle(Item_ItemObjKouraB_vtbl[hooks::ItemObj_stateEquipHang]);

			m_Item_ItemObjBase_stateEquipHang = reinterpret_cast<decltype(m_Item_ItemObjBase_stateEquipHang)>(Item_ItemObjKouraB_stateEquipHang_hnd.add(0x8).jmp().as<void *>());
			m_Item_ItemObjBase_setStateSelfMove = Item_ItemObjKouraB_stateEquipHang_hnd.add(0x18).jmp().as<decltype(m_Item_ItemObjBase_setStateSelfMove)>();
			m_Item_ItemObjKouraB_stateEquipHang = Item_ItemObjKouraB_stateEquipHang_hnd.as<decltype(m_Item_ItemObjKouraB_stateEquipHang)>();
			m_Item_ItemObjKouraR_stateInitComeBackDown = Item_ItemObjKouraB_vtbl[hooks::ItemObj_stateInitComeBackDown];
		});

		batch.add("Item::ItemObjBananaDirector", "21 01 84 E8 48 D0 8D E2 F0 87 BD E8 01 00 A0 E3", [this](memory::handle handle)
		{
			auto Item_ItemObjBananaDirector_vtbl = *handle.add(0x3C).as<void ***>();
			auto Item_ItemObjBananaDirector_createBeforeStructure_hnd = memory::handle(Item_ItemObjBananaDirector_vtbl[hooks::Director_createBeforeStructure_index]);

			m_Item_GetExtraItemNum = Item_ItemObjBananaDirector_createBeforeStructure_hnd.add(0x18).jmp().as<decltype(m_Item_GetExtraItemNum)>();
			m_Item_GetNumInItemType = Item_ItemObjBananaDirector_createBeforeStructure_hnd.add(0xC).jmp().as<decltype(m_Item_GetNumInItemType)>();
		});

		batch.add("Item::KartItem", "02 01 8C E7 34 00 84 E5 04 00 A0 E1 B0 80 BD E8", [this](memory::handle handle)
		{
			m_Item_KartItem = handle.add(0x10).as<decltype(m_Item_KartItem)>();
		});

		batch.add("Kart::Director", "04 00 A0 E1 24 50 84 E5 70 80 BD E8", [this](memory::handle handle)
		{
			m_Kart_Director = handle.add(0xC).as<decltype(m_Kart_Director)>();

			auto vtbl = *static_cast<decltype(m_Kart_Director) **>(m_Kart_Director);
			auto Kart_Director_calcBeforeStructure = vtbl[hooks::Director_calcBeforeStructure_index];
			auto hnd = memory::handle(Kart_Director_calcBeforeStructure);

			m_Kart_Unit_calcMove = hnd.add(0x224).jmp().as<decltype(m_Kart_Unit_calcMove)>();
			m_Kart_VehicleReact_calcReact_0x20 = hnd.add(0x1E8).jmp().add(0x18).jmp().add(0x20).as<decltype(m_Kart_VehicleReact_calcReact_0x20)>();
		});

		batch.add("Item::ItemObjDirectorBase::_emitItemImpl", "F0 43 2D E9 1C D0 4D E2 01 40 A0 E1 02 60 A0 E1", [this](memory::handle handle)
		{
			m_Item_ItemObjDirectorBase_emitItemImpl = reinterpret_cast<decltype(m_Item_ItemObjDirectorBase_emitItemImpl)>(handle.as<void *>());
		});

		batch.add("Item::KartItem::setItemForce", "70 40 2D E9 00 40 A0 E1 34 00 90 E5 01 50 A0 E1", [this](memory::handle handle)
		{
			m_Item_KartItem_setItemForce = reinterpret_cast<decltype(m_Item_KartItem_setItemForce)>(handle.as<void *>());
		});

		batch.add("Effect::KartEffect::_calcTireEffect_WheelSpin", "70 40 2D E9 00 40 A0 E1 02 8B 2D ED 60 D0 4D E2", [this](memory::handle handle)
		{
			m_Effect_KartEffect_calcTireEffectWheelSpin = handle.as<decltype(m_Effect_KartEffect_calcTireEffectWheelSpin)>();
		});

		batch.add("Item::ItemObjKouraG::stateInitSelfMoveImpl", "F0 41 2D E9 00 40 A0 E1 F4 73 9F E5 02 8B 2D ED", [this](memory::handle handle)
		{
			m_Item_ItemObjKouraG_stateInitSelfMoveImpl = handle.as<decltype(m_Item_ItemObjKouraG_stateInitSelfMoveImpl)>();
		});

		batch.add("Kart::NetData::send", "30 40 2D E9 24 D0 4D E2 00 40 A0 E1 01 50 A0 E1 10 00 8D E2", [this](memory::handle handle)
		{
			m_Kart_NetData_send = handle.as<decltype(m_Kart_NetData_send)>();
		});

		batch.add("Kart::VehicleReact::reactAccidentCommon", "FF 4F 2D E9 0C D0 4D E2 00 40 A0 E1 01 5A 84 E2", [this](memory::handle handle)
		{
			m_Kart_VehicleReact_reactAccidentCommon = handle.as<decltype(m_Kart_VehicleReact_reactAccidentCommon)>();
		});

		batch.add("Net::NetworkDataManager<Net::NetworkSystemSendFormat>::onReceived", "70 40 2D E9 00 40 A0 E1 EC 00 D0 E5 01 60 A0 E1", [this](memory::handle handle)
		{
			m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived = handle.as<decltype(m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived)>();
		});

		batch.add("Net::NetworkEngine::sendUnreliableCore", "F0 4F 2D E9 00 40 A0 E1 01 0B 80 E2 01 50 A0 E1", [this](memory::handle handle)
		{
			m_Net_NetworkEngine_sendUnreliableCore = handle.as<decltype(m_Net_NetworkEngine_sendUnreliableCore)>();
		});

		batch.add("Net::NetworkEventModule::calc", "F0 4F 2D E9 00 50 A0 E1 98 80 80 E2 0C D0 4D E2", [this](memory::handle handle)
		{
			m_Net_NetworkEventModule_calc_0xB4 = handle.add(0xB4).as<decltype(m_Net_NetworkEventModule_calc_0xB4)>();
		});

		batch.add("RaceSys::LapRankChecker::calcLapPosition_", "F0 4F 2D E9 01 40 A0 E1 00 50 A0 E1 02 8B 2D ED", [this](memory::handle handle)
		{
			m_RaceSys_LapRankChecker_calcLapPosition = handle.as<decltype(m_RaceSys_LapRankChecker_calcLapPosition)>();
		});

		batch.add("RaceSys::ModeManagerRace::calcCountDown", "70 40 2D E9 00 40 A0 E1 B0 50 9F E5 00 60 A0 E3", [this](memory::handle handle)
		{
			m_RaceSys_ModeManagerRace_calcCountDown_0x18 = handle.add(0x18).as<decltype(m_RaceSys_ModeManagerRace_calcCountDown_0x18)>();
		});

		batch.add("System::KDPadInputer::calcInput", "04 10 90 E5 01 00 51 E3 02 00 00 1A 00 10 90 E5", [this](memory::handle handle)
		{
			m_System_KDPadInputer_calcInput = handle.as<decltype(m_System_KDPadInputer_calcInput)>();
		});
		
		batch.add("NetworkBufferSizes", "01 80 88 E2 08 00 50 E1 ? ? ? CA F0 9F BD E8", [this](memory::handle handle)
		{
			m_network_buffer_sizes = *handle.add(0x10).as<decltype(m_network_buffer_sizes) *>();
		});

		batch.add("Data", "F0 4F 2D E9 01 6A 80 E2 00 40 A0 E1 04 8B 2D ED", [this](memory::handle handle)
		{
			auto hnd = memory::handle(*handle.add(0x410).as<void **>());
			m_miniturbo_blue_threshold = hnd.add(0x12C).as<decltype(m_miniturbo_blue_threshold)>();
			m_miniturbo_red_threshold = hnd.add(0x130).as<decltype(m_miniturbo_red_threshold)>();
			m_invincibility_frames_invisible_amount = hnd.add(0x230).as<decltype(m_invincibility_frames_invisible_amount)>();
			m_invincibility_frames_visible_amount = hnd.add(0x234).as<decltype(m_invincibility_frames_visible_amount)>();
			m_press_frames_kart_size = hnd.add(0x2CC).as<decltype(m_press_frames_kart_size)>();
		});
		
		batch.run(memory::range(memory::handle(TEXT_BASE), CTRPluginFramework::Process::GetTextSize()));

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
