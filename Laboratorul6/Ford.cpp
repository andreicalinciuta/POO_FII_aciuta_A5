#include "Ford.h"
#include<stdio.h>
#include <string.h>


void Ford::SetAverageSpeedRain(int val)
{
	this->average_speed_rain = val;
}
void Ford::SetAverageSpeedSnow(int val)
{
	this->average_speed_snow = val;
}
void Ford::SetAverageSpeedSunny(int val)
{
	this->average_speed_sunny = val;
}
void Ford::SetFuelCapacity(int val)
{
	this->fuel_capacity = val;
}
void Ford::SetFuelConsumption(int val)
{
	this->fuel_consumption = val;
}
int Ford::GetFuelCapacity()
{
	return fuel_capacity;
}
int Ford::GetFuelConsumption()
{
	return fuel_consumption;
}
int Ford::GetAverageSpeedRain()
{
	return average_speed_rain;
}
int Ford::GetAverageSpeedSunny()
{
	return average_speed_sunny;
}
int Ford::GetAverageSpeedSnow()
{
	return average_speed_snow;
}


Ford::Ford()
{
	printf("Ford a intrat pe pista!\n");
	this->name = (char*)"Ford";
	SetAverageSpeedRain(70);
	SetAverageSpeedSnow(70);
	SetAverageSpeedSunny(130);
	SetFuelCapacity(200);
	SetFuelConsumption(65);
}
Ford::~Ford()
{
	printf("Ford a fost descalificata!!\n");
}
