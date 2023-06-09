#include "Wizard.h"

#include "Components/InputComponent.h"

#include "../Attribute/Armor.h"
#include "../Attribute/Health.h"
#include "../Attribute/Mana.h"

AWizard::AWizard()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	Weapon = CreateDefaultSubobject<UWeaponComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), TEXT("Weapon"));

	SpellBook = CreateDefaultSubobject<USpellBookComponent>(TEXT("SpellBook"));
	SpellBook->SetWeapon(Weapon);

	Attributes->Add<FArmor>();
	Attributes->Add<FHealth>();
	Attributes->Add<FMana>();
}

void AWizard::SetupArmour(int Value, int MaxValue)
{
	auto Armor = Attributes->Get<FArmor>();
	Armor->SetMaxValue(MaxValue);
	Armor->SetValue(Value);
}

void AWizard::SetupHealth(int Value, int MaxValue)
{
	auto Health = Attributes->Get<FHealth>();
	Health->SetMaxValue(MaxValue);
	Health->SetValue(Value);
}

void AWizard::SetupMana(int Value, int MaxValue)
{
	auto Mana = Attributes->Get<FMana>();
	Mana->SetMaxValue(MaxValue);
	Mana->SetValue(Value);
}

void AWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ChoseFireball"), IE_Released, this, &AWizard::ShootFireball);
	PlayerInputComponent->BindAction(TEXT("ChoseIceShard"), IE_Released, this, &AWizard::ShootIceShard);
	PlayerInputComponent->BindAction(TEXT("ChoseMagicbolt"), IE_Released, this, &AWizard::ShootMagicbolt);

	PlayerInputComponent->BindAxis(TEXT("Move"), this, &AWizard::Move);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &AWizard::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("LookAround"), this, &AWizard::LookAround);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AWizard::LookUp);
}

void AWizard::Move(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AWizard::MoveSide(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AWizard::LookAround(float Value)
{
	AddControllerYawInput(Value);
}	

void AWizard::LookUp(float Value)
{
	auto Rotator = CameraBoom->GetRelativeRotation();
	CameraBoom->SetRelativeRotation(FRotator(Rotator.Pitch + Value, Rotator.Yaw, Rotator.Roll));
}

void AWizard::ShootFireball()
{
	SpellBook->SpawnFireball();
}

void AWizard::ShootIceShard()
{
	SpellBook->SpawnIceShard();
}

void AWizard::ShootMagicbolt()
{
	SpellBook->SpawnMagicbolt();
}
