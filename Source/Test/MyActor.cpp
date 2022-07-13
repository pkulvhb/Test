// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMyActor::NotifyActorOnClicked(FKey ButtonPressed) 
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Click"));

	double NowTime = FDateTime::Now().GetTimeOfDay().GetTotalSeconds();

	// �Ƿ���˫�����Խ׶�
	if (IsInDoubleClickTest) {
		// ����Ѿ�����˫�����Խ׶Σ���Ƚϴ˿�����һ��������ǵ�ʱ����
		if (NowTime - LastClickTime < DoubleClickTestPadding) {
			//�������㹻С���ʹ���˫���¼����˳�˫�����Խ׶�
			OnDoubleClick();
			IsInDoubleClickTest = false;
		}
	}
	else {
		// ���������˫�����Խ׶Σ������˫�����Խ׶�
		IsInDoubleClickTest = true;
	}
	// ÿ�����������Ҫ��¼�����ʱ��
	LastClickTime = NowTime;
}

void AMyActor::OnDoubleClick()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("DoubleClick"));
}


void AMyActor::NotifyActorBeginCursorOver()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("BeginCursorOver"));
}

void AMyActor::NotifyActorEndCursorOver()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("EndCursorOver"));
}