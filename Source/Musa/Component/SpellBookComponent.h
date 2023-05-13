#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "../Object/Projectile.h"

#include "WeaponComponent.h"

#include "SpellBookComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MUSA_API USpellBookComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void SetWeapon(UWeaponComponent* NewWeapon);

	void SpawnFireball();

	void SpawnIceShard();

	void SpawnMagicbolt();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectile> Fireball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectile> IceShard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectile> Magicbolt;

private:
	UWeaponComponent* Weapon;
};