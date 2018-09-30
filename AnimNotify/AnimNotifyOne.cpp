// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimNotifyOne.h"
#include "Engine/Engine.h"

void UAnimNotifyOne::Notify(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.4f, FColor::Yellow, TEXT("AnimNotifyOne called"));
}
