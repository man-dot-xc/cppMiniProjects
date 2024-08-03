#include <iostream>

int main() {
	std::cout << "test string\nnew line\n"; //comment
	return 0;
}

/*
#include is a preprocessor directive which tells the c++ preprocessor to include the subsequent files
 <iostream> is called a header contains library or file with functions
 angled brackets indicate that either the header is a std library or is in the path where your IDE searches for libraries (in case of third party library)
 main() is a function that controls the start and lifetime of your program
 () is where any parameters required to run the function, which are provided upon calling the function, are declared.
 function is an ordered set of executable statements
 int is the return type for the function
 main functions can only have the return type int
 a return code of 0 implies successful execution, return 0 is not needed as it is implied upon all instructions being executed in the main function
 a non-zero return code implies various platform specific error codes
 curly brackets delimit the set of executable statements which make up a function
 the indented line delimited by a ; is called a c++ statement
 std is the standard library
 cout is the function which was included by the #include <iostream>
 << is the stream insertion character
 any set of characters enclosed by "" are the object type string a c++ code
 \n is a escape sequence; it tells the cursor to escape the writing path and jump to the next line where the rest of the string is the outputted
 */