//takes a bunch of number grades and converts to letter grade

#include <iostream>
#include <format>

using namespace std;

int main() {
	int total{ 0 };
	int gradeCounter{ 0 };
	int aCount{ 0 };
	int bCount{ 0 };
	int cCount{ 0 };
	int dCount{ 0 };
	int fCount{ 0 };
	cout << "gimme grades please; new line for new grade; ctrl + z for end of file\n";
	int grade;
	while (cin >> grade) {
		total += grade;
		++gradeCounter;
		switch (grade / 10) {
			case 9://grade between 90
			case 10://and 100 inclusive
				++aCount;
				break;
			case 8:
				++bCount;
				break;
			case 7:
				++cCount;
				break;
			case 6:
				++dCount;
				break;
			default:
				++fCount;
				break;
		} //switch end
	}
	int mean{ total / gradeCounter };
	cout << format("\n\nnumber of grades eneter: {}\n sum: {}\naverage: {}\nNumber of students who got: \nA:{}\nB:{}\nC:{}\nD:{}\nF:{}\n", gradeCounter, total, mean, aCount, bCount, cCount, dCount, fCount);
}
