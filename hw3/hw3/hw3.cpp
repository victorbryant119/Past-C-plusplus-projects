/*
       PIC 10B 2B, Homework 3
       Purpose: comparing two files
       Author: Wenchen (Victor) Shi
       Date: 11/5/2019
*/
//JFMAbstract.txt
//PhysicaDAbstract.txt
#include <iostream>
#include <string>
#include "textfile.h"
#include <fstream>
//bool operator >(textfile::textfile &a,textfile::textfile &b)
//{
//    if (a > b)
//        
//}
int main(int argc, const char * argv[]) {
    //declare ifstream for file intake
    std::ifstream fin1;
    std::ifstream fin2;
    std::string filename1;
    std::string filename2;
    int count1;
    int count2;
    int count3;
    int count4;
    std::cout << "Enter the name of file 1: ";
    //take in the filename
    getline(std::cin,filename1);
    fin1.open(filename1);
    //call the class textfile
    textfile file1(&fin1);
    //call the character and word number for file 1
    count1 = file1.characternumber(fin1);
    count3 = file1.wordnumber(fin1);
    std::cout << "Number of characters: " << count1 << std::endl;
    std::cout << "Number of words: " << count3 << std::endl;
    std::cout << "Enter the name of file 2: ";
    getline(std::cin,filename2);
    fin2.open(filename2);
    textfile file2(&fin2);
    //call the character and word number for file 2
    count2 = file2.characternumber(fin2);
    count4 = file2.wordnumber(fin2);
    std::cout << "Number of characters: " <<count2 << std::endl;
    std::cout << "Number of words: " << count4 << std::endl;
    std::cout << std::endl;
    file1.linecounting(fin1);
    file2.linecounting(fin2);
    //print out the conclusions
    if (file1>file2)
        std::cout << "The file named " << filename2 << "has less lines than " << filename1 << std::endl;
    else if (file1==file2)
        std::cout << "The file named " << filename2 << "has the same amount of lines as " << filename1 << std::endl;
    else
        std::cout << "The file named " << filename2 << "has more lines than " << filename1 << std::endl;
    return 0;
}
