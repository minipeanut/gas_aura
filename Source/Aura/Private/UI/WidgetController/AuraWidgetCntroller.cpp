// Copyright chen.


#include "UI/WidgetController/AuraWidgetCntroller.h"

void UAuraWidgetCntroller::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AttributeSet = WCParams.AttributeSet;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
}

void UAuraWidgetCntroller::BroadcastInitialValues()
{
}

void UAuraWidgetCntroller::BindCallBacksToDependencies()
{
}
