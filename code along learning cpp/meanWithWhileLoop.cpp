#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int gradeCounter{ 0 };
	int total{ 0 };
	double mean{ 0 };

	while (gradeCounter < 10) {
		cout << "Enter Grade: ";
		int grade;
		cin >> grade;
		if (grade > 100 || grade < 0) {
			cout << "\n\nGrade is out of bounds. Please enter a grade between 0 and 100. \n\n";
			continue;
		}
		total += grade;
		gradeCounter++;
	}

	mean = round(total / 10);
	cout << "\n\nthe mean of the 10 grade is: " << mean << "\n\n";
}