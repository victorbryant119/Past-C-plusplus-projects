////
////  main.cpp
////  Week 1
////
////  Created by James Chapman on 9/28/21.
////
///*
// Review:
// Data types
// Strings
// User input
// Loops
// If-else
// Booleans
// */
//
//#include <iostream>
//#include <cmath>
//using namespace std;
//
////1. Write a function that repeatedly asks for user input. Stops when the user enters an int
//int getNum() {
//    return 0;
//}
//
//
///*2.
// Print out the following, where n is some number (say 10)
// 1
// 1 2
// 1 2 3
// ...
// 1 2 3 4 ... n
// */
//void tableFun(int n) {
//
//}
//
////3. Add up the numbers in the previous table
//int tableSum(int n) {
////    int x = 0;
////    for (int i=1; i<= n; i++){
////        for (int j =1; j<= i; j++){
////            x = x + j;
////        }
////    }
////    cout << x << endl;
//    return 0;
//}
//
////4. Write code to compute the n'th fibonacci number. Print out the first 100 Fibonacci numbers
////  - recall F_0 = 0, F_1 = 1, F_{n+2} = F_{n+1} + F_n
//int fib(int n) {
////    int x = 0;
////    for (int i=1; i<= n; i++){
////        if (i==1){
////            cout << 0;
////        }
////        }
////    return 0;
//    int t1 = 0, t2 = 1, nextTerm = 0;
//
//        cout << "Enter the number of terms: ";
//        cin >> n;
//
//        cout << "Fibonacci Series: ";
//
//        for (int i = 1; i <= n; ++i) {
//            // Prints the first two terms.
//            if(i == 1) {
//                cout << t1 << ", ";
//                continue;
//            }
//            if(i == 2) {
//                cout << t2 << ", ";
//                continue;
//            }
//            nextTerm = t1 + t2;
//            t1 = t2;
//            t2 = nextTerm;
//
//            cout << nextTerm << ", ";
//        }
//        return 0;
//}
////4b. The Fibonacci numbers can also be written as F_n = (a^n + b^n)/sqrt(5) where
////  a = (1+sqrt(5))/2   and b = (1-sqrt(5))/2
////  What happens when we input a large n?
//int fib2(int n) {
//    float a = (1+sqrt(5))/2;
//    float b = (1-sqrt(5))/2;
//    return (pow(a, n) + pow(b, n))/sqrt(5);
//}
////because using float means that you will lose a lot of accuracy in your data.
////5. Calculate the sum of the digits in a non-negative number
//int digitSum(int n) {
//    int sum = 0, m = 0;
//    if (n < 0){
//        cout << n << endl;
//    }
//    while (n > 0)
//    {
//        m = n%10;
//        sum+=m;
//        n=n/10;
//    }
//    cout<<sum<<endl;
//    return 0;
//}
//
////6. Write a function that sorts the letters in a word and displays it
//void wordSorter(string str) {
//
//    return;
//}
//
///*7. What happens when the following code is run?
// string str = "hi";
// cout << "a" + "b" + str << endl;
// */
////str+ "a" is good but not the other way around
//
//
//int main() {
//
//    tableSum(5);
////    fib(5);
//    digitSum(467);
//    return 0;
//}

//
//  main.cpp
//  Week 1 Thursday
//
//  Created by James Chapman on 9/29/21.
//
/*
 Reviewing:
 Functions
 Classes
 */

//#include <iostream>
//#include <cmath>
//using namespace std;
//
//
////1. Write a function that sorts the letters in a word and displays it
//void wordSorter(string str) {
//    return;
//}
//
////2. What does the function g3 do? Can you give a formula in terms of n?
//int g1(int n) {
//    return n*(n-1)/2;
//}
//int g2(int n) {
//    return g1(n) + g1(n-1);
//}
//int g3(int n) {
//    return g1(2*n) + g2(n);
//}
//
//
////3. What does the function f1 do? Can you give a formula in terms of n?
//int f1(int n);
//int f2(int n);
//
//int f1(int n) {
//    return f2(n-1) * n;
//}
//
//int f2(int n) {
//    if(n % 3 == 0) {
//        return 1;
//    } else {
//        return f1(n);
//    }
//}
//
////4. What does this function do?
//int base = 15;
//double exponential(double base, double power) {
//    return pow(base, power);
//}
//
//
///*5. Write a class for a circle in the plane
// Requirements:
//    - Store center and radius privately
//    - Default constructor
//    - Other constructors
//    - Public Access functions
//    - Public Mutator function for the center
//    - Public function to determine if two circles intersect
// Extra:
//    - Function that prints intersection points
//    - Function that prints nearest points
//    - Function to "add" two circles
// */
//
//
//
//
//
////6. Challenge Problem
////Write a function to compute the n'th root of a double where n is a positive integer
////you are not allowed to use anything from the cmath library
////you may only use loops, if-else, and +-*/%
////You may find it easiest to start by thinking about only
////the square root.
//
//
//
//
//int main() {
//
//    return 0;
//}

//
//  main.cpp
//  Week 2 Tuesday
//
//  Created by James Chapman on 10/4/21.
//
/*
 Review:
 Vectors
 Arrays
 2D vectors/arrays
 Skip File I/O until later in the quarter
 
 New Topics:
 Pointer
 
 Comments:
    - Problem 3 from last discussion was hard
 
 */

