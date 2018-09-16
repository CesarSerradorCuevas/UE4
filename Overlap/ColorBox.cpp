// Fill out your copyright notice in the Description page of Project Settings.

#include "ColorBox.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "CPPoverlapCharacter.h"


// Sets default values
AColorBox::AColorBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxComponent->InitBoxExtent(FVector(100.f, 100.f, 100.f));
	boxComponent->SetCollisionProfileName(TEXT("trigger"));
	RootComponent = boxComponent;

	boxStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxShape"));
	boxStaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	boxStaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	boxStaticMesh->SetupAttachment(RootComponent);

	boxComponent->OnComponentBeginOverlap.AddDynamic(this, &AColorBox::onOverlapBegin);
	boxComponent->OnComponentEndOverlap.AddDynamic(this, &AColorBox::onOverlapEnd);

}

// Called when the game starts or when spawned
void AColorBox::BeginPlay()
{
	Super::BeginPlay();

	playerChar = Cast<ACPPoverlapCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	matInstance = boxStaticMesh->CreateAndSetMaterialInstanceDynamic(0);
	
}

// Called every frame
void AColorBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColorBox::onOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		ACPPoverlapCharacter* gameChar = Cast<ACPPoverlapCharacter>(OtherActor);

		if (gameChar == playerChar) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("IN"));
			
			if (matInstance != nullptr)
			{
				matInstance->SetVectorParameterValue(FName("ColorToChange"), FLinearColor::Green);
			}
			
		}

	}
}

void AColorBox::onOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		ACPPoverlapCharacter* gameChar = Cast<ACPPoverlapCharacter>(OtherActor);

		if (gameChar == playerChar) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("OUT"));

			if (matInstance != nullptr)
			{
				matInstance->SetVectorParameterValue(FName("ColorToChange"), FLinearColor(0, 0.25, 1));
			}

		}

	}
}

