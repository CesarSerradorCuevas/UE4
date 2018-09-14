![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Events/MD/Event.jpg?raw=true)


# GreenBox.h

```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GreenBox.generated.h"
```
#### //Step 1
```
DECLARE_EVENT_OneParam(ABlueBox, FMyevent, FString)

UCLASS()
class CPPEVENTS_API AGreenBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGreenBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
```
#### //Step 2
```
	FMyevent OnPrintToScreen;
	
};

```
# GreenBox.cpp

```
#include "GreenBox.h"


// Sets default values
AGreenBox::AGreenBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGreenBox::BeginPlay()
{
	Super::BeginPlay();

	FString car = "BMW";
```
#### //Step 3
```
	OnPrintToScreen.Broadcast(car);
	
}

// Called every frame
void AGreenBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
```


# BlueBox.h
```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlueBox.generated.h"

UCLASS()
class CPPEVENTS_API ABlueBox : public AActor
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

	void printCar(FString car);	
	
};
```

# BlueBox.cpp

```
#include "BlueBox.h"
#include "GreenBox.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/Engine.h"


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

	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGreenBox::StaticClass(), foundActors);
	AGreenBox *blueBox = Cast<AGreenBox>(foundActors[0]);
```
#### //Step 4
```
	blueBox->OnPrintToScreen.AddUObject(this, &ABlueBox::printCar);
	
}

// Called every frame
void ABlueBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABlueBox::printCar(FString car)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *car);
	GEngine->AddOnScreenDebugMessage(12, 4.0f, FColor::Red, FString::Printf(TEXT("%s"), *car));
}


```

* Documentation
	* [UGameplayStatics](http://api.unrealengine.com/INT/API/Runtime/Engine/Kismet/UGameplayStatics/)
	* [Events](https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Delegates/Events)
