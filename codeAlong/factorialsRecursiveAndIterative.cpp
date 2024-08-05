#include <iostream>
#include <format>
#include <cmath>

using namespace std;

int factorial(int n);

int main() {
	int number;
	cout << "Gimme number not too large pls : ";
	cin >> number;
	cout << "\nIteratively : " << fixed << tgamma(number+1);
	cout << "\nRecursively : " << fixed << factorial(number);
}

int factorial(int n) {
	if (n == 1) {
		return n;
	}
	else {
		return factorial(n - 1)* n;
	}
}