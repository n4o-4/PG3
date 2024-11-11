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

#include <algorithm>

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

std::string ExtractNunber(const::string& ID)
{
	size_t start = ID.find('g') + 1;  // 'g' の次の位置を取得
	size_t end = ID.find('@');       // '@' の位置を取得
	return ID.substr(start, end - start);
}

int main()
{

	std::vector<string> studentID = { "k022g0108@g.neec.ac.jp", "k022g0045@g.neec.ac.jp", "k022g0007@g.neec.ac.jp", "k022g0015@g.neec.ac.jp", "k022g0028@g.neec.ac.jp", "k022g0049@g.neec.ac.jp", "k022g0003@g.neec.ac.jp", "k022g0044@g.neec.ac.jp", "k022g0072@g.neec.ac.jp", "k022g0055@g.neec.ac.jp", "k021g1139@g.neec.ac.jp", "k021g1485@g.neec.ac.jp", "k021g1162@g.neec.ac.jp", "k021g1278@g.neec.ac.jp", "k020g1229@g.neec.ac.jp", "k020g1202@g.neec.ac.jp", "k020g1215@g.neec.ac.jp", "k020g1416@g.neec.ac.jp", "k020g1245@g.neec.ac.jp", "k020g1506@g.neec.ac.jp", "k020g1401@g.neec.ac.jp", "k022g0089@g.neec.ac.jp", "k022g0107@g.neec.ac.jp", "k022g0135@g.neec.ac.jp", "k022g0020@g.neec.ac.jp", "k022g0046@g.neec.ac.jp", "k022g0126@g.neec.ac.jp", "k022g0068@g.neec.ac.jp", "k022g1060@g.neec.ac.jp", "k022g0019@g.neec.ac.jp", "k022g0013@g.neec.ac.jp", "k022g0024@g.neec.ac.jp", "k022g0134@g.neec.ac.jp", "k022g0123@g.neec.ac.jp", "k022g0030@g.neec.ac.jp", "k022g0053@g.neec.ac.jp", "k022g0023@g.neec.ac.jp", "k022g0041@g.neec.ac.jp", "k022g0063@g.neec.ac.jp", "k022g0059@g.neec.ac.jp", "k022g0078@g.neec.ac.jp", "k022g0011@g.neec.ac.jp", "k022g0040@g.neec.ac.jp", "k022g0088@g.neec.ac.jp", "k022g0099@g.neec.ac.jp", "k022g0060@g.neec.ac.jp", "k022g0032@g.neec.ac.jp", "k022g0087@g.neec.ac.jp", "k022g0016@g.neec.ac.jp", "k022g0116@g.neec.ac.jp", "k022g0056@g.neec.ac.jp", "k022g0009@g.neec.ac.jp", "k022g0034@g.neec.ac.jp", "k022g0062@g.neec.ac.jp", "k022g0102@g.neec.ac.jp", "k022g0113@g.neec.ac.jp", "k022g0064@g.neec.ac.jp", "k022g0080@g.neec.ac.jp", "k022g0114@g.neec.ac.jp", "k022g0025@g.neec.ac.jp", "k022g0095@g.neec.ac.jp", "k022g0121@g.neec.ac.jp", "k022g0021@g.neec.ac.jp", "k022g0104@g.neec.ac.jp", "k022g0101@g.neec.ac.jp", "k022g0130@g.neec.ac.jp", "k022g0036@g.neec.ac.jp", "k022g0004@g.neec.ac.jp", "k022g0093@g.neec.ac.jp", "k022g0038@g.neec.ac.jp", "k022g0069@g.neec.ac.jp", "k022g0029@g.neec.ac.jp", "k022g0010@g.neec.ac.jp", "k022g0083@g.neec.ac.jp", "k022g0086@g.neec.ac.jp", "k022g0129@g.neec.ac.jp", "k022g0048@g.neec.ac.jp", "k022g0027@g.neec.ac.jp", "k022g0103@g.neec.ac.jp", "k022g0117@g.neec.ac.jp", "k022g0085@g.neec.ac.jp", "k022g0052@g.neec.ac.jp", "k022g0073@g.neec.ac.jp", "k022g0065@g.neec.ac.jp", "k022g0091@g.neec.ac.jp", "k022g0136@g.neec.ac.jp", "k022g0079@g.neec.ac.jp", "k022g0017@g.neec.ac.jp", "k022g0097@g.neec.ac.jp", "k022g0077@g.neec.ac.jp", "k022g0050@g.neec.ac.jp", "k022g0033@g.neec.ac.jp", "k022g0039@g.neec.ac.jp", "k022g0118@g.neec.ac.jp", "k022g0112@g.neec.ac.jp", "k022g0120@g.neec.ac.jp", "k022g0127@g.neec.ac.jp", "k021g1464@g.neec.ac.jp", "k022g0137@g.neec.ac.jp", "k022g0066@g.neec.ac.jp", "k022g0051@g.neec.ac.jp", "k022g0111@g.neec.ac.jp", "k022g0094@g.neec.ac.jp", "k022g0128@g.neec.ac.jp", "k022g0109@g.neec.ac.jp", "k022g0124@g.neec.ac.jp", "k022g0084@g.neec.ac.jp", "k022g0082@g.neec.ac.jp", "k022g0122@g.neec.ac.jp", "k022g0061@g.neec.ac.jp", "k022g0031@g.neec.ac.jp", "k022g0076@g.neec.ac.jp", "k022g0002@g.neec.ac.jp", "k022g0090@g.neec.ac.jp", "k022g0074@g.neec.ac.jp", "k022g0012@g.neec.ac.jp", "k022g0001@g.neec.ac.jp" };

	// ソート処理
	std::sort(studentID.begin(), studentID.end(), [](const std::string& a, const std::string& b) {
		return ExtractNunber(a) < ExtractNunber(b);
		});

	// 結果を出力
	for (const auto& id : studentID) {
		std::cout << id << std::endl;
	}

	return 0;
}