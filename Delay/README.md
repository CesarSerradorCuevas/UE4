![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Delay/MD/Delay.jpg?raw=true)

```
//.h file
public:

UWorld* World;

UFUNCTION()
	void printFunc();



//.cpp file
#include "Engine/Engine.h"

void AActorA::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	FTimerHandle _TimerHandle;
	World->GetTimerManager().SetTimer(_TimerHandle, this, &AActorA::printFunc, 4.0f, false);
	
}

void AActorA::printFunc()
{
	GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, TEXT("Hello"));
}
```

* Documentation
	* [FTimerHandle](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/FTimerHandle/index.html)
