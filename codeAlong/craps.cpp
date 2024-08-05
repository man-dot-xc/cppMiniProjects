// craps.cpp : This file contains the 'main' function. Program execution begins and ends there.
// craps is casino game
// roll two dice, sum
// 7 or 11 = you win
// 2,3 or 12 = house win = "craps"
// default sum is your point
// make your point before rolling a 7 to win else loose
// make your point means get the same sum in another roll.

#include <iostream>
#include <format>
#include <random>

using namespace std;
using std::cout;

int rollDice();

int main() {
	//scoped enumeration which contants to represent game status
	//calls names are in capital camel case
	//scope bc only exists in main
	enum class Status {keepRolling,won,lost};

	int point{ 0 }; //tracks points
	Status gameStatus{ Status::keepRolling }; //use cosntant instead of 0 for readability

	switch (const int sum{ rollDice() }) {
	case 7:
	case 11:
		gameStatus = Status::won;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = Status::lost;
		break;
	default:
		point = sum;
		cout << "\nPoint is " << point;
		break;
	}
	
	while (gameStatus == Status::keepRolling) {
		if(const int sum{ rollDice()};sum==point){
			gameStatus = Status::won;
		}
		else if (sum == 7) {
			gameStatus = Status::lost;
		}
	}

	if (gameStatus == Status::won) {
		cout << "\n player wins";
	}
	else if (gameStatus == Status::lost) {
		cout << "\n player lost";
	}
}

int rollDice() {
	static random_device rd; //static variable is only initialized at the first function call and reused without needing to initialize
	static default_random_engine engine{ rd() };
	static uniform_int_distribution fairDie{ 1,6 };

	const int die1{ fairDie(engine) };
	const int die2{ fairDie(engine) };
	const int sum{ die1 + die2 };
	cout << format("\n Player rolled {} + {} = {}", die1, die2, sum);
	return sum;
}