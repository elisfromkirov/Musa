#include "Projectile.h"

AProjectile::AProjectile()
{
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collider;
}

void AProjectile::OnHitGameCharacter(AGameCharacter* GameCharacter)
{
	UE_LOG(LogTemp, Display, TEXT("On game character hitting"));

	// TODO: (elisfromkirov) damage hitted character

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