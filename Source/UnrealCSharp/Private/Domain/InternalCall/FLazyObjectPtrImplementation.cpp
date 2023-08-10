﻿#include "Domain/InternalCall/FLazyObjectPtrImplementation.h"
#include "Binding/Class/FClassBuilder.h"
#include "Environment/FCSharpEnvironment.h"
#include "Macro/NamespaceMacro.h"

struct FRegisterLazyObjectPtr
{
	FRegisterLazyObjectPtr()
	{
		FClassBuilder(TEXT("LazyObjectPtr"), NAMESPACE_LIBRARY)
			.Function("Register", FLazyObjectPtrImplementation::LazyObjectPtr_RegisterImplementation)
			.Function("UnRegister", FLazyObjectPtrImplementation::LazyObjectPtr_UnRegisterImplementation)
			.Function("Get", FLazyObjectPtrImplementation::LazyObjectPtr_GetImplementation)
			.Register();
	}
};

static FRegisterLazyObjectPtr RegisterLazyObjectPtr;

void FLazyObjectPtrImplementation::LazyObjectPtr_RegisterImplementation(MonoObject* InMonoObject,
                                                                        const MonoObject* InObject)
{
	const auto FoundObject = FCSharpEnvironment::GetEnvironment().GetObject(InObject);

	const auto LazyObjectPtr = new TLazyObjectPtr<UObject>(FoundObject);

	FCSharpEnvironment::GetEnvironment().AddMultiReference<TLazyObjectPtr<UObject>>(InMonoObject, LazyObjectPtr);
}

void FLazyObjectPtrImplementation::LazyObjectPtr_UnRegisterImplementation(
	const FGarbageCollectionHandle InGarbageCollectionHandle)
{
	(void)FCSharpEnvironment::GetEnvironment().RemoveMultiReference<TLazyObjectPtr<UObject>>(InGarbageCollectionHandle);
}

void FLazyObjectPtrImplementation::LazyObjectPtr_GetImplementation(
	const FGarbageCollectionHandle InGarbageCollectionHandle, MonoObject** OutValue)
{
	const auto Multi = FCSharpEnvironment::GetEnvironment().GetMulti<TLazyObjectPtr<
		UObject>>(InGarbageCollectionHandle);

	*OutValue = FCSharpEnvironment::GetEnvironment().Bind(Multi->Get());
}
