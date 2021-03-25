#pragma once
#include "Car.h"
class Toyota : public Car {
public:
	Toyota();
	~Toyota();
	void SetAverageSpeedRain(int val) override;
	void SetAverageSpeedSnow(int val) override;
	void SetAverageSpeedSunny(int val) override;
	void SetFuelCapacity(int val) override;
	void SetFuelConsumption(int val) override;
	int GetFuelCapacity();
	int GetFuelConsumption();
	int GetAverageSpeedRain();
	int GetAverageSpeedSunny();
	int GetAverageSpeedSnow();
}; 
