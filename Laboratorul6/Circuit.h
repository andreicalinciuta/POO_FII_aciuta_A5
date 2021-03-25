#pragma once
#include"Car.h"
#include"Weather.h"
#include<cstdlib>



class Circuit
{
private: 
	int length;
	int cars_on_race;
	int* rank;
	Weather wether_now;
	Car** cars;

public:
	Circuit();
	~Circuit();
	void SetLength(int val);
	void SetWeather(Weather op);
	void AddCar(Car* obj);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};