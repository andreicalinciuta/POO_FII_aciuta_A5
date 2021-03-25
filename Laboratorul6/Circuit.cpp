#include"Circuit.h"
#include <stdio.h>

Circuit::Circuit()
{
	this->cars_on_race = 0;
}

void Circuit::SetLength(int val)
{
	this->length = val;
	printf("Circuitul are %d km\n\n", val);
}

void Circuit::SetWeather(Weather op)
{
	this->wether_now = op;
	switch (op)
	{
	case Weather::Rain:
		printf("@===Cursa se tine pe ploaie!===@\n\n");
		break;
	case Weather::Sunny:
		printf("@===Vreamea e perfecta!===@\n\n");
		break;
	case Weather::Snow:
		printf("@===A inceput sa ninga!===@\n\n");
		break;
	default:
		break;
	}
}

void Circuit::AddCar(Car* obj)
{
	if (this->cars_on_race == 0)
	{
		this->cars = (Car**)malloc(sizeof(Car*));
	}
	else {
		this->cars = (Car**)realloc(this->cars, (this->cars_on_race + 1 )* sizeof(Car*));
	}
	this->cars[this->cars_on_race] = obj;
	this->cars_on_race++;

	printf("Pozitia %d \n\n", this->cars_on_race);

}
void Circuit::Race()
{
	printf("A inceput cursa!\n\n");
	int how_much_fuel_per_km;
	this->rank = (int *)malloc(this->cars_on_race * sizeof(int));
	for (int index = 0; index < this->cars_on_race; ++index)
	{
		this->rank[index] = index;

		if ((this->cars[index]->GetFuelConsumption()) * this->length / 100 > (this->cars[index]->GetFuelCapacity()))
		{
			(this->cars[index])->finish = false;
			(this->cars[index])->hoursT = 100;
			(this->cars[index])->minutesT = 58;
		}
		else
		{
			(this->cars[index])->finish = true;
			switch (this->wether_now)
			{
			case Weather::Rain:
				(this->cars[index])->hoursT = this->length / (this->cars[index])->GetAverageSpeedRain();
				(this->cars[index])->minutesT = (this->length % (this->cars[index])->GetAverageSpeedRain()) * 60 / (this->cars[index])->GetAverageSpeedRain();
				break;
			case Weather::Sunny:
				(this->cars[index])->hoursT = this->length / (this->cars[index])->GetAverageSpeedSunny();
				(this->cars[index])->minutesT = (this->length % (this->cars[index])->GetAverageSpeedSunny()) * 60 / (this->cars[index])->GetAverageSpeedSunny();
				break;
			case Weather::Snow:
				(this->cars[index])->hoursT = this->length / (this->cars[index])->GetAverageSpeedSnow();
				(this->cars[index])->minutesT = (this->length % (this->cars[index])->GetAverageSpeedSnow()) * 60 / (this->cars[index])->GetAverageSpeedSnow();
				break;
			default:
				break;
			}
		}
	}

	for (int index = 0; index < this->cars_on_race; ++index)
	{
		for (int index1 = index + 1; index1 < this->cars_on_race; ++index1)
		{
			if (this->cars[this->rank[index1]]->hoursT < this->cars[this->rank[index]]->hoursT ||
				(this->cars[this->rank[index1]]->hoursT == this->cars[this->rank[index]]->hoursT && this->cars[this->rank[index1]]->minutesT < this->cars[this->rank[index]]->minutesT))
			{
				int tmp = rank[index];
				rank[index] = rank[index1];
				rank[index1] = tmp;
			}
		}
	}
}
void Circuit::ShowFinalRanks()
{
	printf("     Clasamentul final:\n\n");
	for (int index = 0; index < this->cars_on_race; ++index)
	{
		if ((this->cars[this->rank[index]])->finish == true)
		{
			printf("%d. %s a terminat in %d ore si %d minute!\n", index + 1, (this->cars[this->rank[index]])->name, (this->cars[this->rank[index]])->hoursT, (this->cars[this->rank[index]])->minutesT);
		}
		if (index == 2)
			printf("\n");
	}
	printf("\n\n\n");
}
void Circuit::ShowWhoDidNotFinish()
{
	printf("    Nu au terminat cursa:\n\n");
	for (int index = 0; index < this->cars_on_race; ++index)
	{
		if ((this->cars[index])->finish == false)
		{
			printf("%s", (this->cars[index])->name);
		}
	}
	printf("\n\n\n");
}
Circuit::~Circuit()
{
	for (int index = 0; index < this->cars_on_race; ++index)
	{
		free(this->cars[index]);
	}
	free(this->cars);
	free(this->rank);
}
