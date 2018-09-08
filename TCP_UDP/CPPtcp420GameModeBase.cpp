// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPtcp420GameModeBase.h"
#include "Engine/Engine.h"//
#include "MyPlayerController.h"//



ACPPtcp420GameModeBase::ACPPtcp420GameModeBase() {

	PlayerControllerClass = AMyPlayerController::StaticClass();
	
}


void ACPPtcp420GameModeBase::BeginPlay() {

	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(0, 4.0f, FColor::Green, TEXT("PRINTED FROM GAME MODE"));

}