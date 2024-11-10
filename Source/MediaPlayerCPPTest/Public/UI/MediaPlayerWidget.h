// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <functional>
#include "MediaAssets/Public/MediaPlayer.h"
#include "MediaPlayerWidget.generated.h"

class UMediaPlayer;
/**
 * 
 */
UCLASS()
class MEDIAPLAYERCPPTEST_API UMediaPlayerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MediaPlayerWidget")
	void Init(UMediaPlayer* Player, UMediaSource*& Source );

	UFUNCTION(BlueprintCallable, Category="MediaPlayerWidget")
	bool PlayVideo();

	void BindVideoReachEndEvent(std::function<void()> Callback);
	
private:
	std::function<void()> OnVideoReachEndCallback;
	UMediaPlayer* MediaPlayer;
	UMediaSource* MediaSource;
	UFUNCTION()
	void ReachVideoEnd();	
};



