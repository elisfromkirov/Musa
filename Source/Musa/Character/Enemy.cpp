#include "Enemy.h"

#include "Components/InputComponent.h"

#include "../Attribute/Health.h"

#include "../Effect/Death.h"

AEnemy::AEnemy()
{
	SetActorTickEnabled(true);

	Attributes->Add<FHealth>();

	Effects->Add<FDeath>();
}

void AEnemy::SetupHealth(int Value, int MaxValue)
{
	auto Health = Attributes->Get<FHealth>();
	Health->SetMaxValue(MaxValue);
	Health->SetValue(Value);
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Attributes->OnTick(DeltaTime, this);

	Effects->OnTick(DeltaTime, this);
}