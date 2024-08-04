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
	UOverlayWidgetCntroller* WidgetCntroller = GetUOverlayWidgetCntroller(WidgetControllerParams);
	OverlayWidget->SetWidgetController(WidgetCntroller);
	Widget->AddToViewport();
}

