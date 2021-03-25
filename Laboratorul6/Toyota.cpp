#include "Toyota.h"
#include<stdio.h>
#include <string.h>


void Toyota::SetAverageSpeedRain(int val)
{
	this->average_speed_rain = val;
}
void Toyota::SetAverageSpeedSnow(int val)
{
	this->average_speed_snow = val;
}
void Toyota::SetAverageSpeedSunny(int val)
{
	this->average_speed_sunny = val;
}
void Toyota::SetFuelCapacity(int val)
{
	this->fuel_capacity = val;
}
void Toyota::SetFuelConsumption(int val)
{
	this->fuel_consumption = val;
}
int Toyota::GetFuelCapacity()
{
	return fuel_capacity;
}
int Toyota::GetFuelConsumption()
{
	return fuel_consumption;
}
int Toyota::GetAverageSpeedRain()
{
	return average_speed_rain;
}
int Toyota::GetAverageSpeedSunny()
{
	return average_speed_sunny;
}
int Toyota::GetAverageSpeedSnow()
{
	return average_speed_snow;
}


Toyota::Toyota()
{
	printf("Toyota a intrat pe pista!!\n");
	this->name = (char*)"Toyota";
	SetAverageSpeedRain(88);
	SetAverageSpeedSnow(44);
	SetAverageSpeedSunny(132);
	SetFuelCapacity(550);
	SetFuelConsumption(68);
}
Toyota::~Toyota()
{
	printf("Toyota a fost descalificata!!\n");
}
