#include <iostream>
#include <random>
#include <format>

using namespace std;

int main() {
	random_device rd;
	default_random_engine engine{rd()};
	uniform_int_distribution fairDie{ 1,6 };
	int freq1{ 0 }, freq2{ 0 }, freq3{ 0 }, freq4{ 0 }, freq5{ 0 }, freq6{ 0 }; //not using arrays yet
	for (int i{ 0 }; i < 6'000'000; ++i) { //single quote works in place of commas
		switch (const int face{ fairDie(engine) }) {
			case 1:
				freq1++;
				break;
			case 2:
				freq2++;
				break;
			case 3:
				freq3++;
				break;
			case 4:
				freq4++;
				break;
			case 5:
				freq5++;
				break;
			case 6:
				freq6++;
				break;
			default:
				cout << "\nerror placeholder 1";
		}
	}
	cout << format("\nFinal distruibutions are \n1:{:>13d}\n2:{:>13d}\n3:{:>13d}\n4:{:>13d}\n5:{:>13d}\n6:{:>13d}\n\n",freq1, freq2, freq3, freq4, freq5, freq6);
}