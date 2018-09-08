// Fill out your copyright notice in the Description page of Project Settings.

#include "MyUserWidget.h"
#include "Engine/Engine.h"//
#include "Components/Button.h"//
#include "Components/Slider.h"
#include "Sockets.h"//
#include "Networking/Public/Networking.h"//




bool UMyUserWidget::Initialize()
{
	bool success = Super::Initialize();

	if (!success) return false;

	// Bind delegates here.
	if (!ensure(ButtonON != nullptr)) return false;
	ButtonON->OnClicked.AddDynamic(this, &UMyUserWidget::btnON);

	if (!ensure(ButtonOFF != nullptr)) return false;
	ButtonOFF->OnClicked.AddDynamic(this, &UMyUserWidget::btnOFF);

	if (!ensure(UdpButtonON != nullptr)) return false;
	UdpButtonON->OnClicked.AddDynamic(this, &UMyUserWidget::sendUDP);

	if (!ensure(UdpButtonOFF != nullptr)) return false;
	UdpButtonOFF->OnClicked.AddDynamic(this, &UMyUserWidget::sendUDPbuilder);

	if (!ensure(SliderX != nullptr)) return false;
	SliderX->OnMouseCaptureBegin.AddDynamic(this, &UMyUserWidget::sliderBegin);
	SliderX->OnMouseCaptureEnd.AddDynamic(this, &UMyUserWidget::sliderEnd);
	SliderX->OnValueChanged.AddDynamic(this, &UMyUserWidget::sliderChange);


	listenTCP();
	

	return true;
}




void UMyUserWidget::btnON() 
{
	FSocket* SocketTCP = nullptr;

	if (SocketTCP)
	{
		SocketTCP->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketTCP);
	}

	SocketTCP = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("SocketTCP"), false);
	FIPv4Address ip(192, 168, 1, 41);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(4015);

	bool connected = SocketTCP->Connect(*addr);

	FString serialized = "1";
	const TCHAR* xx = *serialized;
	int32 size = FCString::Strlen(xx);
	int32 sent = 0;

	bool successful = SocketTCP->Send((uint8*)xx, size, sent);

	SocketTCP->Close();

}

void UMyUserWidget::btnOFF() 
{
	FSocket* SocketTCP = nullptr;

	if (SocketTCP)
	{
		SocketTCP->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketTCP);
	}

	SocketTCP = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("SocketTCP"), false);
	FIPv4Address ip(192, 168, 1, 41);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(4015);

	bool connected = SocketTCP->Connect(*addr);

	FString serialized = "0";
	const TCHAR* xx = *serialized;
	int32 size = FCString::Strlen(xx);
	int32 sent = 0;

	bool successful = SocketTCP->Send((uint8*)xx, size, sent);

	SocketTCP->Close();

	
}

void UMyUserWidget::sliderBegin()
{
	UE_LOG(LogTemp, Warning, TEXT("BEGIN"));

}

void UMyUserWidget::sliderEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("END"));
	
}

void UMyUserWidget::sliderChange(float val)
{	
	int32 numx = FMath::TruncToInt(val * 250);
	FString strx = FString::FromInt(numx) + "\n";
	FString stra = FString::SanitizeFloat(val) + "\n";

	UE_LOG(LogTemp, Warning, TEXT("%s"), *strx);

	
	

}

void UMyUserWidget::sendUDP()
{
	FSocket* SocketUDP = nullptr;

	if (SocketUDP)
	{
		SocketUDP->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketUDP);
	}

	FIPv4Address ip(192, 168, 1, 33);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(4010);

	SocketUDP = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("SocketUDP"), true);

	FString name = "ON";
	FArrayWriter Writer;
	Writer << name;
	int32 bytesSent = 0;


	if (SocketUDP->Connect(*addr))
	{
		
		SocketUDP->Send(Writer.GetData(), Writer.Num(), bytesSent);
	
	}

	SocketUDP->Close();
	
}


void UMyUserWidget::sendUDPbuilder()
{
	FSocket* SocketUDP = nullptr;

	if (SocketUDP)
	{
		SocketUDP->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketUDP);
	}

	FIPv4Address ip(192, 168, 1, 33);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(4010);

	int32 BufferSize = 2 * 1024 * 1024;
	SocketUDP = FUdpSocketBuilder(TEXT("UDP Socket")).WithBroadcast().WithSendBufferSize(BufferSize).Build();
	
	FString name = "OFF";
	FArrayWriter Writer;
	Writer << name;
	int32 bytesSent = 0;	

	SocketUDP->SendTo(Writer.GetData(), Writer.Num(), bytesSent, *addr);	

	SocketUDP->Close();

}


