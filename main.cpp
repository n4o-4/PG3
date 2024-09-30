#include <stdio.h>
#include <iostream>

template <typename T1, typename T2>

void Min(T1 a, T2 b) {

	if (typeid(a) == typeid(char) || typeid(b) == typeid(char)) {

		printf("数字以外は代入できません\n");
		
		return;
	}

	if (a > b) {
		
		if (typeid(b) == typeid(int))
		{
			printf("%d\n", b);

			return;
		}
		else if (typeid(b) == typeid(float))
		{
			printf("%f\n", b);

			return;
		}
		else
		{
			printf("%lf\n", b);

			return;
		}
	}


	else if (a < b) {

		if (typeid(a) == typeid(int))
		{
			printf("%d\n", a);

			return;
		}
		else if (typeid(a) == typeid(float))
		{
			printf("%f\n", a);

			return;
		}
		else
		{
			printf("%lf\n", a);

			return;
		}
	}

	else
	{
		printf("同じ値です\n");
	}
}

int comparison(int normalSalary, int SpecialSalary,int totalNS , int totalSS, int timeH) {

	timeH++;

	if (timeH == 1)
	{
		SpecialSalary = 100;

		printf("一般的な賃金体系 : 再帰的な賃金体系\n");
	}
	else
	{
		SpecialSalary = SpecialSalary * 2 - 50;
	}

	totalNS += normalSalary;

	totalSS += SpecialSalary;

	printf("%d : %d\n", totalNS, totalSS);

	if (totalNS < totalSS) {
		return timeH;
	}
	else
	{
		comparison(normalSalary, SpecialSalary, totalNS, totalSS, timeH);
	}
}

int main() {

	printf("%d", comparison(1072,0,0,0,0));

	return 0;
}