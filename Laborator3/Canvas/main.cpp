#include"Canvas.h"
#include <windows.h>

int main()
{
	Canvas myCanva(20, 20);
	myCanva.DrawCircle(4, 5, 6, '1');
	myCanva.FillCircle(10, 15, 4, '2');
	//myCanva.Clear();
	myCanva.DrawLine(1, 1, 7, 5, '3');
	myCanva.DrawRect(4, 4, 26, 26, '4');
	myCanva.FillRect(17, 18, 26, 26, '5');
	myCanva.Print();
	return 0;
}

