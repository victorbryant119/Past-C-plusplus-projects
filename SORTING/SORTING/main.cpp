#include <vector>
#include <iostream>
using namespace std;

int binary_search(vector<int> v, int from, int to, int value)
{
if (from > to) return -1;    // if no find
int mid = (from + to) / 2;

if (v[mid] == value)
    return mid;
else if (v[mid] < value)
    return binary_search(v, mid + 1, to, value);
else
    return binary_search(v, from, mid - 1, value);
}


int main()
{
    int target;
    vector<int> v={ 2, 6, 9, 12, 15, 19, 25, 28, 35, 41, 49, 52, 67, 71, 76, 82, 83, 89, 92, 95, 98, 100 };
    cout << "Enter the number you want to search: ";
    cin >> target;
    int pos = binary_search(v, 0, v.size(), target);
    if (pos == -1)
        cout<< "Can't find the number " << target << " in the list.";
    else
        cout<< "The number " << target << " is found at v[" << pos << "].";
    return 0;
}
//#include <iostream>
//using namespace std;
//
//int a[50];
//void merge(int,int,int);
//void merge_sort(int low,int high)
//{
// int mid;
// if(low<high)
// {
//  mid=(low+high)/2;
//  merge_sort(low,mid);
//  merge_sort(mid+1,high);
//  merge(low,mid,high);
// }
//}
//
//
//void merge(int low,int mid,int high)
//{
//int h,i,j,b[50],k;
//h=low;
//i=low;
//j=mid+1;
//
//while((h<=mid)&&(j<=high))
//{
//  if(a[h]<=a[j])
//  {
//   b[i]=a[h];
//   h++;
//  }
//  else
//  {
//   b[i]=a[j];
//   j++;
//  }
//  i++;
// }
// if(h>mid)
// {
//  for(k=j;k<=high;k++)
//  {
//   b[i]=a[k];
//   i++;
//  }
//}
//else
//{
//  for(k=h;k<=mid;k++)
//  {
//    b[i]=a[k];
//    i++;
//  }
//}
//for(k=low;k<=high;k++)
//  a[k]=b[k];
//}
//
//
//int main()
//{
//int num,i;
//cout<<"Please Enter THE NUMBER OF ELEMENTS you want to sort [THEN PRESS ENTER]:"<<endl;
//cin>>num;
//cout<<endl;
//cout<<"Now, Please Enter the ( "<< num <<" ) numbers (ELEMENTS) [THEN PRESS ENTER]:"<<endl;
//for(i=1;i<=num;i++)
//{
//  cin>>a[i];
//}
//merge_sort(1,num);
//cout<<endl;
//cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;
//
//for(i=1;i<=num;i++)
//  cout<<a[i]<<"    ";
//
//cout<<endl<<endl<<endl<<endl;
//
//return 0;
//}
//#include <iostream>
//using namespace std;
//
//void swap(int *xp, int *yp){
//   int temp = *xp;
//   *xp = *yp;
//    *yp = temp;
//}
//
//void selectionSort(int arr[], int n){
//    int i, j, min_idx;
//    //One by one mover boundary of unsorted subarray
//    for(i=0; i<n-1; i++){
//        min_idx = i; //Find the min element
//        for(j=i+1; j<n; j++)
//            if(arr[j]<arr[min_idx])
//                min_idx = j;
//        // Swap the min element with the first
//        swap(&arr[min_idx], &arr[i]);
//    }
//}
//
//void printArray(int arr[], int size){
//    for(int i=0; i<size; i++)
//        cout << arr[i]<< endl;
//}
//
//int main(){
//    int arr[] = {64, 25, 12, 22, 11};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    selectionSort(arr, n);
//    printArray(arr, n);
//    return 0;
//}
//
//  main.cpp
//  Week 6 Thursday
//
//  Created by James Chapman on 11/2/21.
//
/*
 Midterm:
 We won't talk about it today
 
 Problems:
 1. Write a program to solve the Subset-sum problem
 2. Write a function that recursively sorts an array
 3. Program a Tic Tac Toe AI using recursion
 4. Write a maze solving program
 
 //MARK: INSTRUCTIONS FOR PEOPLE WATCHING FROM HOME
 Since we didn't have lecture Wednesday, we will be working on harder recursion problems in groups. I give a summary of the solutions below.
 If you are attending online or working on this later, I encourage you to work on the problems above before reading the solutions below. The solutions are written in pseudo-code and won't actually run in c++. The main goal of todays discussion is to learn how to solve hard problems and to get practice with different recursion techniques.
 
 {1, 2, 3} -> 7 no
 {-1, 4, 8} -> 3 yes
 
 1. Want code approximately like
 Sub(&A, depth, SUM) {
    if SUM == 0 return True
    else if ( depth == length of A ) return False
    for(int i = 0; i <= 1; i++) {
        if( Sub(&A, depth+1, SUM - i * A[depth]) == True)
            return True
    return False
 }
 This is equivalent to asking if x dot c = SUM has a solution for c a binary vector in n dimensions
 The previous code is essentially just enumerating all binary vectors c and seeing if one works
 **Make sure to pass by reference since not doing so is expensive with recursion
 
 2. First solution
 Sort(&A, depth) {
    if depth == len(A)
        return;
    //get location of min
    AM = argmin(of remaining elements of A)
    swap(AM, A[depth])
    Sort(A, depth+1)
 }
 
 Better solution: Merge sort
 The idea is to break the problem down into half the size each time
 
 3. No one worked on this
 If you want to have an idea of how to solve this, look up minimax
 
 4. First figure out how to represent the board
 Class square {
    store some stuff
    store pointers to squares (these are neighbors without a wall between them)
 }
 Then have a vector of these, which represents the maze.
 Now use __DEPTH FIRST SEARCH__ to solve this. We didn't cover exactly what this is since implementation details took a while.
 
 */

