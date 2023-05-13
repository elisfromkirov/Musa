#include "SpellBookComponent.h"

void USpellBookComponent::SetWeapon(UWeaponComponent* NewWeapon)
{
	Weapon = NewWeapon;
}

void USpellBookComponent::SpawnFireball()
{
	auto Location = Weapon->GetFirePoint();
	auto Rotation = Weapon->GetDirection().Rotation();
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(Fireball, Location, Rotation, FActorSpawnParameters());
}

void USpellBookComponent::SpawnIceShard()
{
	auto Location = Weapon->GetFirePoint();
	auto Rotation = Weapon->GetDirection().Rotation();
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(IceShard, Location, Rotation, FActorSpawnParameters());
}

void USpellBookComponent::SpawnMagicbolt()
{
	auto Location = Weapon->GetFirePoint();
	auto Rotation = Weapon->GetDirection().Rotation();
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(Magicbolt, Location, Rotation, FActorSpawnParameters());
}