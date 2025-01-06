#include <stdio.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <algorithm>
#include <type_traits>

#include <stdlib.h>
#include <vector>
#include <list>
#include <thread>
#include <chrono>


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

class Enemy
{
public:
	void phaseApproach();
	void phaseFire();
	void phaseLeave();

	void Update();
private:
	static void (Enemy::* spFuncTable[])();

	enum Phase {
		Approach,
		Fire,
		Leave,
	};

	Phase phase_ = Phase::Approach;

};

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::phaseApproach,
	&Enemy::phaseFire,
	&Enemy::phaseLeave
};

void Enemy::phaseApproach()
{

	printf("敵が近づいてきた!!\n\n");

	phase_ = Phase::Fire;
}

void Enemy::phaseFire()
{

	printf("敵が弾を発射!!!\n\n");

	phase_ = Phase::Leave;

}

void Enemy::phaseLeave()
{

	printf("敵は離れていった...\n\n");

}

void Enemy::Update()
{

	(this->*spFuncTable[static_cast<size_t>(phase_)])();

}

template <typename Type1, typename Type2>

class Diff {
public:
	Type1 num1;
	Type2 num2;

	Diff(Type1 num1, Type2 num2) : num1(num1), num2(num2) {}

	void Min() {

		auto minNum = (num1 < num2) ? num1 : num2;

		if constexpr (std::is_same_v<decltype(minNum), int>) {
			printf("%d\n", minNum);
		}
		else if constexpr (std::is_same_v<decltype(minNum), float>) {
			printf("%f\n", minNum);
		}
		else if constexpr (std::is_same_v<decltype(minNum), double>) {
			printf("%lf\n", minNum);
		}
		else {
			// 型が int, float, double でない場合の処理
			printf("Unsupported type\n");
		}
	}
};
class  ILanguage{
public:
	
	virtual void Greeting() = 0;
};

class Japanese : public ILanguage
{
public:

	void Greeting() override {

		printf("おはよう\n");

	}
};

class English : public ILanguage
{
public:

	void Greeting() override {

		printf("good morning\n");

	}
};

class Chainese : public ILanguage
{
public:

	void Greeting() override {

		printf("早上好\n");

	}
};

using namespace std;

struct Station
{
	const char* name;
};

void InsertNewStation(std::list<Station>& stations,const char* targetStation,const char* newStation)
{

	std::list<Station>::iterator it;

	for (it = stations.begin(); it != stations.end(); ++it)
	{
		if (strcmp(it->name, targetStation) == 0)
		{

			stations.insert(std::next(it), { newStation });

			return;
		}
	}

}

void Print(int num)
{
	printf("thread%d\n", num);
}

int main()
{

	// 大きな文字列を生成
    std::string str(1000000, 'a');

	// コピー処理の時間を計測
	auto startCopy = std::chrono::high_resolution_clock::now();
	std::string str1 = str;
	auto endCopy = std::chrono::high_resolution_clock::now();

	// ムーブ処理の時間を計測
	auto startMove = std::chrono::high_resolution_clock::now();
	std::string str2 = std::move(str);
	auto endMove = std::chrono::high_resolution_clock::now();

	// コピーとムーブにかかった時間を表示
	auto copyDuration = std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count();
	auto moveDuration = std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count();

	std::cout << "Copy duration: " << copyDuration << " microseconds\n";
	std::cout << "Move duration: " << moveDuration << " microseconds\n";

	return 0;
}