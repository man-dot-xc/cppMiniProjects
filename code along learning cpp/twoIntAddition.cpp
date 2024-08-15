//twoIntAddition.cpp
//adds two ints
#include <iostream>

int main() {
	//declare + initialize int vars by writing [objType] [varName]{value};
	int num1{ 0 };
	int num2{ 0 };
	int sum{ 0 };
	
	std::cout << "give me a number ";
	std::cin >> num1;
	std::cout << "another ";
	std::cin >> num2;
	sum = num1 + num2;
	std::cout << "Sum is " << sum << "\n";
}

/*
variable is a named entity that represents a value
you can do multiple stream insertion character (<<) to concatenate int with string. 
>> is called an output stream character
int is 4 bytes
long is 8 byte
for a signed integer +- 2 billion
*/