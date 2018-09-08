// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Engine/Engine.h"//
#include "MyUserWidget.h"//
#include "UObject/ConstructorHelpers.h"//



AMyPlayerController::AMyPlayerController() {

	ConstructorHelpers::FClassFinder<UUserWidget> MenuClassFinder(TEXT("/Game/WidgetX"));
	if (!ensure(MenuClassFinder.Class != nullptr)) return;
	MenuClass = MenuClassFinder.Class;

}


void AMyPlayerController::BeginPlay() {

	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor::Red, TEXT("PRINTED FROM PLAYER CONTROLLER"));

	bShowMouseCursor = true;

	

	UserInterface = CreateWidget<UMyUserWidget>(this, MenuClass);
	FInputModeGameAndUI Mode;
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	Mode.SetHideCursorDuringCapture(false);
	SetInputMode(Mode);
	UserInterface->AddToViewport();
}

void AMyPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();

	this->InputComponent->BindAction("Green", IE_Released, this, &AMyPlayerController::PressingA);
}


void AMyPlayerController::PressingA()
{

	UE_LOG(LogTemp, Warning, TEXT("GREEN BUTTON"));
	
	GEngine->AddOnScreenDebugMessage(2, 2.0f, FColor::Yellow, TEXT("GREEN BUTTON"));

}