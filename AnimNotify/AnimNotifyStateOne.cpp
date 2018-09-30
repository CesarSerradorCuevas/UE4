// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimNotifyStateOne.h"
#include "Engine/Engine.h"

void UAnimNotifyStateOne::NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.4f, FColor::Green, TEXT("AnimNotifyStateOne start"));
}

void UAnimNotifyStateOne::NotifyTick(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float FrameDeltaTime)
{
}

void UAnimNotifyStateOne::NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.4f, FColor::Red, TEXT("AnimNotifyStateOne end"));
}
