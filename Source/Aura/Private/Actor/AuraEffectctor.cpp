// Copyright chen.


#include "Actor/AuraEffectctor.h"

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

void AAuraEffectctor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
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


