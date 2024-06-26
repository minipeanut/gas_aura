// Copyright chen.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

#include "Layers/Layer.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	// 不将鼠标锁定到视口
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	// 一旦视口获取到鼠标，不会隐藏鼠标
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
