![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Character/AnalogSticks/MD/GamepadInput.jpg?raw=true)

![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Character/AnalogSticks/MD/MovementInput.jpg?raw=true)

# character.cpp
```
#include "GameFramework/Controller.h"

void ACPPcharacterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPPcharacterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPPcharacterCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnRate", this, &ACPPcharacterCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ACPPcharacterCharacter::LookUpAtRate);

}


void ACPPcharacterCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACPPcharacterCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACPPcharacterCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACPPcharacterCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

```
