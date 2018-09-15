// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPPspawnGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPSPAWN_API ACPPspawnGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		ACPPspawnGameModeBase();

public:

	virtual void BeginPlay();

	
	
};
