// Fill out your copyright notice in the Description page of Project Settings.

#include "GreenBox.h"
#include "TrunkClass.h"


// Sets default values
AGreenBox::AGreenBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGreenBox::BeginPlay()
{
	Super::BeginPlay();

	TSharedRef<TrunkClass> tc(new TrunkClass());
	OnPrintToScreen.BindSP(tc, &TrunkClass::printToScreen);
	OnPrintToScreen.ExecuteIfBound();

	TSharedPtr<TrunkClass> sp = MakeShareable(new TrunkClass());

	if (sp.IsValid()) {
		sp->printToScreen();
		sp.Reset();
	}

}

// Called every frame
void AGreenBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



