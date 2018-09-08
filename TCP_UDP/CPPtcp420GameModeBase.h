// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPPtcp420GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPTCP420_API ACPPtcp420GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		ACPPtcp420GameModeBase();

	
public:
	virtual void BeginPlay() override;
	
	
};
