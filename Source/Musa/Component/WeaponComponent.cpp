#include "WeaponComponent.h"

FVector UWeaponComponent::GetDirection()
{
	return GetChildActor()->GetActorRightVector();
}

FVector UWeaponComponent::GetFirePoint()
{
	return GetChildActor()->GetActorLocation() + GetChildActor()->GetActorRightVector() * FirePointOffset;
}