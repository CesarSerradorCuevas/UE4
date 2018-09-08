// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPPTCP420_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

		AMyPlayerController();
	
	
public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent();
	void PressingA();

	
private:
	TSubclassOf<class UUserWidget> MenuClass;

	class UMyUserWidget* UserInterface;
	
};