//#include <iostream>
//using namespace std;
//
//int main() {
//
//    return 0;
//}
//
//  main.cpp
//  Week 7 Tuesday
//
//  Created by James Chapman on 11/8/21.
//
// [1] - C. Horstmann "Big C++: Late Objects" 3rd edition

//#include <iostream>
//
////1. Give the big O notation for the following: [1] exercise R12.3
//// f(n) is O(g(n)) if f(n) <= C g(n) for large n for some constant C
///*
// a. n^2 + 2n + 1                    | O(n^2)
// b. n^10 + 9n^9 + 20n^8 + 145n^7    | O(n^10)
// c. (n+1)^4                         | O(n^4)
// d. (n^2 + n)^2                     | O(n^4)
// e. n + .001 n^3                    | O(n^3)
// f. 1000n^5 + 10^9                  | O(n^5)
// g. n + log(n)                      | O(n)
// h. n^2 + n log(n)                  | O(n^2)
// i. 2^n + n^2                       | O(2^n)
// j. (n^3 + 2n)/(n^2 + .75)          | O(n)
// */
//
////2. Order the following from smallest to largest: [1] exercise R12.7
///*
// O(n)
// O(log n)
// O(2^n)
// O(n sqrt(n))
// O(n^3)
// O(n^2 log(n))
// O(sqrt(n))
// O(n^log(n))
// O(n^n)
// O(n log(n))
//
// log(n)     sqrt(n)     n       n log(n)    n sqrt(n)   n^2 log(n)      n^3     n^log(n)    2^n     n^n
//
// 2^n, n^n, n^log(n)     n^n is biggest since n > 2 eventually and n > log(n) eventually
//
// n^log(n) < 2^n
//
// n^log(n) = (2^log_2(n))^log(n) = 2^(log_2(n) * log(n)) = 2^(c log(n)^2) < 2^n
// log(n)^2 < n eventually
// */
//
////3. Compute the run time of the following programs
///*
// a. Find an element in an array
// b. Find an element in a sorted array
// c. Randomly shuffling an array until there is a 90% chance it is sorted
// d. Towers of Hanoi solver
// e. Time to do a dot product
// f. Time to "naively" multiply an mxn matrix with an nxk matrix
// g. Factoring a number with n digits. Can call the number m.
// h. Add two numbers
// i. Multiply two numbers
//
//
// a. O(n)
// b. recurrence is f(n) = 3 + f(n/2) which gives O(log(n))
// c.
// Guesses: O(n!^n)   O(n!*.9^(-n))   O(n!^n)
//
// 1-(1-p)^m > .9     where p = 1/n!
// (1-p)^m < .1
// m log(1-p) < log(.1)       log(1-p) < 0
// m > log(.1) / log(1-p)     log(1-p) is approximately -p = -1/n!
// m > -log(.1) n!
// O(n!)
//
// C is our confidence instead of 90%
// m > -log(1-C) n! = n! log(1/(1-C))
// O(n! log(1/(1-C)))
//
// //MARK: CORRECTION
// m is O(n!), but each step take O(n) time, so we have that the problem is m * O(n) = O(n*n!) time
// Correspondingly, we get O(n n! log(1/(1-C)))
//
//
// */
//
//// Further Reading on complexity theory:
//// https://en.wikipedia.org/wiki/Computational_complexity_theory
//// https://en.wikipedia.org/wiki/P_versus_NP_problem
//
//// Challenge Problems:
//// Show that for all epsilon > 0 you can do matrix multiplication in O(n^(2+epsilon)) where you have nxn matrices
//// Show that boolean satisfyability is NP-complete
//// Show that 3-SAT is NP-complete
//
//int main() {
//
//    return 0;
//}
//
//  LinkedList.cpp
//  Week 8 Tuesday
//
//  Created by James Chapman on 11/16/21.
//

