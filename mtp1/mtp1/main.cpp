//
//  main.cpp
//  mtp1
//
//  Created by Victor Shi on 11/2/21.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int string_to_int(string s)
  {
      istringstream instr(s);
   int n;
   instr >> n;
return n;
  }
bool isSame(int x, double y)
      {
          return true;
      }
int main(int argc, const char * argv[]) {
//    string s1, s2, s3;
//    char ch1, ch2, ch3;
//    double d1, d2, d3, last4;
//    int i1, i2, i3;
//    istringstream abc("Phone: (123)12.1234");
//    abc >> s1 >> ch1 >> i1 >> ch2 >> i2 >> ch3 >> last4;
//    cout << last4 << endl;
//    int i = string_to_int("1333");
//    cout << i << endl;
//    string input = "January 23, 1955";
//        istringstream instr(input);
//        string month;
//        int day;
//        string comma;
//        int year;
//        instr >> month >> day >> comma >> year;
//    cout << month << day <<comma << year;
//   bool FunPrt = *isSame;
//    bool (*FunPrt)(int,double)=isSame;
    int myarray[6]={1,2,3,4,5,6};
    cout << *(myarray+5)<< endl;
    return 0;
}
