#pragma once

class Car {

protected:
	int fuel_capacity;
	int fuel_consumption;
	int average_speed_rain;
	int average_speed_sunny;
	int average_speed_snow;
	virtual void SetFuelCapacity(int val) = 0;
	virtual void SetFuelConsumption(int val) = 0;
	virtual void SetAverageSpeedRain(int val) = 0;
	virtual void SetAverageSpeedSunny(int val) = 0;
	virtual void SetAverageSpeedSnow(int val) = 0;
public:
	char* name;
	int hoursT, minutesT;
	bool finish;
	virtual int GetFuelCapacity() = 0;
	virtual int GetFuelConsumption() = 0;
	virtual int GetAverageSpeedRain() = 0;
	virtual int GetAverageSpeedSunny() = 0;
	virtual int GetAverageSpeedSnow() = 0;

};