//#include "LinkedList.hpp"
//
//
//Node::Node(int x) : prev(nullptr), next(nullptr), data(x) {};
//
//void Node::setPrev(Node* p) {
//    prev = p;
//}
//
//void Node::setNext(Node* p) {
//    next = p;
//}
//
//void Node::set(int x) {
//    data = x;
//}
//int Node::get() {
//    return data;
//}
//
//
//LinkedList::LinkedList() : beg(nullptr), end(nullptr), cur(nullptr), size(0) {};
//
//Node* LinkedList::getBeg() {
//    return beg;
//}
//
//Node* LinkedList::getEnd() {
//    return end;
//}
//
//void LinkedList::operator++() {
//    if(cur != end)
//        cur = cur->next;
//}
//
//void LinkedList::operator--() {
//    if(cur != beg)
//        cur = cur->prev;
//}
//
//void LinkedList::insert(int x) {
//    Node* p = new Node(x);
//    if(size == 0) {
//        beg = p;
//        cur = p;
//        end = p;
//    }
//    else {
//        p->prev = cur->prev;
//        p->next = cur;
//        cur->prev = p;
//        (p->prev)->next = p;
//        cur = p;
//    }
//    //TODO: Need to handle edge cases: beginning and end
//    size++;
//}

////
////  main.cpp
////  Week 8 Thursday
////
////  Created by James Chapman on 11/17/21.
////
//// [1] - C. Horstmann "Big C++: Late Objects" 3rd edition
//
//#include <iostream>
//#include <list>
//#include <cassert>
//#include <cmath>
//
//using namespace std;
//
////1. Write a recursive function to print a list
//void listPrinterHelper(list<int>& L, list<int>::iterator pos) {
//    if(pos == L.end())
//        return;
//    cout << *pos << " ";
//    pos++;
//    listPrinterHelper(L, pos);
//    return;
//}
//
//void listPrinter(list<int>& L) {
//    /*for(list<int>::iterator pos = L.begin(); pos != L.end(); pos++)
//        cout << *pos << " ";
//    cout << endl;*/
//    listPrinterHelper(L, L.begin());
//    cout << endl;
//}
//
//
////2. Write a recursive function to get the maximum of a list
//int myMaxHelper(list<int>& L, list<int>::iterator pos) {
//    if(pos == L.end()--)
//        return *pos;
//    int tmp = *pos;
//    pos++;
//    return max(tmp, myMaxHelper(L, pos));
//}
//
//int myMax(list<int>& L) {
//    /*
//    list<int>::iterator pos = L.begin();
//    int tmp = *pos;
//    while(pos != L.end()) {
//        if(*pos > tmp)
//            tmp = *pos;
//        pos++;
//    }
//    return tmp;*/
//    return myMaxHelper(L, L.begin());
//}
//
//
////3. Write a class for a polynomial that stores it as a list    [1]
///*
// p(x) = 5 x^10 + 9 x^7 - x - 10 would be stored in a list as (5, 10), (9, 7), (-1, 1), (10, 0)
// Implement:
//    A. printing (nicely like a polynomial)          operator<<
//    B. addition                                     operator+
//    C. multiplication                               operator*
//    D. Evaluation at a point                        .eval(double)
//    E. Test these on the above polynomial
//    F. If time do differentiation and integration   .derivative()   and     .integral(double)
// */
//
//class Term {
//public:
//    Term(double c, int e) : coeff(c), exp(e) {assert(e >= 0);}
//
//private:
//    double coeff;
//    int exp;
//
//    Term operator+(Term other) {assert(exp == other.exp); return Term(coeff+other.coeff, exp);}
//    Term operator-(Term other) {assert(exp == other.exp); return Term(coeff-other.coeff, exp);}
//    Term operator*(Term other) {return Term(coeff * other.coeff, exp + other.exp);}
//
//    friend ostream& operator<<(ostream& out, Term data) {out << data.coeff << " x^" << data.exp; return out;}
//
//    friend class Polynomial;
//};
//
//// (a, b) + (c, d) = (a+c, b) if b == d     a x^b + c x^d = (a + c)x^b if b == d
////
//
//class Polynomial {
//private:
//    list<Term> L;
//
//public:
//    Polynomial(Term t) {L.push_back(t);}
//    Polynomial() {};
//
//    //Used to add more terms to a polynomial.
//    void operator+=(Term t) {
//        //Need to check if there is already a term of the same exponent as t
//        for(list<Term>::iterator pos = L.begin(); pos != L.end(); pos++) {
//            if(pos->exp == t.exp) {
//                pos->coeff += t.coeff;
//                return;
//            }
//        }
//        L.push_back(t);
//    }
//
//    Polynomial operator+(Polynomial& other) {
//        Polynomial p;
//        //Loop through to copy
//        for(list<Term>::iterator pos = L.begin(); pos != L.end(); pos++)
//            p.L.push_back(*pos);
//        //Loop through the other polynomial and add each term using the += operator
//        for(list<Term>::iterator pos = other.L.begin(); pos != other.L.end(); pos++)
//            p += *pos;
//        return p;
//    }
//
//    Polynomial operator-(Polynomial& other);
//    Polynomial operator*(Polynomial& other);
//
//    double eval(double x) {
//        double result = 0;
//        for(list<Term>::iterator pos = L.begin(); pos != L.end(); pos++) {
//            result += pos->coeff * pow(x, pos->exp);
//        }
//        return result;
//    }
//
//    friend ostream& operator<<(ostream& out, Polynomial& data);
//
//    Polynomial derivative();
//    Polynomial integral(double c);
//
//};
//
//
////Challenge Problem:
////1. Write code to find a real root of an odd degree, real valued polynomial
////2. Come up with an algorithm to find all roots of a polynomial (including complex roots)
//
//int main() {
//    list<int> L;
//    L.push_back(1);
//    L.push_back(2);
//    L.push_back(3);
//    listPrinter(L);
//    cout << myMax(L) << endl;
//
//
//
//    return 0;
//}
//

