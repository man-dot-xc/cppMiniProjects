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
void displaySpan(std::span<int> items, std::string msg = std::string{"Displaying a span"});
void mergeSort(std::span<int> A, size_t offset = size_t{0});
void merge(std::span<int> A, size_t m, size_t offset);

std::vector<int> inputVector{ getInput() };
std::vector<int> outputVector{ inputVector };

int main()
{
    displaySpan(inputVector, "Displaying Input");
    mergeSort(inputVector, size_t{0});
    displaySpan(outputVector, "Dsiplaying Output");
    writeOutput(outputVector);

}

std::vector<int> getInput() {
    std::vector<int> inputVector;
    if (std::ifstream input{ "data.txt",std::ios::in }) {
        //initializaing temporary objects for input validation
        std::string s;
        int n;
        //get each line
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

void displaySpan(std::span<int> items,std::string msg) {
    std::cout << "\n\n" << msg << "\n";
    for (const auto& item : items) {
        std::cout << std::format("{}\n", item);
    }
    std::cout << std::format("The number of elements in this span are {}\n\n", items.size());
}

void mergeSort(std::span<int> A, size_t offset) {
    if (size_t n = A.size(); n != 1 && n != 0) { //base case of n=1 or n=0 is handled with no change
        size_t m; //determine pivot point as the middle position
        (n % 2 == 0) ? m = n / 2 : m = (n / 2) + 1;

        mergeSort(A.subspan(0, m), offset);
        mergeSort(A.subspan(m, n - m), offset + m);
        
        merge(A, m, offset);
        
        inputVector = outputVector; //reusing inputVector as auxillary storage
        // previous line is too spacially complex, need to iterate over only offset to n positions
    }
}

void merge(std::span<int> A, size_t m, size_t offset) {
    size_t n{ A.size() }; //size_t is too spacially complex considering the application, consider a narrowing converison from size_t to int
    size_t i{ 0 }; // left array (assumed sorted due to inductive hypothesis) from offset to m
    size_t j{ m }; // right array (assumed sorted due to inductive hypothesis) from m to n
    for (size_t k{ 0 }; k < n; ++k) {
        if (j >= n) { //if all elements in right array already merged, merge the next element in the left sorted array 
            outputVector[offset + k] = A[i];
            ++i;
        }
        else if (i >= m) { // if all elements in left array already merged, merge the next element in the right sorted array
            outputVector[offset + k] = A[j];
            ++j;
        }
        else if (A[i] < A[j]) { // the 'next element' from the left and right sorted array compared, smaller one merges first to make ascending list
            outputVector[offset + k] = A[i];
            ++i;
        }
        else {
            outputVector[offset + k] = A[j];
            ++j;
        }
    }


}