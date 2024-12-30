/*
    PIC 10B, Final Exam - Part 2
    Problem 1: Combination
    Author: Wenchen(Victor) Shi
    Date: 12/08/2021
*/

/*
 NOTE: Write a function that returns a vector of all k-combinations of the numbers {1, 2, ..., n} where n and k are integer inputs to the function.
1. get the function to store from 1 to n
2. use recursive function to print out the possible combinations
 */
#include <stdio.h>
#include "P1.h"
#include <iostream>
using namespace std;

//NOTE: use & for s since we need to update it
std::vector<std::vector<int>> recursivehelp(std::vector<std::vector<int>> &s, std::vector <int> a, std::vector<int> combination, int base, int k)
{
    //Check if k==0, one set of combinations has been pushed back
    if (k==0)
    {
        s.push_back(combination);
        return s;
    }
    
    for (int i = base; i <= a.size() - k; ++i)
    {
        combination.push_back(a[i]);
        //use recursion to reenter the function
        recursivehelp(s, a, combination, i+1, k-1);
        //pop back the elements to create new combinations
        combination.pop_back();
    }
    
    return s;
}

//NOTE: it's a vector of vectors of type int
std::vector<std::vector<int>> combinations(int n, int k)
{
    std::vector<std::vector<int>> combvec={};
    std::vector <int> combine= {};
    std::vector <int> newcomb= {};
    
    //case0: when k==0, nothing prints out
    //NOTE: n choose 0 leads to NULL
    if (k==0)
        return combvec;
    
    //case1: when k==n, print out every number from 1 to n in one int vector
    if (k==n)
    {
        int count = n;
        for (int i=0; i<count; i++)
        {
            newcomb.push_back(n);
            n--;
        }
        combvec.push_back(newcomb);
    }
    
    //case2: when k==1, print out every number from 1 to n in separate vectors
    else if (k==1)
    {
        int count2 = n;
        for (int i=0; i<count2; i++)
        {
            newcomb.push_back(n);
            combvec.push_back(newcomb);
            n--;
            newcomb.clear();
        }
    }
    
    //case3: when k is in the middle, use recursive function to loop through
    else if (k!=0 && k!= n)
    {

        int count3 = n;
        for (int i=0; i<count3; i++)
        {
            newcomb.push_back(n);
            n--;
        }
        
        //call recursive function which will push back values in combination
        recursivehelp(combvec, newcomb, combine, 0, k);
    }
    return combvec;
}