////  main.cpp
////  Week 9 Tuesday
////
////  Created by James Chapman on 11/22/21.
////
//// [1] - C. Horstmann "Big C++: Late Objects" 3rd edition
////MARK: I forgot to save the 2A notes, but these are very similar. Watch the recording for any slight differences.
///*
// Homework Advice:
// 1. Start early
// 2. Think about all the different cases (general and edge cases)
//    - Empty list
//    - 1 node
//    - 2 nodes
//    - many nodes
//    - etc.
// 3. Test your code on all these different cases
//    - Just write some code in your main function to test that things are working correctly in these cases
//    - Don't submit this code, just use it for yourself.
// 4. Test code on VS19
// */
//
//#include <iostream>
//#include <vector>
//#include <set>
//
//using namespace std;
//
////1. [1] - Implement union and intersection of sets
////Do this with for(int x : a) after
//// {1, 2, 3} union      {3, 4, 5}   = {1, 2, 3, 4, 5}
//// {1, 2, 3} intersect  {3, 4, 5}   = {3}
//set<int> set_union(const set<int>& a, const set<int>& b) {
//    set<int> u;
//    /*
//    //for(set<int>::iterator pos = a.begin(); pos != a.end(); pos++)
//    //    u.insert(*pos);
//    for(set<int>::iterator pos = b.begin(); pos != b.end(); pos++)
//        u.insert(*pos);
//     */
//    for(int x : a)
//        u.insert(x);
//    for(int x : b)
//        u.insert(x);
//    return u;
//}
//
//
//set<int> intersection(const set<int>& a, const set<int>& b) {
//    set<int> i;
//    /*
//    for(int x : a) {
//        for(int y : b) {
//            if(x == y) {
//                i.insert(x);
//                break;
//            }
//        }
//    }*/
//    for(int x : a) {
//        if(b.count(x) == 1)
//            i.insert(x);
//    }
//
//    return i;
//}
//
//
//
////2. Templates:
///*
// Lets you define functions that could take different input types but which do the same thing
// This is just operator overloading going on behind the scenes
// Can not have template files separated between .hpp and corresponding .cpp files. Put the definition in the .hpp file.
// Template functions are compiled when needed
// template <typename T> or template <typename T, typename U, ...>
// */
////a. Write a function to print a vector of any type
////b. Write a function to get the max of a vector of any type (the type needs an ordering)
////c. Write a function to reverse a vector of any type
//
////MARK: Part a
//// {3, 2, 1}    {3.0, 2.0, 1.0}
//// 321 -> 231 -> 213 -> 123
//// 321 -> 231 -> 213 -> 123     //pretend these are doubles
//// Lets just write the code once
//
//template <typename T>
//void vecPrinter(vector<T> v) {
//    for(T x : v)
//        cout << x << " ";
//    cout << endl;
//}
//
//template <typename T, typename U>
//void vecPrinter2(vector<T> v1, vector<U> v2) {
//    for(T x : v1)
//        cout << x << " ";
//    for(U x : v2)
//        cout << x << " ";
//    cout << endl;
//}
//
//template <typename T>
//T myMax(vector<T> v) {
//    T guessMax = v[0];
//    for(T x : v) {
//        if(x > guessMax)
//            guessMax = x;
//    }
//    return guessMax;
//}
//
//class TestClass {
//private:
//    int x;
//public:
//    TestClass(int x) : x(x) {};
//};
//
////3. Define a function called AbstractSet that takes a truth statement to create the set
////  Use templates
///*  ex. 1   {x a real number : x > 0}
//        2   {x : sqrt(x) is an integer}
//        3   {(x, y) : x^2 + y^2 < 1}
// */
//
//
//
//
//TODO: binary tree: node is pointer to other nodes that are their children
//TODO: linked list: node is pointer to every single other node?
//TODO: Running time R(n) = O(n) = C*n, running time is no greater than linear
//int main() {
//
//    //AbstractSet<int> mySet;
//
//    vector<int> v1 = {1, 2, 3};
//    vector<double> v2 = {1.1, 2.2, 3.3};
//    vecPrinter(v1);
//    //Is there a vecPrinter(vector<int>). No but there is a template function like this.
//    //Create a void vecPrinter(vector<int>) based on the template function.
//    //Runs this version.
//    vecPrinter(v2); //Does same thing and now we have a vecPrinter(vector<double>)
//
//    vecPrinter2(v1, v2); //vecPrinter2(vector<int>, vector<double>)
//
//    cout << myMax(v1) << endl;
//    cout << myMax(v2) << endl;
//
//    vector<TestClass> v;
//    for(int i = 1; i <= 3; i++) {
//        v.push_back(TestClass(i));
//    }
//    //myMax(v);
//
//
//    return 0;
//}
//#include <iostream>
//#include <list>
//#include <iterator>
//using namespace std;
//
////function for printing the elements in a list
//void showlist(list <int> g){
//    list <int> :: iterator it;
//    for(it = g.begin(); it != g.end(); ++it)
//        cout << ' ' << *it;
//    cout << endl;
//}
//
//
//int main() {
//    list <int> gqlist1, gqlist2;
//    for (int i = 0; i < 10; ++i) {
//        gqlist1.push_back(i * 2);
//        gqlist2.push_front(i * 3);
//    }
//    cout << "\nList 1 (gqlist1) is : ";
//    showlist(gqlist1);
//
//    cout << "\nList 2 (gqlist2) is : ";
//    showlist(gqlist2);
//    cout << "\ngqlist1.front() : " << gqlist1.front();
//    cout << "\ngqlist1.back() : " << gqlist1.back();
//    cout << "\ngqlist1.pop_front() : ";
//    gqlist1.pop_front();
//    showlist(gqlist1);
//    cout << "\ngqlist2.pop_back() : ";
//    gqlist2.pop_back();
//    showlist(gqlist2);
//    cout << "\ngqlist1.reverse() : ";
//    gqlist1.reverse();
//    showlist(gqlist1);
//    cout << "\ngqlist2.sort(): ";
//    gqlist2.sort();
//    showlist(gqlist2);
//    return 0;
//}
//


