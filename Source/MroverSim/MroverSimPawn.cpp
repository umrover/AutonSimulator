// Copyright Epic Games, Inc. All Rights Reserved.

#include "MroverSimPawn.h"
#include "MroverSimWheelFront.h"
#include "MroverSimWheelRear.h"
#include "MroverSimHud.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/TextRenderComponent.h"
#include "Materials/Material.h"
#include "GameFramework/Controller.h"

#ifndef HMD_MODULE_INCLUDED
#define HMD_MODULE_INCLUDED 0
#endif

// Needed for VR Headset
#if HMD_MODULE_INCLUDED
#include "IXRTrackingSystem.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#endif // HMD_MODULE_INCLUDED

const FName AMroverSimPawn::LookUpBinding("LookUp");
const FName AMroverSimPawn::LookRightBinding("LookRight");

#define LOCTEXT_NAMESPACE "VehiclePawn"

AMroverSimPawn::AMroverSimPawn(const class FObjectInitializer& PCIP) :
 Super(PCIP.SetDefaultSubobjectClass<USimpleWheeledVehicleMovementComponent>(AWheeledVehicle::VehicleMovementComponentName))
{
	// Car mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CarMesh(TEXT("/Game/Vehicle/Rover/Complete_Rover.Complete_Rover"));
	GetMesh()->SetSkeletalMesh(CarMesh.Object);

	static ConstructorHelpers::FClassFinder<UObject> AnimBPClass(TEXT("/Game/Vehicle/Rover/Complete_Rover_Skeleton_AnimBlueprint"));
	GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);

	// Simulation
	VehicleSimple = CastChecked<USimpleWheeledVehicleMovementComponent>(GetVehicleMovement());

	VehicleSimple->WheelSetups.SetNum(4);

	VehicleSimple->WheelSetups[0].WheelClass = UMroverSimWheelFront::StaticClass();
	VehicleSimple->WheelSetups[0].BoneName = FName("Wheel_Front_Left");
	VehicleSimple->WheelSetups[0].AdditionalOffset = FVector(0.f, -12.f, 0.f);

	VehicleSimple->WheelSetups[1].WheelClass = UMroverSimWheelFront::StaticClass();
	VehicleSimple->WheelSetups[1].BoneName = FName("Wheel_Front_Right");
	VehicleSimple->WheelSetups[1].AdditionalOffset = FVector(0.f, 12.f, 0.f);

	VehicleSimple->WheelSetups[2].WheelClass = UMroverSimWheelRear::StaticClass();
	VehicleSimple->WheelSetups[2].BoneName = FName("Wheel_Rear_Left");
	VehicleSimple->WheelSetups[2].AdditionalOffset = FVector(0.f, -12.f, 0.f);

	VehicleSimple->WheelSetups[3].WheelClass = UMroverSimWheelRear::StaticClass();
	VehicleSimple->WheelSetups[3].BoneName = FName("Wheel_Rear_Right");
	VehicleSimple->WheelSetups[3].AdditionalOffset = FVector(0.f, 12.f, 0.f);

	// Create a spring arm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->TargetOffset = FVector(0.f, 0.f, 200.f);
	SpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 600.0f;
	SpringArm->bEnableCameraRotationLag = true;
	SpringArm->CameraRotationLagSpeed = 7.f;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;

	// Create camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
	Camera->FieldOfView = 90.f;
}
	void AMroverSimPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveForward", IE_Pressed, this, &AMroverSimPawn::MoveForward);
	PlayerInputComponent->BindAction("MoveForward", IE_Released, this, &AMroverSimPawn::ResetWheelTorque);
	PlayerInputComponent->BindAction("MoveBackward", IE_Pressed, this, &AMroverSimPawn::MoveBackward);
	PlayerInputComponent->BindAction("MoveBackward", IE_Released, this, &AMroverSimPawn::ResetWheelTorque);
	PlayerInputComponent->BindAction("TurnRight", IE_Pressed, this, &AMroverSimPawn::TurnRight);
	PlayerInputComponent->BindAction("TurnRight", IE_Released, this, &AMroverSimPawn::ResetWheelTorque);
	PlayerInputComponent->BindAction("TurnLeft", IE_Pressed, this, &AMroverSimPawn::TurnLeft);
	PlayerInputComponent->BindAction("TurnLeft", IE_Released, this, &AMroverSimPawn::ResetWheelTorque);
}

