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

int main() {

	Min<int, double>(10, 9.0);

	Min<char, int>('a', 9);

	return 0;
}