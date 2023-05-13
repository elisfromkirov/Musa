#include "GameObject.h"

#include "../Character/GameCharacter.h"

AGameObject::AGameObject()
{
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));

	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	OnActorHit.AddDynamic(this, &AGameObject::DispatchHit);
}

void AGameObject::OnHitGameCharacter(AGameCharacter* GameCharacter)
{
}

void AGameObject::OnHitGameObject(AGameObject* GameObject)
{
}

void AGameObject::OnHit()
{
}

void AGameObject::DispatchHit(AActor* Actor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& HitResult)
{
	if (AGameCharacter* GameCharacter = Cast<AGameCharacter>(OtherActor))
	{
		OnHitGameCharacter(GameCharacter);
	}
	else if (AGameObject* GameObject = Cast<AGameObject>(OtherActor))
	{
		OnHitGameObject(GameObject);
	}
	else
	{
		OnHit();
	}
}