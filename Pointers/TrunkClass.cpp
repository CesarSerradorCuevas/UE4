// Fill out your copyright notice in the Description page of Project Settings.

#include "TrunkClass.h"
#include "Engine/Engine.h"

TrunkClass::TrunkClass()
{
}

TrunkClass::~TrunkClass()
{
}

void TrunkClass::printToScreen()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("Isabel"));
	UE_LOG(LogTemp, Warning, TEXT("Isabel"));
}
