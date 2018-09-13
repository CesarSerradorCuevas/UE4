// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GreenBox.generated.h"

//Step 1
DECLARE_EVENT_OneParam(ABlueBox, FMyevent, FString)

UCLASS()
class CPPEVENTS_API AGreenBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGreenBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Step 2
	FMyevent OnPrintToScreen;
	
};
