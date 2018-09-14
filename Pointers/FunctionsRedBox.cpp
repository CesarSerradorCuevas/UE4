// Fill out your copyright notice in the Description page of Project Settings.

#include "FunctionsRedBox.h"
#include "Engine/Engine.h"

FunctionsRedBox::FunctionsRedBox()
{
}

FunctionsRedBox::~FunctionsRedBox()
{
}

void FunctionsRedBox::printToScreen()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Red, TEXT("BMW"));
}
