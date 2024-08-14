// merge sort with file handling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//performs merge sort. Uses txt files to store information.

/*
* Merge sort with array A of length n:
* 1) divide array into two arrays of roundDown(n/2) and roundUp(n/2) length, physically or logically
* 2) merge sort left array
* 3) merge sort right array
* 4) perform merge()
* 
* mergeSort(A[1..n]){
*     n>1:
*         m <- roundDown(n/2);
*         mergeSort(A[1..m]);
*         mergeSort(A[m+1..n]);
*         merge(A[1..n],m)
* }
* 
* merge(A[1..n],m){
*     i <- 1;  // i represents values from A[1..m]
*     j <- m+1; // j represents values from A[m+1..n]
*     for (k<-1 to n){
*         j>n: // here all values in A[m+1..n] have been used so the next value from A[1..m] is used.
*             B[k] <- A[i];
*             ++i;
*         i>m: // here all values in A[1..m] have been used so the next value from A[m+1..n] is used.
*             B[k] <- A[j];
*             ++j;
*         A[i]<A[j]:
*             B[k] <- A[i];
*             ++i;
*         else:
*             B[k] <- A[j];
*             ++j;
*     }
* }
* 
*/

#include <iostream>
#include <format>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <span>
#include <vector>
#include <array>


std::vector<int> getInput();
void writeOutput(std::span<int> inputVector);
void displaySpan(std::span<int> items);
void mergeSort(std::span<int> A, size_t offset=0);
void merge(std::span<int> A, size_t m, size_t offset=0);

// reading in data from file data.txt
std::vector<int> inputVector{ getInput() };
// auxilary space
std::vector<int> outputVector{inputVector};

int main()
{
    std::cout << "\n\n The input data was as follows:\n";
    displaySpan(inputVector);

    mergeSort(inputVector); // second argument, offset, is by default 0

    std::cout << "\n\n The sorted data is as follows:\n";
    displaySpan(outputVector);
    writeOutput(outputVector);

}

std::vector<int> getInput() {
    std::vector<int> inputVector;
    if (std::ifstream input{ "data.txt",std::ios::in }) {
        // initializaing temporary objects for input validation
        std::string s;
        int n;
        // display each line in file
        // at end-of-file character, exception is triggered
        while (input >> s) {
            std::istringstream iss(s);
            iss >> n;
            if (iss.fail() || !iss.eof()) {
                continue; // handle failure
            }
            inputVector.push_back(n);
        }
        return inputVector;
    }
    else {
        std::cerr << "Failure to open input file: data.txt\n";
        std::exit(EXIT_FAILURE);
    }
}


void writeOutput(std::span<int> items) {
    // writes outputVector to file output.txt
    // if no such file creates one 
    // will override preexisting output.txt file
    if (std::ofstream output{ "output.txt" }) {
        for (const auto& item : items) {
            output << std::format("{}\n", item);
        }
    }
    else {
        std::cerr << "Failure to open output file: output.txt\n";
        std::exit(EXIT_FAILURE);
    }
}

void displaySpan(std::span<int> items) {
    //dsiplays some span with a range based for loop
    std::cout <<"\n\nVector: \n";
    for (const auto& item : items) {
        std::cout << std::format("{}\n", item);
    }
    std::cout << std::format("The number of elements in this span are {}\n\n", items.size());
}

void mergeSort(std::span<int> A,size_t offset) {
    if (size_t n = A.size(); n != 1 && n != 0) {
        size_t m;
        (n % 2 == 0) ? m = n / 2 : m = (n / 2) + 1;
        // m splits A roughly into half
        mergeSort(A.subspan(0,m)); // left recursion
        mergeSort(A.subspan(m,n-m),offset+m); // right recursion
        //right recursion get offset by m places to prevent crosscontaminate to other branches of recursion
        merge(A, m);
        inputVector =  outputVector ; // using inputVector as additional auxilary space. Need to find alternative
    }
}

