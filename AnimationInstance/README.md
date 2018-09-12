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
```
