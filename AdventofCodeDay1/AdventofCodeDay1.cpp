// AdventofCodeDay1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

//1. [Process Input] Read input file into a stack, count size.
//                   Create array of {size, 3}.
//2a. [Find first # in each] For each string pulled off the stack, read until a numeral is found. Store in [increment, 0].
//2b. [Find last # in each] For each string pulled off the stack, read from the back until a numeral is found. Store in [increment, 1].
//                          This will catch the edge case where there is only one numeral. 
//3. [Parse First + Last] Iterate through array. [increment, 2] = concat [increment, 0] + [increment, 1]. 
//4. [Return Sum] Iterate through array. sum += [increment, 2]. Return sum. 



int main()
{

    //
    std::cout << "Hello World!\n";
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
