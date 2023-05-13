#pragma once

#include "CoreMinimal.h"

#include "Components/ChildActorComponent.h"

#include "WeaponComponent.generated.h"

UCLASS()
class MUSA_API UWeaponComponent : public UChildActorComponent
{
	GENERATED_BODY()

public:
	FVector GetDirection();

	FVector GetFirePoint();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FirePointOffset;
};