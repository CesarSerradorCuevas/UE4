# Redbox.h

```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedBox.generated.h"

UCLASS()
class CPPPOINTERS_API ARedBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
```

# Redbox.cpp
```
#include "RedBox.h"


// Sets default values
ARedBox::ARedBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARedBox::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ARedBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
```

# FunctionsRedBox.h
```
#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CPPPOINTERS_API FunctionsRedBox
{
public:
	FunctionsRedBox();
	~FunctionsRedBox();

	void printToScreen();
};

```

# FunctionsRedbox.cpp
```
#include "FunctionsRedBox.h"
#include "Engine/Engine.h"

FunctionsRedBox::FunctionsRedBox()
{
}

FunctionsRedBox::~FunctionsRedBox()
{
}

void FunctionsRedBox::printToScreen()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Red, TEXT("BMW"));
}

```

* Documentation
  * [Pointers](https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/SmartPointerLibrary)
