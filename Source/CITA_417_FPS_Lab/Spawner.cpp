// Spawner.cpp
#include "Spawner.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"


ASpawner::ASpawner()
{
PrimaryActorTick.bCanEverTick = true;


// Root component to make actor movable
RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}


void ASpawner::BeginPlay()
{
Super::BeginPlay();


StartLocation = GetActorLocation();


GetWorld()->GetTimerManager().SetTimer(
SpawnTimerHandle,
this,
&ASpawner::SpawnObjects,
SpawnInterval,
true
);
}


void ASpawner::Tick(float DeltaTime)
{
Super::Tick(DeltaTime);


float Time = GetWorld()->TimeSeconds;
float Offset = FMath::Sin(Time * MovementSpeed) * MovementDistance;


FVector NewLocation = StartLocation;
NewLocation.X += Offset; // Moves left and right along X axis
SetActorLocation(NewLocation);
}


void ASpawner::SpawnObjects()
{
if (!ObjectToSpawn) return;


float Elapsed = TotalSpawns * SpawnInterval;
if (Elapsed >= TotalDuration)
{
GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
return;
}


for (int32 i = 0; i < ObjectsPerBatch; i++)
{
GetWorld()->SpawnActor<AActor>(ObjectToSpawn, GetActorLocation(), GetActorRotation());
}


TotalSpawns++;
}