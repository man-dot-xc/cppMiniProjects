#include <iostream>

using namespace std;

int main() {
	bool sentinel1{ true };
	double total{ 0.0 };
	int numGrades{ 0 };

	while (sentinel1) {
		int grade;
		cout << "Please enter a grade or -1 to quit: ";
		cin >> grade;
		if (grade > 100 || grade < -1) { 
			cout << "\n\nData out of bounds\n\n";
			continue;
		}
		if (grade == (-1)) {
			cout << "\nThank you for inputting data!";
			sentinel1 = false;
			continue;
		}
		total += grade;
		numGrades++;
	}

	cout << "\n\n total: "<<total<<"; number of data points: "<<numGrades<<";";
	double mean{ 0.0 };
	if (numGrades!=1) {
		mean = total / numGrades;
	}
	cout << "\n\n grade average is " << mean << " / 100\n\nThank you for using this console app";
}