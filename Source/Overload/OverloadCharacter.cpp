// Fill out your copyright notice in the Description page of Project Settings.

#include "Overload.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "OverloadCharacter.h"

// Sets default values
AOverloadCharacter::AOverloadCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	//GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;

	//CameraBoom->TargetArmLength = 30.f;//500.f;
	//CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	//CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));
///targetOffset.z = 15;

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera
/**
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
**/
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	FootMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FootMesh");
	FootMesh->SetupAttachment(GetMesh());

	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandMesh");
	HandMesh->SetupAttachment(GetMesh());

	HeadMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HeadMesh");
	HeadMesh->SetupAttachment(GetMesh());

	LegMesh = CreateDefaultSubobject<USkeletalMeshComponent>("LegMesh");
	LegMesh->SetupAttachment(GetMesh());

	FaceMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FaceMesh");
	FaceMesh->SetupAttachment(GetMesh());

	FootMesh->SetMasterPoseComponent(GetMesh());
	HandMesh->SetMasterPoseComponent(GetMesh());
	HeadMesh->SetMasterPoseComponent(GetMesh());
	LegMesh->SetMasterPoseComponent(GetMesh());
	FaceMesh->SetMasterPoseComponent(GetMesh());

}

// Called when the game starts or when spawned
void AOverloadCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
    // 5 초간 디버그 메시지를 표시합니다. (첫 인수인) -1 "Key" 값은 이 메시지를 업데이트 또는 새로고칠 필요가 없음을 나타냅니다.
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	}

	GetMesh()->SetSkeletalMesh(ChestMesh_0);

	FootMesh->SetSkeletalMesh(FootMesh_0);
	HandMesh->SetSkeletalMesh(HandMesh_0);
	HeadMesh->SetSkeletalMesh(HeadMesh_0);
	LegMesh->SetSkeletalMesh(LegMesh_0);
	FaceMesh->SetSkeletalMesh(FaceMesh_0);

/**
				//Second Setup Hair
			if (CustomizingInfo.HairIndex >= 0)
			{
				USkeletalMeshComponent* HairMeshComponent = NewObject<USkeletalMeshComponent>(Character, "HairMesh");
				HairMeshComponent->RegisterComponentWithWorld(GetWorld());
				HairMeshComponent->SetSkeletalMesh(GameInstance->GetHairOptions()->Datas[CustomizingInfo.HairIndex].Mesh);

				UMaterialInstanceDynamic* InstanceMaterial = HairMeshComponent->CreateDynamicMaterialInstance(0);
				InstanceMaterial->SetVectorParameterValue("RootColor", CustomizingInfo.HairColor);
				InstanceMaterial->SetVectorParameterValue("TipColor", CustomizingInfo.HairColor);
				HairMeshComponent->SetMaterial(0, InstanceMaterial);

				HairMeshComponent->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale);
				HairMeshComponent->SetMasterPoseComponent(Character->GetMesh());
			}
**/
}

// Called every frame
void AOverloadCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOverloadCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

