# GreenBox.h

```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GreenBox.generated.h"

//Step 1
DECLARE_DELEGATE(FMyDelegate)

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

	//Step 2
	FMyDelegate OnPrintToScreen;

	
};
```

# GreenBox.cpp
```
#include "GreenBox.h"
#include "TrunkClass.h"


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
	
	//SharedReference
	TSharedRef<TrunkClass> tc(new TrunkClass());
	OnPrintToScreen.BindSP(tc, &TrunkClass::printToScreen);
	OnPrintToScreen.ExecuteIfBound();
	
	
	//SharedPointer
	TSharedPtr<TrunkClass> sp = MakeShareable(new TrunkClass());

	if (sp.IsValid()) {
		sp->printToScreen();
		sp.Reset();
	}

}

// Called every frame
void AGreenBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
```

# TrunkClass.h
```
#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CPPEVENTS_API TrunkClass
{
public:
	TrunkClass();
	~TrunkClass();

	void printToScreen();
};


```

# TrunkClass.cpp
```
#include "TrunkClass.h"

TrunkClass::TrunkClass()
{
}

TrunkClass::~TrunkClass()
{
}

void TrunkClass::printToScreen()
{
	UE_LOG(LogTemp, Warning, TEXT("Isabel"));
}
```

* Documentation
  * [Pointers](https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/SmartPointerLibrary)
