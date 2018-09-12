* Input
  * BindAction


# BindAction

![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Input/MD/ProjectSettings.jpg?raw=true)

```
//.h file
UFUNCTION()
	void printSomething();


//.cpp file
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
