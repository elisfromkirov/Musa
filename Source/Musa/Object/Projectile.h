#pragma once

#include "CoreMinimal.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "GameObject.h"

#include "Projectile.generated.h"

class AGameCharacter;

UCLASS()
class MUSA_API AProjectile : public AGameObject
{
	GENERATED_BODY()

public:
	AProjectile();

	int GetCost() const;

	int GetDamage() const;

protected:
	void OnHitGameCharacter(AGameCharacter* GameCharacter) override;

	void OnHitGameObject(AGameObject* GameObject) override;

	void OnHit() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UProjectileMovementComponent* Movement;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Damage;
};