void AMroverSimPawn::MoveForward()
{
	VehicleSimple->SetDriveTorque(600,FRONT_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(600,FRONT_RIGHT_WHEEL);
	VehicleSimple->SetDriveTorque(600,BACK_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(600,BACK_RIGHT_WHEEL);
}

void AMroverSimPawn::MoveBackward()
{
	VehicleSimple->SetDriveTorque(-600,FRONT_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(-600,FRONT_RIGHT_WHEEL);
	VehicleSimple->SetDriveTorque(-600,BACK_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(-600,BACK_RIGHT_WHEEL);
}

void AMroverSimPawn::TurnRight()
{
	VehicleSimple->SetDriveTorque(600,FRONT_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(-600,FRONT_RIGHT_WHEEL);
	VehicleSimple->SetDriveTorque(600,BACK_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(-600,BACK_RIGHT_WHEEL);
}

void AMroverSimPawn::TurnLeft()
{
	VehicleSimple->SetDriveTorque(-600,FRONT_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(600,FRONT_RIGHT_WHEEL);
	VehicleSimple->SetDriveTorque(-600,BACK_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(600,BACK_RIGHT_WHEEL);
}

void AMroverSimPawn::ResetWheelTorque()
{
	VehicleSimple->SetDriveTorque(0,FRONT_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(0,FRONT_RIGHT_WHEEL);
	VehicleSimple->SetDriveTorque(0,BACK_LEFT_WHEEL);
	VehicleSimple->SetDriveTorque(0,BACK_RIGHT_WHEEL);
}

void AMroverSimPawn::Tick(float Delta)
{
	Super::Tick(Delta);
	
	// Update the strings used in the hud (incar and onscreen)
	UpdateHUDStrings();

	bool bHMDActive = false;
#if HMD_MODULE_INCLUDED
	if ((GEngine->XRSystem.IsValid() == true) && ((GEngine->XRSystem->IsHeadTrackingAllowed() == true) || (GEngine->IsStereoscopic3D() == true)))
	{
		bHMDActive = true;
	}
#endif // HMD_MODULE_INCLUDED
	if (bHMDActive == false)
	{
		if ( (InputComponent) && (bInCarCameraActive == true ))
		{
			FRotator HeadRotation = InternalCamera->GetRelativeRotation();
			HeadRotation.Pitch += InputComponent->GetAxisValue(LookUpBinding);
			HeadRotation.Yaw += InputComponent->GetAxisValue(LookRightBinding);
			InternalCamera->SetRelativeRotation(HeadRotation);
		}
	}
}

void AMroverSimPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AMroverSimPawn::UpdateHUDStrings()
{
	float KPH = FMath::Abs(GetVehicleMovement()->GetForwardSpeed()) * 0.036f;
	int32 KPH_int = FMath::FloorToInt(KPH);

	// Using FText because this is display text that should be localizable
	SpeedDisplayString = FText::Format(LOCTEXT("SpeedFormat", "{0} km/h"), FText::AsNumber(KPH_int));

	NavStateStatusDisplayString = FText::Format(LOCTEXT("NavStateFormat", "Navigation State: {0}"), FText::AsNumber(0));

	WaypointsDisplayString = FText::Format(LOCTEXT("WaypointsFormat", "Waypoints: {0}"), FText::AsNumber(0));

	JoystickTranslationalDisplayString = FText::Format(LOCTEXT("JoystickTranslationalFormat", "JoystickTranslational: {0}"), FText::AsNumber(0));

	JoystickRotationalDisplayString = FText::Format(LOCTEXT("JoystickRotationalFormat", "JoystickRotational: {0}"), FText::AsNumber(0));

	OdometryLatitudeDisplayString = FText::Format(LOCTEXT("OdometryLatitudeFormat", "OdometryLatitude: {0}"), FText::AsNumber(0));

	OdometryLongitudeDisplayString = FText::Format(LOCTEXT("OdometryLongitudeFormat", "OdometryLongitude: {0}"), FText::AsNumber(0));

	OdometryHeadingDisplayString = FText::Format(LOCTEXT("OdometryHeadingFormat", "OdometryHeading: {0}"), FText::AsNumber(0));

	ObstacleDistanceDisplayString = FText::Format(LOCTEXT("ObstacleDistanceFormat", "ObstacleDistance: {0}"), FText::AsNumber(0));

	ObstacleBearingDisplayString = FText::Format(LOCTEXT("ObstacleBearingFormat", "ObstacleBearing: {0}"), FText::AsNumber(0));

	RadioStrengthDisplayString = FText::Format(LOCTEXT("RadioStrengthFormat", "RadioStrength: {0}"), FText::AsNumber(0));

	TargetOneDistanceDisplayString = FText::Format(LOCTEXT("TargetOneDistanceFormat", "TargetOneDistance: {0}"), FText::AsNumber(0));

	TargetOneBearingDisplayString = FText::Format(LOCTEXT("TargetOneBearingFormat", "TargetOneBearing: {0}"), FText::AsNumber(0));

	TargetOneIDDisplayString = FText::Format(LOCTEXT("TargetOneIDFormat", "TargetOneID: {0}"), FText::AsNumber(0));

	TargetTwoDistanceDisplayString = FText::Format(LOCTEXT("TargetTwoDistanceFormat", "TargetTwoDistance: {0}"), FText::AsNumber(0));

	TargetTwoBearingDisplayString = FText::Format(LOCTEXT("TargetTwoBearingFormat", "TargetTwoBearing: {0}"), FText::AsNumber(0));

	TargetTwoIDDisplayString = FText::Format(LOCTEXT("TargetTwoIDFormat", "TargetTwoID: {0}"), FText::AsNumber(0));

	if (bInReverseGear == true)
	{
		GearDisplayString = FText(LOCTEXT("ReverseGear", "R"));
	}
	else
	{
		int32 Gear = GetVehicleMovement()->GetCurrentGear();
		GearDisplayString = (Gear == 0) ? LOCTEXT("N", "N") : FText::AsNumber(Gear);
	}	
}
#undef LOCTEXT_NAMESPACE
	