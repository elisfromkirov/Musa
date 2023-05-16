#include "Projectile.h"

#include "../Attribute/Health.h"

#include "../Character/GameCharacter.h"

AProjectile::AProjectile()
{
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collider;
}

int AProjectile::GetCost() const
{
	return Cost;
}

int AProjectile::GetDamage() const
{
	return Damage;
}

void AProjectile::OnHitGameCharacter(AGameCharacter* GameCharacter)
{
	UE_LOG(LogTemp, Display, TEXT("On game character hitting"));

	auto Attributes = GameCharacter->GetAttributes();
	if (Attributes->Has<FHealth>())
	{
		auto Health = Attributes->Get<FHealth>();
		Health->SetValue(Health->GetValue() - Damage);
	}

	Destroy();
}

void AProjectile::OnHitGameObject(AGameObject* GameObject)
{
	UE_LOG(LogTemp, Display, TEXT("On game object hitting"));

	Destroy();
}

void AProjectile::OnHit()
{
	UE_LOG(LogTemp, Display, TEXT("On arbitrary actor hitting"));

	Destroy();
}