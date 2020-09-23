// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OverloadCharacter.generated.h"

UCLASS()
class OVERLOAD_API AOverloadCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOverloadCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public :
	//GetMesh
	///class USkeletalMeshComponent* ChestMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* FootMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* HandMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* HeadMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* LegMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MultiPart")
	class USkeletalMeshComponent* FaceMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* ChestMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* FootMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* HandMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* HeadMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* LegMesh_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* FaceMesh_0;
};
