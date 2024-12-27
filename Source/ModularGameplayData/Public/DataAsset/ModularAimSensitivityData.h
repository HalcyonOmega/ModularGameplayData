// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataAsset.h"

#include "ModularAimSensitivityData.generated.h"

// Define the enum before the class that uses it
UENUM(BlueprintType)
enum class EModularGamepadSensitivity : uint8
{
	Slow UMETA(DisplayName = "Slow"),
	SlowPlus UMETA(DisplayName = "Slow+"),
	SlowPlusPlus UMETA(DisplayName = "Slow++"),
	Normal UMETA(DisplayName = "Normal"),
	NormalPlus UMETA(DisplayName = "Normal+"),
	NormalPlusPlus UMETA(DisplayName = "Normal++"),
	Fast UMETA(DisplayName = "Fast"),
	FastPlus UMETA(DisplayName = "Fast+"),
	FastPlusPlus UMETA(DisplayName = "Fast++"),
	Insane UMETA(DisplayName = "Insane")
};

class UObject;

/** Defines a set of gamepad sensitivity to a float value. */
UCLASS(BlueprintType, Const, Meta = (DisplayName = "Modular Aim Sensitivity Data", ShortTooltip = "Data asset used to define a map of Gamepad Sensitivty to a float value."))
class MODULARGAMEPLAYDATA_API UModularAimSensitivityData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UModularAimSensitivityData(const FObjectInitializer& ObjectInitializer);

	const float SensitivityEnumToFloat(const EModularGamepadSensitivity InSensitivity) const;

protected:
	/** Map of SensitivityMap settings to their corresponding float */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EModularGamepadSensitivity, float> SensitivityMap;
};