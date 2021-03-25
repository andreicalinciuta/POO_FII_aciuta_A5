#include "Mazda.h"
#include<stdio.h>
#include <string.h>


void Mazda::SetAverageSpeedRain(int val)
{
	this->average_speed_rain = val;
}
void Mazda::SetAverageSpeedSnow(int val)
{
	this->average_speed_snow = val;
}
void Mazda::SetAverageSpeedSunny(int val)
{
	this->average_speed_sunny = val;
}
void Mazda::SetFuelCapacity(int val)
{
	this->fuel_capacity = val;
}
void Mazda::SetFuelConsumption(int val)
{
	this->fuel_consumption = val;
}
int Mazda::GetFuelCapacity()
{
	return fuel_capacity;
}
int Mazda::GetFuelConsumption()
{
	return fuel_consumption;
}
int Mazda::GetAverageSpeedRain()
{
	return average_speed_rain;
}
int Mazda::GetAverageSpeedSunny()
{
	return average_speed_sunny;
}
int Mazda::GetAverageSpeedSnow()
{
	return average_speed_snow;
}


Mazda::Mazda()
{
	printf("Mazda a intrat pe pista!\n");
	this->name = (char*)"Mazda";
	SetAverageSpeedRain(65);
	SetAverageSpeedSnow(30);
	SetAverageSpeedSunny(100);
	SetFuelCapacity(450);
	SetFuelConsumption(488);
}
Mazda::~Mazda()
{
	printf("Mazda a fost descalificata!!\n");
}