//  main.cpp
//  Week 10 Tuesday
//
//  Created by James Chapman on 11/29/21.
//
// [1] - C. Horstmann "Big C++: Late Objects" 3rd edition
/*
 Please fill out the instructor evaluations
 I would also love to hear your opinions on the hybrid class format
 
 map:
 Include map and utility for all functionality
 map<type1, type2> name;
 
 name[key1] = val1;
 name[key2] = val2;
 ...
 
 map<type1, type2>::iterator pos lets us iterate through
 name.find(key) gives iterator. Gives name.end() if no match.
 
 
 */

//#include <iostream>
//#include <map>
//#include <utility>
//using namespace std;
//
////1. [1] R16.7 - Consider a binary tree. Insert the following elements. What does it look like after.
//// Adam, Eve, Romeo, Juliet, Tom, Diana, Harry
//
////2. [1] R16.12 - Come up with an algorithm to determine if two trees have the same shape. What is the running time?
////ISOMORPHIC tree
//// TODO: general direction is recursvie function
//// TODO: check if both roots have both children
///* if both roots have both children
//    if ( sameTree(T1.left, T2.left) and sameTree(T1.right, T2.right))
//    return true
//    if both roots have only left child
//        if (sameTree(T1.left, T2.left))
//            return true
//    if both roots have only right child
//        if (sameTree(T1.right, T2.right))
//            return true
//    if both roots have no children
//        return true
// return false;
//*/
////3. Write pseudocode to compute the height of a binary tree.
///*
// TODO: recursive
// h(T) = max (h(T.left), h(T.right))
// BC is if T is null then return or if T is a leaf then return 1
// int h(T)
//    if T has no children (is a leaf)
//        return 1
//    if T has left child only
//        return 1 + h(T.left)
//    if T has right child only
//        return 1 + h(T.right)
//    if T has both children
//        return 1 + max(h(T.left),h(T.right))
// */
////4. [1] E15.5 - Write a function that takes a string as input and returns letter counts in a map.
////  ex. elephant -> [a : 1, b : 0, ..., e : 2, ..., z : 0]
///*
// map<char, int> letterCounts(string s);
// */
////map<char, int> letterCounts(string s){
////    map<char,int> out;
////    for (char c = 'a'; c <= 'z'; c++)
////        out[c]=0;
////    for (char c: s)
////        out[c]++;
////}
////5. [1] P15.4 - Read in words from a string and store them in a multimap where the key is the number entered on a phone
////  ex. 26337 -> {"Andes", "coder", "codes", ...}
///*
// #'s    Letters
// 2      abc
// 3      def
// 4      ghi
// 5      jkl
// 6      mno
// 7      pqrs
// 8      tuv
// 9      wxyz
// //Write a function to convert words into these digits - do this by character
// //Have to read in a long word list
// //Fill out a multimap(int,string> with all these words
// */
////int charToNum(char c) {
////    if('a <= c && c <+ 'c') return 2;
////    if('d'<= c && c <= 'f') return 3;
////       if('a <= c && c <+ 'c') return 2;
////       if('d'<= c && c <= 'f') return 3;
////}
//
//
////Challenge Problem: Write your own implementation of a binary search tree
////  - Write a function to balance the tree
////  - Write insert and remove functions that keep the tree balanced
//
//int main() {
//
//    return 0;
//}
