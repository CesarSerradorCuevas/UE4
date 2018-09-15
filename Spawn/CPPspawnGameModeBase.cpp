// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPspawnGameModeBase.h"
#include "BlueBoxPC.h"

ACPPspawnGameModeBase::ACPPspawnGameModeBase()
{
	PlayerControllerClass = ABlueBoxPC::StaticClass();
	DefaultPawnClass = NULL;
}

void ACPPspawnGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	
	
}
