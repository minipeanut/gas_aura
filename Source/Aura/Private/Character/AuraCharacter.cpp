// Copyright chen.


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	// force character move above the plane
	GetCharacterMovement()->bConstrainToPlane = true;
	// 对齐到平面
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

    // 俯仰
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	// 偏航
	bUseControllerRotationYaw = false;
}
