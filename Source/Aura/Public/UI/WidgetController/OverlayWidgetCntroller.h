// Copyright chen.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetCntroller.h"
#include "OverlayWidgetCntroller.generated.h"

// 声明了一个名为FOnHealthChangedSignature的动态多播委托。这个委托可以携带一个参数，类型为float，代表新的健康值NewHealth。当角色的健康值发生变化时，可以广播这个委托，通知所有注册了这个委托的函数。
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetCntroller : public UAuraWidgetCntroller
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallBacksToDependencies() override;

	// UPROPERTY：这是一个宏，用于声明一个属性，这样它就可以被虚幻引擎的反射系统所识别。这意味着该属性可以被序列化（保存和加载），可以在蓝图编辑器中访问，并且可以用于其他反射相关的功能。
	// BlueprintAssignable：这是一个属性标记，表示这个委托可以在蓝图编辑器中被设置为另一个委托或函数。这允许蓝图作者能够将事件或函数绑定到这个委托上，从而在C++代码中的委托被触发时执行相应的蓝图逻辑。
	// Category="GAS|Attributes"：这是对属性进行分类的一个标记。在蓝图编辑器中，属性会按照指定的类别进行分组，这样可以帮助用户更容易地找到和编辑特定的属性。
	// 在这里，"GAS|Attributes"可能表示这是属于Gameplay Ability System (GAS)框架的属性类别。
	// FOnHealthChangedSignature OnHealthChanged;：这是委托成员变量的声明。FOnHealthChangedSignature是之前使用DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam宏声明的委托类型，
	// 它携带一个float类型的参数，表示新的健康值。OnHealthChanged是这个委托变量的名称，它可以在C++代码中被触发，也可以在蓝图中被其他函数所绑定。
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;


	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;
protected:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;

	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
};