void merge(std::span<int> A, size_t m, size_t offset) {
    size_t n{ A.size() }; // narrowing conversion from unsigned long long to int
    size_t i{0}; //left recursion array from 0 to m-1 (index place)
    size_t j{m}; //right recursion array from m to n-1 (index place)
    for (size_t k{ 0 }; k < n; ++k) {
        if (j >= n) { //if all the elements in the right recursion array are already used
            outputVector[offset + k] = A[i];
            ++i;
        }
        else if (i >= m) { //if all the elements in the left recursion array are already used
            outputVector[offset + k] = A[j];
            ++j;
        }
        else if (A[i] < A[j]) { //picking the smallest of the next element in the right or left recursion array
            outputVector[offset + k] = A[i];
            ++i;
        }
        else {
            outputVector[offset + k] = A[j];
            ++j;
        }
    }


}
/*
merge(A[1..n],m){
    i <- 1;  // i represents values from A[1..m]
    j <- m+1; // j represents values from A[m+1..n]
    for (k<-1 to n){
        j>n: // here all values in A[m+1..n] have been used so the next value from A[1..m] is used.
            B[k] <- A[i];
            ++i;
        i>m: // here all values in A[1..m] have been used so the next value from A[m+1..n] is used.
            B[k] <- A[j];
            ++j;
        A[i]<A[j]:
            B[k] <- A[i];
            ++i;
        else:
            B[k] <- A[j];
            ++j;
    }
}

*/
//--------------------------------------------------------------------------------------------------------------------------------------------
/*
verbose code:

#include <iostream>
#include <format>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <span>
#include <vector>
#include <array>


std::vector<int> getInput();
void writeOutput(std::span<int> inputVector);
void displaySpan(std::span<int> items);
void mergeSort(std::span<int> A, size_t offset);
void merge(std::span<int> A, size_t m, size_t offset);

std::vector<int> inputVector{ getInput() };
std::vector<int> outputVector{ inputVector };

int main()
{
    displaySpan(inputVector);
    size_t offset = 0;
    mergeSort(inputVector, offset);
    displaySpan(outputVector);
    writeOutput(outputVector);

}

std::vector<int> getInput() {
    std::vector<int> inputVector;
    if (std::ifstream input{ "data.txt",std::ios::in }) {
        //initializaing temporary objects for processing
        std::string s;
        int n;
        //display each record in file
        while (input >> s) {
            std::istringstream iss(s);
            iss >> n;
            if (iss.fail() || !iss.eof()) {
                continue; // handle failure
            }
            inputVector.push_back(n);
        }
        return inputVector;
    }
    else {
        std::cerr << "Failure to open input file: data.txt\n";
        std::exit(EXIT_FAILURE);
    }
}


void writeOutput(std::span<int> items) {
    if (std::ofstream output{ "output.txt" }) {
        for (const auto& item : items) {
            output << std::format("{}\n", item);
        }
    }
    else {
        std::cerr << "Failure to open output file: output.txt\n";
        std::exit(EXIT_FAILURE);
    }
}

void displaySpan(std::span<int> items) {
    std::cout << "\n\nDISPLAYSPAN\n";
    for (const auto& item : items) {
        std::cout << std::format("{}\n", item);
    }
    std::cout << std::format("The number of elements in this span are {}\n\n", items.size());
}

void mergeSort(std::span<int> A, size_t offset) {
    if (size_t n = A.size(); n != 1 && n != 0) {
        size_t m;
        (n % 2 == 0) ? m = n / 2 : m = (n / 2) + 1;

        std::cout << std::format("\n\nMERGESORT \nm      :{:>5d}\nn      :{:>5d}\noffset :{:>5d}\n", m, n, offset);

        mergeSort(A.subspan(0, m), offset);
        mergeSort(A.subspan(m, n - m), offset + m);
        merge(A, m, offset);
        inputVector = outputVector;
        std::cout << "\nMERGESORT END\n\n";
    }
}

void merge(std::span<int> A, size_t m, size_t offset) {
    size_t n{ A.size() }; // narrowing conversion from unsigned long long to int
    size_t i{ 0 };
    size_t j{ m };
    std::cout << "\n\nMERGE\n";
    for (size_t k{ 0 }; k < n; ++k) {

        std::cout << std::format(
            "\noffset :{:>5d}"
            "\nk      :{:>5d}"
            "\ni      :{:>5d}"
            "\nj      :{:>5d}"
            "\nn      :{:>5d}"
            "\nm      :{:>5d}"
            "\n", offset, k, i, j, n, m);

        if (j >= n) {
            outputVector[offset + k] = A[i];
            ++i;
            std::cout << "j >= n";
        }
        else if (i >= m) {
            outputVector[offset + k] = A[j];
            ++j;
            std::cout << "i >= m";
        }
        else if (A[i] < A[j]) {
            outputVector[offset + k] = A[i];
            ++i;
            std::cout << "A[i] < A[j]";
        }
        else {
            outputVector[offset + k] = A[j];
            ++j;
            std::cout << "else";
        }

        displaySpan(outputVector);
    }
    std::cout << "\nMERGE END\n\n";


}



*/