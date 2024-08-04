#include <iostream>
#include <format>
#include <cmath>
#include <string>

using namespace std;

int main() {
	double principle{ 0.00 };
	double rate{ 0.00 };
	cout << "Give me principle and rate ";
	cin >> principle >> rate;
	cout << format("Initial principle: {:>7.2f}\n", principle) // :> means right align, 7 means field width so right align in 7 width field, .2f means display floating point value at 2d.p also does rounding.
		<< format("Initial rate: {:>7.2f}\n", rate);

	cout << format("\n{}{:>20}\n", "Year", "Amount on deposit");
	for (int yr{ 1 }; yr <= 10; yr++) {
		double amount{ principle * pow(1.0 + rate,yr) };
		cout << format("\n{:>4d}{:>20.2f}",yr, amount); //d means base 10 int or decimal
	}


}
