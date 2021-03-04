#include"Math.h"

int main()
{
	Math math;
	printf("Suma 5 + 1: %d\n", math.Add(5, 1));
	printf("Suma 5 + 1 + 2: %d\n", math.Add(5, 1, 2));

	printf("Suma 4.3 + 1.2: %d\n", math.Add(4.3, 1.2));
	printf("Suma 1.7 + 1.8 + 2.2: %d\n", math.Add(1.7, 1.8, 2.2));

	printf("Inmultire 5 * 1: %d\n", math.Mul(5, 1));
	printf("Inmultire 5 * 1 * 2: %d\n", math.Mul(5, 1, 2));

	printf("Inmultire 4.3 * 1.2: %d\n", math.Mul(4.3, 1.2));
	printf("Inmultire 1.7 * 1.8 * 2.2: %d\n", math.Mul(1.7, 1.8, 2.2));

	printf("Suma a n numere: %d\n", math.Add(5, 1, 21, 33, 9, 7));

	printf("Concatenarea: %s\n", math.Add("Buna", " Ziua"));
}