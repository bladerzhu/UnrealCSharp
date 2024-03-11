﻿#pragma once

#include "FPrimitivePropertyDescriptor.h"

class FUInt64PropertyDescriptor final : public FPrimitivePropertyDescriptor
{
public:
	using FPrimitivePropertyDescriptor::FPrimitivePropertyDescriptor;

	void Set(void* Src, void* Dest) const override;
};
