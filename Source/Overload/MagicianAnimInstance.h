// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MagicianAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class OVERLOAD_API UMagicianAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMagicianAnimInstance();
	
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void Attack();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimMontage* attackMontage;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MyInstance, meta = (AllowPrivateAccess = "true"))
	bool IsAttack;
};
