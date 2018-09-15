// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BlueBoxPC.generated.h"

/**
 * 
 */
UCLASS()
class CPPSPAWN_API ABlueBoxPC : public APlayerController
{
	GENERATED_BODY()

		ABlueBoxPC();

public:
		virtual void BeginPlay();

private:
		TSubclassOf<class ABlueBox> blueBoxBP;
	
};
