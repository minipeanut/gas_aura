// Copyright chen.


#include "Actor/AuraEffectctor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AAuraEffectctor::AAuraEffectctor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	// so that once the mesh moves, the Sphere follows
	Sphere->SetupAttachment(GetRootComponent());
}
// OverlappedComponent是触发重叠的组件，
// OtherActor是与OverlappedComponent重叠的actor，
// OtherComp是OtherActor中的重叠组件，
// OtherBodyIndex是重叠的body索引，
// bFromSweep表示重叠是否来自一个sweep（线性移动检测），
// SweepResult包含了碰撞的详细信息。
void AAuraEffectctor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// todo change this to apply a gameplay effect, but for now using const_cast as a hack!
	// 当前实现是一个临时的解决方案（“hack”
	// 使用Cast函数来尝试将OtherActor转换为IAbilitySystemInterface类型。如果转换成功，表示OtherActor支持Ability System Component（游戏能力系统组件）
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		// 获取OtherActor的Ability System Component，并从中获取一个类型为UAuraAttributeSet的属性集。UAuraAttributeSet可能包含与健康值、法力值等相关的属性。
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		// 使用const_cast来移除AuraAttributeSet的const属性，以便能够修改它。这是一个不推荐的做法
		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() - 25.f);
		// 调用Destroy函数，它会销毁当前的AAuraEffectctor对象。这意味着这个actor在执行完这个函数后会被从世界中移除
		// Destroy函数的调用意味着AAuraEffectctor对象是一次性的，执行完重叠逻辑后就会被销毁
		Destroy();
	}
}

void AAuraEffectctor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void AAuraEffectctor::BeginPlay()
{
	Super::BeginPlay();
	// as this is a dynamic multicast delegate
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectctor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectctor::OnEndOverlap);
}


