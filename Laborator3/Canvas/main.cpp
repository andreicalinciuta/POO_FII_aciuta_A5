#include"Canvas.h"
#include <windows.h>

#define WAIT 1000

void pause()
{
	Sleep(WAIT);
	system("cls");
}

int main()
{
	Canvas myCanva(20, 20);
	myCanva.DrawCircle(4, 5, 6, '1');
	myCanva.Print();
	pause();
	myCanva.FillCircle(10, 15, 4, '2');
	myCanva.Print();
	pause();
	myCanva.DrawLine(1, 1, 7, 5, '3');
	myCanva.Print();
	pause();
	myCanva.DrawRect(4, 4, 26, 26, '4');
	myCanva.Print();
	pause();
	myCanva.FillRect(17, 18, 26, 26, '5');
	myCanva.Print();
	pause();
	myCanva.Clear();
	myCanva.Print();
	pause();
	return 0;
}

