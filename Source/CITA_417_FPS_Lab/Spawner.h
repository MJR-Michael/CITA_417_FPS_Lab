// Spawner.h
#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"


UCLASS()
class CITA_417_FPS_LAB_API ASpawner : public AActor
{
GENERATED_BODY()


public:
ASpawner();


protected:
virtual void BeginPlay() override;
virtual void Tick(float DeltaTime) override;
void SpawnObjects();


FTimerHandle SpawnTimerHandle;
int32 TotalSpawns = 0;
FVector StartLocation;


public:
UPROPERTY(EditAnywhere, Category="Spawner")
TSubclassOf<AActor> ObjectToSpawn;


UPROPERTY(EditAnywhere, Category="Spawner")
float SpawnInterval = 0.5f;


UPROPERTY(EditAnywhere, Category="Spawner")
int32 ObjectsPerBatch = 10;


UPROPERTY(EditAnywhere, Category="Spawner")
float TotalDuration = 60.f;


// Movement properties
UPROPERTY(EditAnywhere, Category="Movement")
float MovementSpeed = 2.f;


UPROPERTY(EditAnywhere, Category="Movement")
float MovementDistance = 200.f;
};