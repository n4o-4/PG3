#include <stdio.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>

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

void setTimeout(int frame) {
	Sleep(frame);
}

void RandomDice()
{
	srand(static_cast<unsigned int>(time(0)));

	std::string input;

	printf("ダイスの出目が偶数か奇数か入力してください\n");

	std::getline(std::cin, input);

	int diceNum = [=]() {return rand() % 6 + 1; }();

	setTimeout(1800);

	if (input == "偶数")
	{

		if (diceNum % 2 == 0)
		{
			printf("正解です！\n");

			printf("数字は%dでした\n\n",diceNum);
		}
		else
		{
			printf("不正解です\n");

			printf("数字は%dでした\n\n",diceNum);
		}
	}
	else if (input == "奇数")
	{
		if (diceNum % 2 == 0) {
			printf("不正解です");

			printf("数字は%dでした\n\n",diceNum);
		}
		else
		{
			printf("正解です！\n");

			printf("数字は%dでした\n\n",diceNum);
		}
	}

	RandomDice();
}

int main(void)
{
	void(*pfunc)();

	pfunc = RandomDice;

	pfunc();

	return 0;
}