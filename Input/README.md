
![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Input/MD/ProjectSettings.jpg?raw=true)

* Input
  * BindAction


# BindAction

```
//.h file
UFUNCTION()
	void printSomething();


//.cpp file
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
