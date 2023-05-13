#pragma once

#include "CoreMinimal.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

#include "GameFramework/Actor.h"

#include "GameObject.generated.h"

class AGameCharacter;

UCLASS()
class AGameObject : public AActor
{
	GENERATED_BODY()

public:
	AGameObject();

protected:
	UFUNCTION()
	void DispatchHit(AActor* Actor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& HitResult);

protected:
	virtual void OnHitGameCharacter(AGameCharacter* GameCharacter);

	virtual void OnHitGameObject(AGameObject* GameObject);

	virtual void OnHit();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* Collider;
};