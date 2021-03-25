#include "Mercedes.h"
#include<stdio.h>
#include <string.h>


void Mercedes::SetAverageSpeedRain(int val)
{
	this->average_speed_rain = val;
}
void Mercedes::SetAverageSpeedSnow(int val)
{
	this->average_speed_snow = val;
}
void Mercedes::SetAverageSpeedSunny(int val)
{
	this->average_speed_sunny = val;
}
void Mercedes::SetFuelCapacity(int val)
{
	this->fuel_capacity = val;
}
void Mercedes::SetFuelConsumption(int val)
{
	this->fuel_consumption = val;
}
int Mercedes::GetFuelCapacity()
{
	return fuel_capacity;
}
int Mercedes::GetFuelConsumption()
{
	return fuel_consumption;
}
int Mercedes::GetAverageSpeedRain()
{
	return average_speed_rain;
}
int Mercedes::GetAverageSpeedSunny()
{
	return average_speed_sunny;
}
int Mercedes::GetAverageSpeedSnow()
{
	return average_speed_snow;
}

Mercedes::Mercedes()
{
	printf("Mercedes a intrat pe pista!\n");
	this->name = (char*)"Mercedes";
	SetAverageSpeedRain(100);
	SetAverageSpeedSnow(60);
	SetAverageSpeedSunny(180);
	SetFuelCapacity(350);
	SetFuelConsumption(76);
}
Mercedes::~Mercedes()
{
	printf("Mercedes a fost descalificata!!\n");
}