//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//
//void vecPrinter(vector <int> v) {
//    int n = static_cast<int>(v.size());
//    for (int i =0; i < n; i++){
//        cout << v[i] << ",";
//    }
//}
//
//int counter (vector<double> v, double x) {
//    int count = 0;
//    for (int i=0; i< v.size (); i++) {
//        if (v[i] ==x){
//            count +=1;
//        }
//    }
//    return count;
//}
//
//int main() {
//
//    //1.  Make a vector<int> containing {1, 2, 3, ..., n} where n is given by the user (you may assume the user gives a positive integer for n).
//    //1b. Why can't we do the same thing for arrays?
//
////    int n;
////    cin >> n;
////    vector<int> v(n);
////
////    for (int i=0; i<n; i++)
////    {
////        v[i] = i+1;
////        cout << v[i] << endl;
////    }
////    Because we need to have a constant number of arrays where we dont know the size arrays.
//
//    //2.  Create an int array containing {100, 99,..., 1}
//
////    int n= 100;
////        vector<int> v(n);
////    for (int i=99; i>=0; i--)
////        {
////            v[i] = i+1;
////            cout << v[i] << endl;
////        }
////    int num[100];
////    for (int i = 100; i >0;i--){
////        num[100-i] =i;
////        cout << num [100-i] << endl;
////    }
//
//    //3. Write a function to print out a vector<int>
////    int n= 100;
////        vector<int> v(n);
////    for (int i=99; i>=0; i--)
////        {
////            v[i] = i+1;
////            cout << v[i] << endl;
////        }
////    vector <int> v = {1,2,3,4};
////    vecPrinter(v);
//        //4. Write a function counter(v, x) that counts the number of times x occurs in v
//
//    //5. Write a function to compute the mean of an array of data
//
//
//    //Pointers
//    //6. What does the following code do?
//    int a6 = 50, b6 = 51, c6 = -10;
//    int *p6 = &a6, *q6 = &b6, *r6 = &c6;
//    *p6 = c6;
//    q6 = &c6;
//    c6 = 14;
////    cout << p6  << " " << q6  << " " << r6  << endl;
////    cout << *p6 << " " << *q6 << " " << *r6 << endl;
//
//
//    //7. What does the following code do?
//    char a7 = 'a';
//    char* p7 = &a7;
//    p7 += 5;
//    //cout << p7 << endl;
//
//
//    //8. What does the following code do?
//
//    int x8[5] = {1, 2, 3, 4, 5};
//    int* p8 = &x8[0];
//    for(int i = 0; i < 5; i++) {
//        cout << p8 << " ";
//        p8++;
//    }
//    cout << endl;
//
//    //9. Challenge Problem:
//    //Write an interesting class using pointers.
//
//    return 0;
//}

//
//  main.cpp
//  Week 2 Thursday
//
//  Created by James Chapman on 10/6/21.
//
// [1] - C. Horstmann "Big C++: Late Objects" 3rd edition
/*
 Pointers:
    - Literally store a memory address
    - Called a pointer because we think of that variable as pointing to the data stored at the memory address
    - Use &x to get the memory address of the variable x.
    - Use *p to access the data stored at the memory address stored by p
    - Don't leave pointers uninitialized. Use nullptr instead of nothing.
 
 Stack vs Heap:
    - By default, variables are stored on the stack
    - Use the heap for dynamic memory allocation
    - Use keyword new to allocate new memory in the heap
    - Use keyword delete to free up memory in the heap
    - Use keyword delete[] to free up memory associated with an array
 
 
 
 */

#include <iostream>
#include <stdio.h>
#include "RPS.hpp"
using namespace std;


int mean (double* v, int size  ) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(v+i);
    }
    sum /= size;
    return sum;
}
int main() {
    
    //1. What does the following code do?
    char a7 = 'a';
    char* p7 = &a7;
    p7 += 5;
    //cout << p7 << endl;
    
    
    //2. What does the following code do?
    int v2[10] = {5, 6, 3, 4, 9, 8, 1, 2, 3, 4};
    //cout << *v << " " << *(v+1) << " " << *(v+9) << endl;
    
    
    //3. [1] R7.6   Consider the following code
    double primes[] = {2, 3, 5, 7, 11, 13};
    double *p = primes + 3;
    //What are each of the following
    //primes[1], primes + 1, *(primes + 1), p[1], p+1
    cout << primes[1] << " " << primes + 1 << " " << &primes[1] << endl;
    cout << *(primes + 1) << " " << p[1] << " " << p+1 << endl;
    //3b. If &primes[0] = 1000, then what are the memory addresses from the previous problem?
    //1008 for 3 , 1032 for 11 and 1024 for p
    
    //4. Write a function that computes the mean of an array of ints. It should fit the following format.
    // double meanFun(double* v, int size);
    double v4[5] = {1, 2, 3, 4, 5};
    //cout << meanFun(v4, 5) << endl;
    
    
    //5. Write a class called RPS (stands for rock paper scissors). The hpp file outlines some important functions.
    
    
    //6. We want to create an array. Get user input for the size.
    //  Then prompt the user to enter ints into the array (assume good input)
    //  When this is done, print out the array.
    
    
    return 0;
}







//
//  RPS.hpp
//  Week 2 Thursday
//
//  Created by James Chapman on 10/6/21.
//

#ifndef RPS_hpp
#define RPS_hpp

#include <stdio.h>
#include <iostream>

class RPS {
private:
    std::string name;
    RPS* beats;
    
public:
    RPS(std::string name, RPS* beats);
    
    void updateName(std::string newName);
    void updateBeats(RPS* newBeats);    //only allow if beats == nullptr
    
};


#endif /* RPS_hpp */
