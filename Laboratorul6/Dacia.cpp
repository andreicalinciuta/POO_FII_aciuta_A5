#include "Dacia.h"
#include<stdio.h>
#include <string.h>


void Dacia::SetAverageSpeedRain(int val)
{
	this->average_speed_rain = val;
}
void Dacia::SetAverageSpeedSnow(int val)
{
	this->average_speed_snow = val;
}
void Dacia::SetAverageSpeedSunny(int val)
{
	this->average_speed_sunny = val;
}
void Dacia::SetFuelCapacity(int val)
{
	this->fuel_capacity = val;
}
void Dacia::SetFuelConsumption(int val)
{
	this->fuel_consumption = val;
}
int Dacia::GetFuelCapacity()
{
	return fuel_capacity;
}
int Dacia::GetFuelConsumption()
{
	return fuel_consumption;
}
int Dacia::GetAverageSpeedRain()
{
	return average_speed_rain;
}
int Dacia::GetAverageSpeedSunny()
{
	return average_speed_sunny;
}
int Dacia::GetAverageSpeedSnow()
{
	return average_speed_snow;
}

Dacia::Dacia()
{
	this->name = (char*)"Dacia";
	SetAverageSpeedRain(60);
	SetAverageSpeedSnow(40);
	SetAverageSpeedSunny(140);
	SetFuelCapacity(150);
	SetFuelConsumption(8);
	printf("Dacia a intrat pe pista!\n");
}
Dacia::~Dacia()
{
	printf("Dacia a fost descalificata!!\n");
}
