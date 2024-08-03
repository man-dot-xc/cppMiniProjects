#include <iostream> 
#include <string>

using namespace std;

int main() {
	int studentGrade{ 0 };
	cout << "give me a grade please: ";
	cin >> studentGrade;

	cout << "\n\n Grade is: ";

	/*
	if (studentGrade >= 90) {
		cout << "A";
	}
	else {
		if (studentGrade >= 80) {
			cout << "B";
		}
		else {
			if (studentGrade >= 70) {
				cout << "C";
			}
			else {
				if (studentGrade >= 60) {
					cout << "D";
				}
				else {
					cout << "F";
				}

	}
	*/

	//nesting if statements correctly

	if (studentGrade >= 90) {
		cout << "A";
	}
	else if (studentGrade >= 80) {
		cout << "B";
	}
	else if (studentGrade >= 70) {
		cout << "C";
	}
	else if (studentGrade >= 60) {
		cout << "D";
	}
	else {
		cout << "F";
	}

	//conditional operator is [condition]?[if true]:[if false]
	cout << "\n\n Did you fail ? : " << (studentGrade >= 60 ? "Passed" : "Failed")<<"\n\n";

	//while loop
	int product{ 3 };
	while (product <= 100) {
		product = product * 3;
		cout << product << "\n";
	}
}