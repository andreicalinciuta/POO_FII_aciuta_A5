#define WAIT 100

#include<stdio.h>
#include <Windows.h>
#include"Circuit.h"
#include"Car.h"
#include"Dacia.h"
#include"Toyota.h"
#include"Mercedes.h"
#include"Ford.h"
#include"Mazda.h"
#include"Weather.h"


void pause()
{
	Sleep(WAIT);
	system("cls");
}

int main()
{
	Circuit c;
	c.SetLength(100);
	pause();
	c.SetWeather(Weather::Rain);
	pause();
	c.AddCar(new Dacia());
	pause();
	c.AddCar(new Toyota());
	pause();
	c.AddCar(new Mercedes());
	pause();
	c.AddCar(new Ford());
	pause();
	c.AddCar(new Mazda());
	pause();
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}