#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/SpringArmComponent.h"

#include "../Component/SpellBookComponent.h"
#include "../Component/WeaponComponent.h"

#include "GameCharacter.h"

#include "Wizard.generated.h"

class UInputComponent;

UCLASS()
class MUSA_API AWizard : public AGameCharacter
{
	GENERATED_BODY()

public:
	AWizard();

protected:
	UFUNCTION(BlueprintCallable)
	void SetupArmour(int Value, int MaxValue);

	UFUNCTION(BlueprintCallable)
	void SetupHealth(int Value, int MaxValue);

	UFUNCTION(BlueprintCallable)
	void SetupMana(int Value, int MaxValue);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWeaponComponent* Weapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpellBookComponent* SpellBook;

private:
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

private:
	void Move(float Value);

	void MoveSide(float Value);

	void LookAround(float Value);

	void LookUp(float Value);

	void ShootFireball();

	void ShootIceShard();

	void ShootMagicbolt();
};