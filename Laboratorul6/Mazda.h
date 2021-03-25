#pragma once
#include "Car.h"
class Mazda : public Car {
public:
	Mazda();
	~Mazda();
	void SetAverageSpeedRain(int val) override;
	void SetAverageSpeedSnow(int val) override;
	void SetAverageSpeedSunny(int val) override;
	void SetFuelCapacity(int val) override;
	void SetFuelConsumption(int val) override;

	int GetFuelCapacity() override;
	int GetFuelConsumption() override;
	int GetAverageSpeedRain() override;
	int GetAverageSpeedSunny() override;
	int GetAverageSpeedSnow() override;
};