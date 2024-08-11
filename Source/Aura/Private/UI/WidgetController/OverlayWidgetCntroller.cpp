// Copyright chen.


#include "UI/WidgetController/OverlayWidgetCntroller.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetCntroller::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
}
