﻿#pragma once

#include "GarbageCollection/FGarbageCollectionHandle.h"
#include "Macro/PropertyMacro.h"
#include "mono/metadata/object.h"

class FPropertyImplementation
{
public:
	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Byte, uint8)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(UInt16, uint16)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(UInt32, uint32)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(UInt64, uint64)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(SByte, int8)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Int16, int16)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Int, int32)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Int64, int64)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Bool, bool)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Float, float)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Object, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Class, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Interface, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Array, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(WeakObject, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(LazyObject, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(SoftClass, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(SoftObject, MonoObject)

	OBJECT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Double, double)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Map, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Set, MonoObject)

	OBJECT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(FieldPath, MonoObject)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Byte, uint8)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(UInt16, uint16)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(UInt32, uint32)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(UInt64, uint64)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(SByte, int8)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Int16, int16)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Int, int32)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Int64, int64)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Bool, bool)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Float, float)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Object, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Class, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Interface, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Array, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(WeakObject, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(LazyObject, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(SoftClass, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(SoftObject, MonoObject)

	STRUCT_PRIMITIVE_PROPERTY_IMPLEMENTATION_DEFINE(Double, double)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Map, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(Set, MonoObject)

	STRUCT_COMPOUND_PROPERTY_IMPLEMENTATION_DEFINE(FieldPath, MonoObject)
};
