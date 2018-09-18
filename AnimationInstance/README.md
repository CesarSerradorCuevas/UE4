# Animation Instance


![](https://github.com/CesarSerradorCuevas/UE4/blob/master/AnimationInstance/MD/AnimInstanceABP.jpg?raw=true)


# MyAnimInstance.h
```
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class CPPANIMATION_API UTestAnimInst : public UAnimInstance
{
	GENERATED_BODY()


public:

	UTestAnimInst();


public:

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	class ATestCharacter* thisPawn;

	UPROPERTY()
	float varX;
```
# MyAnimInstance.cpp
```
#include "TestAnimInst.h"
#include "TestCharacter.h"


UTestAnimInst::UTestAnimInst()
{
	varX = 10.0f;
}



void UTestAnimInst::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	

	thisPawn = Cast<ATestCharacter>(TryGetPawnOwner());

	FString temp = FString::SanitizeFloat(thisPawn->varX);

	UE_LOG(LogTemp, Warning, TEXT("From Animation Instance: %s"), *temp);
	
}


void UTestAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
```
# CPPcharacter.h
```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

UCLASS(config=Game)
class CPPANIMATION_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	class UTestAnimInst* animInst;

	UPROPERTY()
	float varX;
	
};

```
# CPPcharecter.cpp
```
#include "TestCharacter.h"
#include "TestAnimInst.h"


// Sets default values
ATestCharacter::ATestCharacter()
{
	varX = 20.0f;
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

	animInst = Cast<UTestAnimInst>(GetMesh()->GetAnimInstance());
	FString temp = FString::SanitizeFloat(animInst->varX);
	UE_LOG(LogTemp, Warning, TEXT("From Character Blueprint: %s"), *temp);
	
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
```
