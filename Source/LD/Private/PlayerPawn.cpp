// Fill out your copyright notice in the Description page of Project Settings.


#include "LD\Public\PlayerPawn.h"
#include "Components\StaticMeshComponent.h"
#include "Camera\CameraComponent.h"
#include "Components\InputComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretBase"));
	RootComponent = BoxComponent;

	TurretBodyComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretBodyComponent"));
	TurretBodyComponent->SetupAttachment(RootComponent);

	TurretCannonComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretCannonComponent"));
	TurretCannonComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*PlayerInputComponent->BindAxis("LookUp", this, &APlayerPawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerPawn::AddControllerYawInput);*/
}

void APlayerPawn::RotateTurretBodyYaw(float Value)
{
	FRotator NewRot = TurretBodyComponent->GetRelativeRotation();

	NewRot.Yaw += Value;
	TurretBodyComponent->SetRelativeRotation(NewRot);
}

void APlayerPawn::RotateCannonPitch(float Value)
{
	FRotator NewRot = TurretCannonComponent->GetRelativeRotation();

	NewRot.Pitch += Value;
	TurretCannonComponent->SetRelativeRotation(NewRot);
}

