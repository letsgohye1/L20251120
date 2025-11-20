// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:

	UMyAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VALUE")
	float GroundSpeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VALUE")
	uint8 bSprint : 1;


	
};
