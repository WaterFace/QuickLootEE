#pragma once

#include <memory>  // shared_ptr

#include "RE/Skyrim.h"


class ManagedEntryData
{
public:
	ManagedEntryData() = delete;
	ManagedEntryData(const ManagedEntryData&) = delete;
	ManagedEntryData(ManagedEntryData&& a_rhs);
	explicit ManagedEntryData(RE::TESBoundObject* a_item, SInt32 a_count);
	explicit ManagedEntryData(RE::InventoryEntryData* a_entryData, bool a_manage);
	~ManagedEntryData();

	ManagedEntryData& operator=(const ManagedEntryData&) = delete;
	ManagedEntryData& operator=(ManagedEntryData&& a_rhs);

	RE::InventoryEntryData*	Get();
	bool					IsManaged() const;

protected:
	RE::InventoryEntryData*	_entryData;
	bool					_isManaged;
};


using ManagedEntryDataPtr = std::shared_ptr<ManagedEntryData>;


ManagedEntryDataPtr MakeEntryDataPtr(RE::TESBoundObject* a_item, SInt32 a_count);
ManagedEntryDataPtr MakeEntryDataPtr(RE::InventoryEntryData* a_entryData, bool a_manage);