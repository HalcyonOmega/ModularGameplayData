// Copyright Epic Games, Inc. All Rights Reserved.

#include "DataAsset/ModularAimSensitivityData.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(ModularAimSensitivityData)

UModularAimSensitivityData::UModularAimSensitivityData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SensitivityMap =
	{
		{ EModularGamepadSensitivity::Slow,			0.5f },
		{ EModularGamepadSensitivity::SlowPlus,		0.75f },
		{ EModularGamepadSensitivity::SlowPlusPlus,	0.9f },
		{ EModularGamepadSensitivity::Normal,		1.0f },
		{ EModularGamepadSensitivity::NormalPlus,	1.1f },
		{ EModularGamepadSensitivity::NormalPlusPlus,1.25f },
		{ EModularGamepadSensitivity::Fast,			1.5f },
		{ EModularGamepadSensitivity::FastPlus,		1.75f },
		{ EModularGamepadSensitivity::FastPlusPlus,	2.0f },
		{ EModularGamepadSensitivity::Insane,		2.5f },
	};
}

const float UModularAimSensitivityData::SensitivityEnumToFloat(const EModularGamepadSensitivity InSensitivity) const
{
	if (const float* Sens = SensitivityMap.Find(InSensitivity))
	{
		return *Sens;
	}
	
	return 1.0f;
}

