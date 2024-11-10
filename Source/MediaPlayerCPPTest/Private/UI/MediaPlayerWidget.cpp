// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MediaPlayerWidget.h"

void UMediaPlayerWidget::Init(UMediaPlayer* Player, UMediaSource*& Source)
{
	this->MediaPlayer = Player;
	this->MediaSource = Source;
	this->MediaPlayer->OnEndReached.AddDynamic(this, &UMediaPlayerWidget::ReachVideoEnd);
}

bool UMediaPlayerWidget::PlayVideo()
{
	return this->MediaPlayer->OpenSource(MediaSource);
}

void UMediaPlayerWidget::BindVideoReachEndEvent(std::function<void()> Callback)
{
	this->OnVideoReachEndCallback = Callback;
}

void UMediaPlayerWidget::ReachVideoEnd()
{
	if(!this->OnVideoReachEndCallback) return;

	this->OnVideoReachEndCallback();
}
