// Fill out your copyright notice in the Description page of Project Settings.

#include "BlueBoxPC.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "BlueBox.h"

ABlueBoxPC::ABlueBoxPC()
{
	ConstructorHelpers::FClassFinder<ABlueBox> blueBox(TEXT("/Game/BlueBoxBP"));

	if (!ensure(blueBox.Class != nullptr)) return;

	blueBoxBP = blueBox.Class;

}

void ABlueBoxPC::BeginPlay()
{
	Super::BeginPlay();

	FRotator Rot(0, 0, 0);
	FVector Loc(FMath::RandRange(-300, 300), FMath::RandRange(-300, 300), FMath::RandRange(100, 200));
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<ABlueBox>(blueBoxBP, Loc, Rot, SpawnInfo);

	TArray<AActor*> foundCameras;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), foundCameras);
	
	SetViewTarget((AActor*)foundCameras[0]);

}
