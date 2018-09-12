* Tracing
  * Line Trace By Channel


# Line Trace By Channnel


![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Tracing/MD/LineTraceByChannel.jpg?raw=true)


```
//.h file
public:
UWorld *thisWorld;
FHitResult outHit;
FCollisionQueryParams collisionParams;


//.cpp file
//#include "Engine/Engine.h"

void ACPPcharacterCharacter::BeginPlay()
{

	Super::BeginPlay();

	thisWorld = GetWorld();
	
}

void ACPPcharacterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector loc = GetActorLocation();
	FVector forw = GetActorForwardVector() * 100;
	FVector locPlus = loc + forw;


	bool isHit = thisWorld->LineTraceSingleByChannel(outHit, loc, locPlus, ECC_Visibility, collisionParams);
	if (isHit) {
		GEngine->AddOnScreenDebugMessage(-1, 0.1, FColor::Blue, FString::Printf(TEXT("%s"), *outHit.GetActor()->GetName()));
	}
	
	
}
```

[ECollisionChannel](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/ECollisionChannel/index.html)
[FHitResult](http://api.unrealengine.com/INT/API/Runtime/Engine/Engine/FHitResult/)
