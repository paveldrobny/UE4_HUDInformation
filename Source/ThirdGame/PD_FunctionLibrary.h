// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PD_FunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class THIRDGAME_API UPD_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		static float        currentHP;
	static float	    maxHP;
	static float	    currentStamina;
	static float	    maxStamina;
	static int	        currentXP;
	static int          maxXP;
	static float        upNextLevelXP;
	static int	        currentLVL;
	static int          currentMoney;
	static int	        respectPoint;
	static bool	        isPlayerDie;

	// Cheats variables
	static bool         isInfiniteHealth;
	static bool         isInfiniteStamina;


		UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_Init();


	/////////////// GET FUNCTIONS ///////////////

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static FText PD_GetMessage(FText msg);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static float PD_GetCurrentHP();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static float PD_GetMaxHP();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static float PD_GetPercentageHP();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static float PD_GetCurrentStamina();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static float PD_GetMaxStamina();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static float PD_GetPercentageStamina();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static int PD_GetCurrentXP();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static int PD_GetMaxXP();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static int PD_GetRemainingXP();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static int PD_GetCurrentLVL();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static int PD_GetMoney();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static int PD_GetRespectPoint();


	/////////////// SET FUNCTIONS ///////////////

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void  PD_SetCurrentHealth(float value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void  PD_SetMaxHealth(float value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_SetCurrentStamina(float value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_SetMaxStamina(float value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_SetCurrentXP(float value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_SetCurrentLVL(int value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_SetMoney(int value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_SetRespectPoint(int value);


	/////////////// CHANGE FUNCTIONS (TEST) ///////////////

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_AddHP(float value, bool isPercentDmg);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_DamageHP(float value, bool isPercentDmg);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_AddMaxHP(float value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_RestoreAllHP();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_ChangeStamina(float value, bool isMinus);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_AddMaxStamina(float value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_RestoreAllStamina();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_AddXP(int value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_AddMoney(int value);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_ChangeRespectPoint(int value, bool isMinusPoint);


	/////////////// STATE FUNCTIONS ///////////////

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static bool PD_IsPlayerAlive();

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static bool PD_IsTrueEnding();


	/////////////// CHEAT-MENU ///////////////

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_CM_InfiniteHealth(bool isEnable);

	UFUNCTION(BlueprintCallable, Category = "PD_BP_Library")
		static void PD_CM_InfiniteStamina(bool isEnable);
};
