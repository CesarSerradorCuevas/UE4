// Fill out your copyright notice in the Description page of Project Settings.

#include "BlueBox.h"
#include "GreenBox.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/Engine.h"


// Sets default values
ABlueBox::ABlueBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlueBox::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGreenBox::StaticClass(), foundActors);
	AGreenBox *blueBox = Cast<AGreenBox>(foundActors[0]);

	//Step 4
	blueBox->OnPrintToScreen.AddUObject(this, &ABlueBox::printCar);
	
}

// Called every frame
void ABlueBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABlueBox::printCar(FString car)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *car);
	GEngine->AddOnScreenDebugMessage(12, 4.0f, FColor::Red, FString::Printf(TEXT("%s"), *car));
}

