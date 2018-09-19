
![](https://github.com/CesarSerradorCuevas/UE4/blob/master/ForceFeedback/MD/ForceFeedback.jpg?raw=true)

# PlayerController.h

```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DefaultPC.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAMESETUP_API ADefaultPC : public APlayerController
{
	GENERATED_BODY()

		ADefaultPC();

public:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
	UForceFeedbackEffect* FFoneInst;
	
	void pressYellow();
};

```


# PlayerController.cpp

```
#include "DefaultPC.h"
#include "UObject/ConstructorHelpers.h"


ADefaultPC::ADefaultPC()
{
	static ConstructorHelpers::FObjectFinder<UForceFeedbackEffect> FFone(TEXT("/Game/ContentX/FFone"));
	if (FFone.Succeeded())
	{
		FFoneInst = FFone.Object;
	}
	
}

void ADefaultPC::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADefaultPC::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Yellow", IE_Pressed, this, &ADefaultPC::pressYellow);

}

void ADefaultPC::pressYellow()
{
	ClientPlayForceFeedback(FFoneInst, false, FName("Force Feedback One"));
}

```


* Documentation
  * [ConstructorHelpers](https://api.unrealengine.com/INT/API/Runtime/CoreUObject/UObject/ConstructorHelpers/index.html)
