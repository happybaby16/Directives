#include <stdio.h>
#include <math.h>

#define PI 3.14F

#define POW(a) pow(a,2)
#define lenLine(x1, y1, x2, y2) sqrt(POW(x2 - x1)+POW(y2 - y1))


struct Triangle
{
	float P;
	float S;
};

struct Triangle SP(int x1, int y1, int x2, int y2, int x3, int y3)
{
	struct Triangle answer = { -1,-1 };
	if (((x3-x1)/(x2-x1))==((y3-y1)/(y2-y1)))
	{
		return answer;
	}

	float P = lenLine(x1, y1, x2, y2) + lenLine(x2, y2, x3, y3) + lenLine(x3, y3, x1, y1);
	float p = P / 2;
	float S = sqrt(p * (p - lenLine(x1, y1, x2, y2)) * (p - lenLine(x2, y2, x3, y3)) * (p - lenLine(x3, y3, x1, y1)));
	answer.P = P;
	answer.S = S;
	return answer;

}



int main()
{
	float* p = malloc(sizeof(float));

	float x1, x2, y1, y2,x3,y3;
	float len;

	int switch_on;
	printf("¬ведите действие (1 - задание 1, 2 - задание 2, 3 - задание 3): ");
	scanf_s("%i", &switch_on);


	switch (switch_on)
	{
	case 1:
		printf("\ndefine PI = %f", PI);
		printf("\n¬ведите новое значение константы: ");
		scanf_s("%f", p);
#define PI *p
		printf("\ndefine PI = %f", PI);
		break;
	case 2:
		printf("\n¬ведите x1: ");
		scanf_s("%f", &x1);
		printf("\n¬ведите y1: ");
		scanf_s("%f", &y1);
		printf("\n¬ведите x2: ");
		scanf_s("%f", &x2);
		printf("\n¬ведите y2: ");
		scanf_s("%f", &y2);
		printf("ƒлина отрезка равна: %f", lenLine(x1, y1, x2, y2));
		break;

	case 3:
		printf("\n¬ведите x1: ");
		scanf_s("%f", &x1);
		printf("\n¬ведите y1: ");
		scanf_s("%f", &y1);
		printf("\n¬ведите x2: ");
		scanf_s("%f", &x2);
		printf("\n¬ведите y2: ");
		scanf_s("%f", &y2);
		printf("\n¬ведите x3: ");
		scanf_s("%f", &x3);
		printf("\n¬ведите y3: ");
		scanf_s("%f", &y3);
		struct Triangle an = SP(x1,y1,x2,y2,x3,y3);
		printf("\nќтвет от функции без директив: P = %f, S = %f", an.P, an.S);
		break;
	}
	


	return 0;
}