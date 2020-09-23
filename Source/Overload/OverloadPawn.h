// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "OverloadPawn.generated.h"

UCLASS()
class OVERLOAD_API AOverloadPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AOverloadPawn();

public:    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ABPawnComponent")
    class UCapsuleComponent* Body = nullptr;
 
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ABPawnComponent")
    class USkeletalMeshComponent* SkelMesh = nullptr;
   
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ABPawnComponent")
    class UArrowComponent* Arrow = nullptr;
 
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ABPawnComponent")
    class USpringArmComponent* SpringArm = nullptr;
 
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ABPawnComponent")
    class UCameraComponent* Camera = nullptr;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
 		class UAnimMontage * Montage = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* FaceMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* HairMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* FootMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* HandMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* LegMesh;
/**
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* ChestMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* FaceMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* HairMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* FootMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* HandMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* LegMesh_0;
**/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
