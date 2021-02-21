#include "PD_FunctionLibrary.h"


// Set default values in static variables
float	  UPD_FunctionLibrary::currentHP = 100.0f;
float	  UPD_FunctionLibrary::maxHP = 100.0f;
float     UPD_FunctionLibrary::currentStamina = 100.0f;
float	  UPD_FunctionLibrary::maxStamina = 100.0f;
int	      UPD_FunctionLibrary::currentXP = 0;
int       UPD_FunctionLibrary::maxXP = 750;
float	  UPD_FunctionLibrary::upNextLevelXP = 1.1;
int       UPD_FunctionLibrary::currentLVL = 0;
int       UPD_FunctionLibrary::currentMoney = 0;
int	      UPD_FunctionLibrary::respectPoint = 0;
bool	  UPD_FunctionLibrary::isPlayerDie = false;

// Cheats variables
bool	  UPD_FunctionLibrary::isInfiniteHealth = false;
bool	  UPD_FunctionLibrary::isInfiniteStamina = false;


// Reset static variable on PIE (call in your Game Instance -> Event Init -> PD_Init())
void UPD_FunctionLibrary::PD_Init()
{
	currentHP = 100.0f;
	maxHP = 100.0f;
	currentStamina = 100.0f;
	maxStamina = 100.0f;
	currentXP = 0;
	maxXP = 750;
	upNextLevelXP = 1.1;
	currentLVL = 0;
	currentMoney = 0;
	respectPoint = 0;
	isPlayerDie = false;

	isInfiniteHealth = false;
	isInfiniteStamina = false;
}


/////////////// GET FUNCTIONS ///////////////

FText UPD_FunctionLibrary::PD_GetMessage(FText msg)
{
	return msg;
}

float UPD_FunctionLibrary::PD_GetCurrentHP()
{
	return currentHP;
}

float UPD_FunctionLibrary::PD_GetMaxHP()
{
	return maxHP;
}

float UPD_FunctionLibrary::PD_GetPercentageHP()
{
	return currentHP / maxHP;
}

float UPD_FunctionLibrary::PD_GetCurrentStamina()
{
	return currentStamina;
}

float UPD_FunctionLibrary::PD_GetMaxStamina()
{
	return maxStamina;
}

float UPD_FunctionLibrary::PD_GetPercentageStamina()
{
	return currentStamina / maxStamina;
}

int UPD_FunctionLibrary::PD_GetCurrentXP()
{
	return currentXP;
}

int UPD_FunctionLibrary::PD_GetMaxXP()
{
	return maxXP;
}

int UPD_FunctionLibrary::PD_GetRemainingXP()
{
	return maxXP - currentXP;
}

int UPD_FunctionLibrary::PD_GetCurrentLVL()
{
	return currentLVL;
}

int UPD_FunctionLibrary::PD_GetMoney() {
	return currentMoney;
}

int UPD_FunctionLibrary::PD_GetRespectPoint()
{
	return respectPoint;
}


/////////////// SET FUNCTIONS ///////////////

void UPD_FunctionLibrary::PD_SetCurrentHealth(float value)
{
	if (currentHP > maxHP) return;
	currentHP = value;
}

void UPD_FunctionLibrary::PD_SetMaxHealth(float value)
{
	if (maxHP < currentHP) return;
	maxHP = value;
}

void UPD_FunctionLibrary::PD_SetCurrentStamina(float value)
{
	if (currentStamina > maxStamina) return;
	currentStamina = value;
}

void UPD_FunctionLibrary::PD_SetMaxStamina(float value)
{
	if (maxStamina < currentStamina) return;
	maxStamina = value;
}

void UPD_FunctionLibrary::PD_SetCurrentXP(float value)
{
	currentXP = value;
}

void UPD_FunctionLibrary::PD_SetCurrentLVL(int value)
{
	currentLVL = value;
	for (int i = 0; i < value; i++) {
		maxXP *= upNextLevelXP;
	}
}

void UPD_FunctionLibrary::PD_SetMoney(int value) {
	currentMoney = value;
}

void UPD_FunctionLibrary::PD_SetRespectPoint(int value)
{
	respectPoint = value;
}


/////////////// CHANGE FUNCTIONS ///////////////

void UPD_FunctionLibrary::PD_AddHP(float value, bool isPercentDmg)
{
	if (!isPlayerDie)
	{
		if (isPercentDmg)
		{
			float addPercent = ((currentHP / maxHP) * value);
			currentHP += addPercent;
			if (currentHP >= maxHP) {
				currentHP = maxHP;
			}
			return;
		}
		currentHP += value;
		if (currentHP >= maxHP) {
			currentHP = maxHP;
		}
	}
}

void UPD_FunctionLibrary::PD_DamageHP(float value, bool isPercentDmg)
{
	if (!isPlayerDie)
	{
		if (isInfiniteHealth == false)
		{
			if (isPercentDmg)
			{
				float damagePercent = ((currentHP / maxHP) * value);
				currentHP -= damagePercent;
				if (currentHP <= 0) {
					currentHP = 0;
				}
				return;
			}
			currentHP -= value;
			if (currentHP <= 0) {
				currentHP = 0;
			}
		}
	}
}

void UPD_FunctionLibrary::PD_AddMaxHP(float value)
{
	if (!isPlayerDie)
	{
		maxHP += value;
		currentHP = maxHP;
	}
}

void UPD_FunctionLibrary::PD_RestoreAllHP()
{
	currentHP = maxHP;
}

void UPD_FunctionLibrary::PD_AddMaxStamina(float value) {
	if (!isPlayerDie)
	{
		maxStamina += value;
		currentStamina = maxStamina;
	}
}

void UPD_FunctionLibrary::PD_ChangeStamina(float value, bool isMinus)
{
	if (isInfiniteStamina == false) {
		if (isMinus) {
			currentStamina -= value;
		}
		else {
			currentStamina += value;
		}
	}
}

void UPD_FunctionLibrary::PD_RestoreAllStamina() {
	currentStamina = maxStamina;
}

void UPD_FunctionLibrary::PD_AddXP(int value)
{
	currentXP += value;
	if (currentXP >= maxXP)
	{
		currentXP -= maxXP;
		currentLVL++;
		maxXP = maxXP * upNextLevelXP;
	}
}

void UPD_FunctionLibrary::PD_AddMoney(int value) {
	currentMoney += value;
}

void UPD_FunctionLibrary::PD_ChangeRespectPoint(int value, bool isMinusPoint)
{
	if (!isMinusPoint)
	{
		respectPoint += value;
		return;
	}
	respectPoint -= value;
}


/////////////// STATE FUNCTIONS ///////////////

bool UPD_FunctionLibrary::PD_IsPlayerAlive()
{
	return currentHP > 0 ? true : false;
}

bool UPD_FunctionLibrary::PD_IsTrueEnding()
{
	return respectPoint > 0 ? true : false; // Return true ending game or quest
}


/////////////// CHEAT-MENU ///////////////

void UPD_FunctionLibrary::PD_CM_InfiniteHealth(bool isEnable) {
	if (isEnable) {
		PD_RestoreAllHP();
	}
	isInfiniteHealth = isEnable;
}

void UPD_FunctionLibrary::PD_CM_InfiniteStamina(bool isEnable) {
	if (isEnable) {
		PD_RestoreAllStamina();
	}
	isInfiniteHealth = isEnable;

}
