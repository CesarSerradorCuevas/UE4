// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"





UCLASS()
class CPPTCP420_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	UFUNCTION()
		void btnON();

	UFUNCTION()
		void btnOFF();

	UFUNCTION()
		void sliderBegin();

	UFUNCTION()
		void sliderEnd();

	UFUNCTION()
		void sliderChange(float val);

	UFUNCTION()
		void sendUDP();

	UFUNCTION()
		void sendUDPbuilder();

	UFUNCTION()
		void listenTCP();

	UFUNCTION()
		void listenUDPlambda();

	UFUNCTION()
		void listenUDPstatic();


	FSocket* Socket;

	
private:
	UPROPERTY(meta = (BindWidget))
		class UButton* ButtonON;

	UPROPERTY(meta = (BindWidget))
		class UButton* ButtonOFF;

	UPROPERTY(meta = (BindWidget))
		class USlider* SliderX;

	UPROPERTY(meta = (BindWidget))
		class UButton* UdpButtonON;

	UPROPERTY(meta = (BindWidget))
		class UButton* UdpButtonOFF;


	
};
