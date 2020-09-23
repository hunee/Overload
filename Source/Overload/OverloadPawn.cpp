// Fill out your copyright notice in the Description page of Project Settings.

#include "Overload.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimBlueprint.h"

#include "GameFramework/SpringArmComponent.h"

#include "UObject/ConstructorHelpers.h"

#include "MagicianAnimInstance.h"

#include "OverloadPawn.h"

// Sets default values
AOverloadPawn::AOverloadPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

// Collision - CapsuleComponent
    Body = CreateDefaultSubobject<UCapsuleComponent>(TEXT("ATestPawnCapsuleComponent"));
    check(Body);
    Body->SetCapsuleSize(34.f, 88.f);
 
    // set as RootComponent
    RootComponent = Body;
 
    // Rendering - SkeletalMeshComponent
    SkelMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ATestPawnSkeletalMeshComponent"));
    check(SkelMesh);
 
    SkelMesh->SetRelativeLocationAndRotation(
        FVector(0.f, 0.f,0.f),
        FRotator(0.f, -90.f, 0.f)    // Roll
    );
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_Warrior(TEXT("SkeletalMesh'/Game/Assets/Magician_Female_Chest_000'"));
    SkelMesh->SetSkeletalMesh(SK_Warrior.Object);    
    // Attacth to RootComponent
    SkelMesh->SetupAttachment(RootComponent);
 


    // ArrowComponent
    Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ATestPawnArrowComponent"));
    check(Arrow);
    // Attacth to RootComponent
    Arrow->SetupAttachment(RootComponent);
 
    // SpringArmComponent
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("ATestPawnSpringArmComponent"));
    check(SpringArm);
 
    SpringArm->TargetArmLength = 650.f;
    // Pitch
    SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
    // Disable inherit
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = false;
    SpringArm->bInheritRoll = false;
 
    // Attacth to RootComponent
    SpringArm->SetupAttachment(RootComponent);
 
    // CameraComponent
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ATestPawnCameraComponent"));
    check(Camera);
    // Attacth to SpringArmComponent
    Camera->SetupAttachment(SpringArm);


	//Animation Setup
	SkelMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	//static ConstructorHelpers::FClassFinder<UObject> AnimBPClass(TEXT("/Game/Blueprints/Animations/BP_AnimNormal"));
	//애니메이션 블루프린트 가져오기 클래스를 가져오는 것이기 때문에 맨 마지막에 _C를 붙여아함
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimBPClass(TEXT("AnimBlueprint'/Game/Blueprints/Animations/BP_AnimNormal.BP_AnimNormal_C'"));

	check(AnimBPClass.Succeeded());
	
	SkelMesh->SetAnimInstanceClass(AnimBPClass.Class);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	FaceMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FaceMesh");
	FaceMesh->SetupAttachment(SkelMesh);

	HairMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HairMesh");
	HairMesh->SetupAttachment(SkelMesh);

	FootMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FootMesh");
	FootMesh->SetupAttachment(SkelMesh);

	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandMesh");
	HandMesh->SetupAttachment(SkelMesh);

	LegMesh = CreateDefaultSubobject<USkeletalMeshComponent>("LegMesh");
	LegMesh->SetupAttachment(SkelMesh);

	FaceMesh->SetMasterPoseComponent(SkelMesh);
	HairMesh->SetMasterPoseComponent(SkelMesh);
	FootMesh->SetMasterPoseComponent(SkelMesh);
	HandMesh->SetMasterPoseComponent(SkelMesh);
	LegMesh->SetMasterPoseComponent(SkelMesh);


//	static ConstructorHelpers::FObjectFinder<USkeletalMesh> ChestMesh_0(TEXT("SkeletalMesh'/Game/Assets/Magician_Female_Chest_000'"));
//	SkelMesh->SetSkeletalMesh(ChestMesh_0);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> FaceMesh_0(TEXT("SkeletalMesh'/Game/Assets/Magician_Female_Face_000'"));
	FaceMesh->SetSkeletalMesh(FaceMesh_0.Object);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> HairMesh_0(TEXT("SkeletalMesh'/Game/Assets/Magician_Female_Hair_000'"));
	HairMesh->SetSkeletalMesh(HairMesh_0.Object);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> FootMesh_0(TEXT("SkeletalMesh'/Game/Assets/Magician_Female_Foot_000'"));
	FootMesh->SetSkeletalMesh(FootMesh_0.Object);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> HandMesh_0(TEXT("SkeletalMesh'/Game/Assets/Magician_Female_Hand_000'"));
	HandMesh->SetSkeletalMesh(HandMesh_0.Object);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> LegMesh_0(TEXT("SkeletalMesh'/Game/Assets/Magician_Female_Leg_000'"));
	LegMesh->SetSkeletalMesh(LegMesh_0.Object);

}

// Called when the game starts or when spawned
void AOverloadPawn::BeginPlay()
{
	Super::BeginPlay();

	UMagicianAnimInstance *AnimInst = Cast<UMagicianAnimInstance> (SkelMesh->GetAnimInstance()); 
	if (AnimInst) 
	{ 
		//AnimInst->Montage_Play(Montage); 
		//AnimInst->Attack();
	} 
}

// Called every frame
void AOverloadPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOverloadPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

