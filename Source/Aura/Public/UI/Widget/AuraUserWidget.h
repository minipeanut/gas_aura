// Copyright chen.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	// 用于自动生成一些代码，比如构造函数、序列化函数等。这个宏是由Unreal Engine的代码生成工具在编译时自动填充的。
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	// 是一个模板类，用于安全地持有UObject指针，它可以自动处理引用计数。
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();  // 表示这个函数是一个蓝图可实现的函数事件，可以在蓝图编辑器中被重写和实现。
};
