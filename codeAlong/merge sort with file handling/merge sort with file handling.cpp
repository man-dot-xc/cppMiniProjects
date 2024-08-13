// merge sort with file handling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//performs merge sort. Uses txt files to store information.

/*
Merge sort with array A of length n:
1) divide array into two arrays of roundDown(n/2) and roundUp(n/2) length, physically or logically
2) merge sort left array
3) merge sort right array
4) perform merge()

mergeSort(A[1..n]){
    n>1:
        m <- roundDown(n/2);
        mergeSort(A[1..m]);
        mergeSort(A[m..n]);
        merge(A[1..n],m)
}

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

#include <iostream>
#include <format>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main()
{
    
    if (std::ifstream dataIn{"data.txt",std::ios::in }) {
        std::cout << "Dipalying contents of data.text: \n";
        std::cout << std::format("{}\n", "Unsorted data: ");
        std::string s;
        int n;
        //display each record in file
        while ( dataIn >> s) {
            std::istringstream iss(s);
            iss >> n;
            if (iss.fail() || !iss.eof()) {
                continue; // handle failure
            }
            std::cout << std::format("{}\n", n);
        }
    }
    else {
        std::cerr << "Failure to open file";
        std::exit(EXIT_FAILURE);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
