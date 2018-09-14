![](https://github.com/CesarSerradorCuevas/UE4/blob/master/GetAllActorsOfClass/MD/GetAllActorsOfClass.jpg?raw=true)

```
#include "BlueBox.h"
#include "GreenBox.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/Engine.h"


void ABlueBox::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> foundActors;
	TArray<AGreenBox*> greenBoxes;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGreenBox::StaticClass(), foundActors);

	int total = 0;

	for (AActor *i : foundActors) {
		AGreenBox *xx = Cast<AGreenBox>(i);	
		greenBoxes.Add(xx);
		FString boxName = xx->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *boxName);
		total += 1;
	}

	GEngine->AddOnScreenDebugMessage(12, 4.0f, FColor::Red, FString::Printf(TEXT("Total number of green boxes: %d"), total));
	
}
```

* Documentation
  * [UGameplayStatics](http://api.unrealengine.com/INT/API/Runtime/Engine/Kismet/UGameplayStatics/)
