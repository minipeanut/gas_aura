// Copyright chen.


#include "UI/WidgetController/OverlayWidgetCntroller.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetCntroller::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
}

void UOverlayWidgetCntroller::BindCallBacksToDependencies()
{
	// bind a callback to delegate that's broadcast whenever attributes change
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetCntroller::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetCntroller::MaxHealthChanged);
}

void UOverlayWidgetCntroller::HealthChanged(const FOnAttributeChangeData& Data) const
{
	// 
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetCntroller::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
