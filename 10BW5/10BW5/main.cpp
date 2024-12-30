//
//  main.cpp
//  Week 5 Thursday
//
//  Created by James Chapman on 10/27/21.
//

#include <iostream>
using namespace std;

//1. Reverse a string
//  - Similar to the palindrome example from class
//  - Pass by reference
//  - Have a helper function
void reverse (string& s, int start, int end){
    if (start>= end)
        return;
    char temp = s[start];
    s[start]=s[end];
    s[end]= temp;
    reverse(s, start+1,end-1);
}
void rev(string& s){
    reverse(s, 0, (int)s.size()-1);
}
//2. Sum the digits of a number
/*
 8  -> 8
 12 -> 3
 525-> 12
 */
int sumDigits(int n);

//3. How many ways can you place n queens on an nxn chess board so that they aren't attacking each other?
//  https://en.wikipedia.org/wiki/Eight_queens_puzzle



//Challenge Problem:
//1. Take any code you wrote in PIC10A using loops and write it with only recursion.
//2. Write a perfect tic-tac-toe AI using recursive backtracking
//3. Write a checkers AI using recursive backtracking

int main() {
    string s = "james";
    cout << s << endl;
    return 0;
}
