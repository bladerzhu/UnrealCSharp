﻿#include "Binding/Class/FClassBuilder.h"
#include "Environment/FCSharpEnvironment.h"
#include "Macro/NamespaceMacro.h"
#include "Async/Async.h"

struct FRegisterScriptInterface
{
	static void RegisterImplementation(MonoObject* InMonoObject, const MonoObject* InObject,
	                                   MonoString* InInterfaceName)
	{
		const auto FoundObject = FCSharpEnvironment::GetEnvironment().GetObject(InObject);

		const auto ScriptInterface = new TScriptInterface<IInterface>(FoundObject);

		FCSharpEnvironment::GetEnvironment().AddMultiReference<TScriptInterface<IInterface>>(
			InMonoObject, ScriptInterface);
	}

	static bool IdenticalImplementation(const FGarbageCollectionHandle InA, const FGarbageCollectionHandle InB)
	{
		if (const auto FoundA = FCSharpEnvironment::GetEnvironment().GetMulti<TScriptInterface<IInterface>>(InA))
		{
			if (const auto FoundB = FCSharpEnvironment::GetEnvironment().GetMulti<TScriptInterface<IInterface>>(InB))
			{
				return *FoundA == *FoundB;
			}
		}

		return false;
	}

	static void UnRegisterImplementation(const FGarbageCollectionHandle InGarbageCollectionHandle)
	{
		AsyncTask(ENamedThreads::GameThread, [InGarbageCollectionHandle]
		{
			(void)FCSharpEnvironment::GetEnvironment().RemoveMultiReference<TScriptInterface<IInterface>>(
				InGarbageCollectionHandle);
		});
	}

	static void GetObjectImplementation(const FGarbageCollectionHandle InGarbageCollectionHandle, MonoObject** OutValue)
	{
		const auto Multi = FCSharpEnvironment::GetEnvironment().GetMulti<TScriptInterface<IInterface>>(
			InGarbageCollectionHandle);

		*OutValue = FCSharpEnvironment::GetEnvironment().Bind(Multi->GetObject());
	}

	FRegisterScriptInterface()
	{
		FClassBuilder(TEXT("ScriptInterface"), NAMESPACE_LIBRARY)
			.Function("Register", RegisterImplementation)
			.Function("Identical", IdenticalImplementation)
			.Function("UnRegister", UnRegisterImplementation)
			.Function("GetObject", GetObjectImplementation)
			.Register();
	}
};

static FRegisterScriptInterface RegisterScriptInterface;
