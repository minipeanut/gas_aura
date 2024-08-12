// Copyright chen.


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/OverlayWidgetCntroller.h"

UOverlayWidgetCntroller* AAuraHUD::GetUOverlayWidgetCntroller(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetCntroller == nullptr)
	{
		OverlayWidgetCntroller = NewObject<UOverlayWidgetCntroller>(this, OverlayWidgetCntrollerClass);
		OverlayWidgetCntroller->SetWidgetControllerParams(WCParams);
		OverlayWidgetCntroller->BindCallBacksToDependencies();
		return OverlayWidgetCntroller;
	}
	return OverlayWidgetCntroller;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetCntrollerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"));
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	// at this point the widget controller does have a valid attribute set
	UOverlayWidgetCntroller* WidgetCntroller = GetUOverlayWidgetCntroller(WidgetControllerParams);
	
	// and at this point our overlay widget has its widget controller set, which means that widget controller
	// set blueprint event will be called  at this point, that's where we can do those things like
	// bind to the widget controllers delegates, only after this has happened
	// should we tell the widget controller to broadcast its initial values
	OverlayWidget->SetWidgetController(WidgetCntroller);
	WidgetCntroller->BroadcastInitialValues();
	Widget->AddToViewport();
}

