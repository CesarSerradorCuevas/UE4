* Rotator
	* Get Bone Forward Vector
	


# GET BONE FORWARD VECTOR

![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Rotator/MD/GamePlay.jpg?raw=true)
![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Rotator/MD/FootL.jpg?raw=true)
![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Rotator/MD/ForwardVectorA.jpg?raw=true)

```
//.h file
public:
USkeletalMeshComponent *thisMesh;
UWorld *thisWorld;


//.cpp file
void ACPPcharacter::BeginPlay()
{

	Super::BeginPlay();

	thisMesh = GetMesh();
	thisWorld = GetWorld();
	
	
}

void ACPPcharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector loc = GetActorLocation();
	FVector forw = GetActorForwardVector() * 100;
	FVector locPlus = loc + forw;

	FVector footForw = FRotationMatrix(thisMesh->GetSocketRotation("foot_l")).GetScaledAxis(EAxis::Y) * 100;
	FVector footLoc = thisMesh->GetSocketLocation("foot_l");
	FVector footPlus = footLoc + footForw;

	DrawDebugLine(thisWorld, footLoc, footPlus, FColor::Orange, false, 0, -1, 2);	
	
}

```

* Documentation Links
	* [FRotationMatrix](https://api.unrealengine.com/INT/API/Runtime/Core/Math/FRotationMatrix/index.html)
	* [FMatrix](https://api.unrealengine.com/INT/API/Runtime/Core/Math/FMatrix/index.html)
	* [DrawDebugLine](https://api.unrealengine.com/INT/API/Runtime/Engine/DrawDebugLine/index.html)