bool onEnterClientTCP(FSocket* sock, const FIPv4Endpoint &addrs) {

	FString val = "NEW CLIENT!";
	GEngine->AddOnScreenDebugMessage(6, 5.f, FColor::Red, *val);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *val);

	uint8 ReceivedData[1024];
	int32 BufferSize = 1024;
	int32 BytesRead = 0;

	uint32 PendingDataSize = 0;

	bool areThereData = false;	

	sock->Wait(ESocketWaitConditions::WaitForRead, FTimespan::FromMilliseconds(100));

	if (sock->HasPendingData(PendingDataSize))
	{
		sock->Recv(ReceivedData, BufferSize, BytesRead);
		
		FString dataStr = BytesToString(ReceivedData, BytesRead);

		FString finalStr = "";

		//If we don't do this, for example, whether the client sends "Car", in our server will be printed "Dbs"
		for (int i = 0; i < dataStr.Len(); i++) {
			const TCHAR letter = dataStr[i] - 1;
			finalStr.AppendChar(letter);
		}

		UE_LOG(LogTemp, Warning, TEXT("Received Data string: %s"), *finalStr);
		FString dataNum = FString::FromInt(BytesRead);
		UE_LOG(LogTemp, Warning, TEXT("Received Data length: %s"), *dataNum);
	}
	
	return true;
}

void UMyUserWidget::listenTCP()
{
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}

	FIPv4Address ip(192, 168, 1, 33);

	FIPv4Endpoint EndPointA;
	EndPointA.Address = ip.Value;
	EndPointA.Port = 4015;

	Socket = FTcpSocketBuilder(TEXT("SocketTCP")).AsReusable().BoundToEndpoint(EndPointA).Listening(10);
		
	if (Socket != nullptr) {

		GEngine->AddOnScreenDebugMessage(5, 5.f, FColor::Red, TEXT("TCP Socket Created!"));
		
	}

	FTcpListener* listener = new FTcpListener(*Socket);
	listener->OnConnectionAccepted().BindStatic(&onEnterClientTCP);
	listener->Init();
}

void onEnterClientUDP(const FArrayReaderPtr & arrayRead, const FIPv4Endpoint & endPoint) 
{
	TArray<uint8> RawData;
	FString fixed;
	uint16 DataReceivedNum = arrayRead->Num();

	for (uint16 i = 0; i < DataReceivedNum; i++) 
	{ 
		RawData.Add(arrayRead->Pop()); 
	}

	FString result = BytesToString(RawData.GetData(), DataReceivedNum);

	for (int i = 0; i < result.Len(); i++) {
		const TCHAR c = result[i] - 1;
		fixed.AppendChar(c);
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *fixed.Reverse());
}


void UMyUserWidget::listenUDPstatic()
{
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}

	FIPv4Endpoint EndPointA(FIPv4Address(0, 0, 0, 0), 4015);


	Socket = FUdpSocketBuilder(TEXT("SocketUDP")).AsNonBlocking().AsReusable().WithReceiveBufferSize(1024).BoundToEndpoint(EndPointA).Build();

	FUdpSocketReceiver* receiver = new FUdpSocketReceiver(Socket, FTimespan::FromMilliseconds(1), TEXT("Receiver"));
	if (receiver)
	{
		receiver->OnDataReceived().BindStatic(&onEnterClientUDP);

		receiver->Start();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NOT RECEIVER"));
	}

}
	


void UMyUserWidget::listenUDPlambda()
{
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}

	FIPv4Endpoint EndPointA (FIPv4Address(0, 0, 0, 0), 4015);


	Socket = FUdpSocketBuilder(TEXT("SocketUDP")).AsNonBlocking().AsReusable().WithReceiveBufferSize(1024).BoundToEndpoint(EndPointA).Build();

	FUdpSocketReceiver* receiver = new FUdpSocketReceiver(Socket, FTimespan::FromMilliseconds(1), TEXT("Receiver"));
	if (receiver)
	{
		receiver->OnDataReceived().BindLambda([](const FArrayReaderPtr & arrayRead, const FIPv4Endpoint & endPoint) {
			TArray<uint8> RawData;
			FString fixed;
			uint16 DataReceivedNum = arrayRead->Num();

			for (uint16 i = 0; i < DataReceivedNum; i++)
			{
				RawData.Add(arrayRead->Pop());
			}

			FString result = BytesToString(RawData.GetData(), DataReceivedNum);

			for (int i = 0; i < result.Len(); i++) {
				const TCHAR c = result[i] - 1;
				fixed.AppendChar(c);
			}

			UE_LOG(LogTemp, Warning, TEXT("%s XYZ"), *fixed.Reverse());
		});

		receiver->Start();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NOT RECEIVER"));
	}
		
}


