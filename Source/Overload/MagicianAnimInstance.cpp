// Fill out your copyright notice in the Description page of Project Settings.

#include "Overload.h"

#include "Animation/AnimMontage.h"
#include "UObject/ConstructorHelpers.h"

#include "MagicianAnimInstance.h"

UMagicianAnimInstance::UMagicianAnimInstance()
{
	IsAttack = false;


/**
		static ConstructorHelpers::FObjectFinder<UAnimMontage> MontageObj(TEXT("AnimMontage'/Game/Assets/Animations/BP_NormalMontage'"));
 		Montage = MontageObj.Object;
**/

  static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("AnimMontage'/Game/Blueprints/Animations/BP_RunAnimMontage'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		attackMontage = ATTACK_MONTAGE.Object;
	}
}

void UMagicianAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UMagicianAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UMagicianAnimInstance::Attack()
{
	//TODO : Play Attack Montage
  Montage_Play(attackMontage);
}