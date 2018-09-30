
![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Input/MD/ProjectSettings.jpg?raw=true)

* Input
  * BindAction


# BindAction

![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Input/MD/BindActionBP.jpg?raw=true)

```
//Character.h file
UFUNCTION()
	void printSomething();


//Character.cpp file
#include "Engine/Engine.h"

void ACPPcharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACPPcharacter::printSomething);
	

}

void ACPPcharacterCharacter::printSomething()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Jump button pressed"));
}
```

* Documentation
	* [EInputEvent](http://api.unrealengine.com/INT/API/Runtime/Engine/Engine/EInputEvent/index.html)
	* [AddOnScreenDebugMessage](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/UEngine/AddOnScreenDebugMessage/1/index.html)


# BindAxis

PlayerController.h
```
public:
virtual void BeginPlay() override;
virtual void SetupInputComponent() override;
class ACPPgameSetupCharacter* characterOne;
```

PlayerController.cpp
```
#include "CPPgameSetupCharacter.h"

void ADefaultPC::BeginPlay()
{
	Super::BeginPlay();

	characterOne = Cast<ACPPgameSetupCharacter>(GetCharacter());
	
}

void ADefaultPC::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ADefaultPC::MoveForward);
}

void ADefaultPC::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		characterOne->AddMovementInput(Direction, Value);
	}
}
```
