![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Spawn/MD/SpawnBox.jpg?raw=true)

# GameMode.h
```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPPspawnGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPSPAWN_API ACPPspawnGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		ACPPspawnGameModeBase();

public:

	virtual void BeginPlay();

	
	
};
```

# GameMode.cpp
```
#include "CPPspawnGameModeBase.h"
#include "BlueBoxPC.h"

ACPPspawnGameModeBase::ACPPspawnGameModeBase()
{
	PlayerControllerClass = ABlueBoxPC::StaticClass();
	DefaultPawnClass = NULL;
}

void ACPPspawnGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	
	
}
```

# PlayerController.h
```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BlueBoxPC.generated.h"

/**
 * 
 */
UCLASS()
class CPPSPAWN_API ABlueBoxPC : public APlayerController
{
	GENERATED_BODY()

		ABlueBoxPC();

public:
		virtual void BeginPlay();

private:
		TSubclassOf<class ABlueBox> blueBoxBP;
	
};
```

# PlayerController.cpp
```
#include "BlueBoxPC.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "BlueBox.h"

ABlueBoxPC::ABlueBoxPC()
{
	ConstructorHelpers::FClassFinder<ABlueBox> blueBox(TEXT("/Game/BlueBoxBP"));

	if (!ensure(blueBox.Class != nullptr)) return;

	blueBoxBP = blueBox.Class;

}

void ABlueBoxPC::BeginPlay()
{
	Super::BeginPlay();

	FRotator Rot(0, 0, 0);
	FVector Loc(FMath::RandRange(-300, 300), FMath::RandRange(-300, 300), FMath::RandRange(100, 200));
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<ABlueBox>(blueBoxBP, Loc, Rot, SpawnInfo);

	TArray<AActor*> foundCameras;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), foundCameras);
	
	SetViewTarget((AActor*)foundCameras[0]);

}

```

# Actor.h
```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlueBox.generated.h"

UCLASS()
class CPPSPAWN_API ABlueBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlueBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
```

# Actor.cpp
```
#include "BlueBox.h"


// Sets default values
ABlueBox::ABlueBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlueBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlueBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
```
