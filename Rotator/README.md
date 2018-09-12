
![](https://github.com/CesarSerradorCuevas/UE4/blob/master/Rotator/MD/ForwardVector.jpg?raw=true)

```
//.h file
public:
USkeletalMeshComponent *thisMesh;


//.cpp file
void ACPPcharacter::BeginPlay()
{

	Super::BeginPlay();

	USkeletalMeshComponent *thisMesh = GetMesh();
	
	
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

	DrawDebugLine(GetWorld(), footLoc, footPlus, FColor::Orange, false, 0, -1, 2);	
	
}

```
