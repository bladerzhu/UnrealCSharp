﻿#pragma once

#include "GarbageCollection/TGarbageCollectionHandleMapping.h"
#include "mono/metadata/object-forward.h"

class FMultiRegistry
{
public:
	template <typename T>
	struct TMultiAddress
	{
		typedef T Type;

		void* Address;

		Type Value;
	};

	typedef TMultiAddress<TSubclassOf<UObject>> FSubclassOfAddress;

	typedef TMultiAddress<TWeakObjectPtr<UObject>> FWeakObjectPtrAddress;

public:
	FMultiRegistry();

	~FMultiRegistry();

public:
	void Initialize();

	void Deinitialize();

public:
	template <typename T>
	auto GetMulti(const MonoObject* InMonoObject);

	template <typename T>
	auto GetObject(const void* InAddress) const;

public:
	bool AddReference(MonoObject* InMonoObject, const FSubclassOfAddress::Type& InValue);

	bool AddReference(void* InAddress, MonoObject* InMonoObject, const FSubclassOfAddress::Type& InValue);

	bool AddReference(MonoObject* InMonoObject, const FWeakObjectPtrAddress::Type& InValue);

	bool AddReference(void* InAddress, MonoObject* InMonoObject, const FWeakObjectPtrAddress::Type& InValue);

	template <typename T>
	auto RemoveReference(const MonoObject* InMonoObject);

	template <typename T>
	auto RemoveReference(const void* InAddress);

private:
	TGarbageCollectionHandleMapping<FSubclassOfAddress> GarbageCollectionHandle2SubclassOfAddress;

	TMap<void*, FGarbageCollectionHandle> SubclassOfAddress2GarbageCollectionHandle;

	TGarbageCollectionHandleMapping<FWeakObjectPtrAddress> GarbageCollectionHandle2WeakObjectPtrAddress;

	TMap<void*, FGarbageCollectionHandle> WeakObjectPtrAddress2GarbageCollectionHandle;
};

#include "FMultiRegistry.inl"