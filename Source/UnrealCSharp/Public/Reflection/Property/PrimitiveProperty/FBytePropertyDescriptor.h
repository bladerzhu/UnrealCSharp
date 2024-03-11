﻿#pragma once

#include "FPrimitivePropertyDescriptor.h"

class FBytePropertyDescriptor final : public FPrimitivePropertyDescriptor
{
public:
	using FPrimitivePropertyDescriptor::FPrimitivePropertyDescriptor;

	void Set(void* Src, void* Dest) const override;
};
