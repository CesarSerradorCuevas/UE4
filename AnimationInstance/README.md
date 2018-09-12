# Animation Instance


![](https://github.com/CesarSerradorCuevas/UE4/blob/master/AnimationInstance/MD/AnimInstanceABP.jpg?raw=true)

```
//MyAnimInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPPCHARACTER_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = Cesar)
	float SpeedCesar;

	UPROPERTY(BlueprintReadWrite, Category = Cesar)
	APawn * OwningPawn;

	UFUNCTION(BlueprintPure, Category = Cesar)
		float CesarFunc();


	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTimeX) override;
	
};

//MyAnimInstance.cpp

#include "MyAnimInstance.h"


void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwningPawn = TryGetPawnOwner();

	UE_LOG(LogTemp, Warning, TEXT("Begin"));
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	Super::NativeUpdateAnimation(DeltaTimeX);

	UE_LOG(LogTemp, Warning, TEXT("Update"));
}

float UMyAnimInstance::CesarFunc()
{
	return 1.0f;
}

//CPPcharacter.h
public:
UPROPERTY()
	class UMyAnimInstance* animInst;


//CPPcharecter.cpp
#include "Engine/Engine.h"
#include "MyAnimInstance.h"

void ACPPcharacterCharacter::BeginPlay()
{

	Super::BeginPlay();

	animInst = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->SpeedCesar = 1000;
	FString TheFloatStr = FString::SanitizeFloat(animInst->SpeedCesar);
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, *TheFloatStr);

	//
	implementableEvent();
	
}
```
