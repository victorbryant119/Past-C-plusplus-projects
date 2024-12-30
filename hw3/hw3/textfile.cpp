/*
       PIC 10B 2B, Homework 3
       Purpose: comparing two files
       Author: Wenchen (Victor) Shi
       Date: 11/5/2019
*/
// operator overloading, File I/O
//JFMAbstract.txt
//PhysicaDAbstract.txt
#include "textfile.h"
#include <iostream>
#include <string>
#include <fstream>
textfile::textfile(std::ifstream* fin){
}
// count the character number
int textfile::characternumber (std::ifstream &fin)
{
    int count = 0;
    std::string s;
    //private varaible number of words, if
    //character will be like the main function (counter should be void) to increment wordnumber and characternumber,
    //and then we have getters for character number and wordnumber
    char character = 0;
    //count character by character
    while (fin.get(character))
    {
            count++;
        //consulted with TA, since there is apparent messy counts towwards endline, we decrement by 2
        if (character=='\n')
        {
            count=count-2;
        }
    }
    return count;
}
int textfile::wordnumber (std::ifstream &fin)
{
    //clean up the pointer and restart
    fin.clear();
    fin.seekg(std::ios::beg);
    int count = 0;
    std::string s;
    char character = 0;
    //go through the whole text character by character
    while (fin.get(character))
    {
        //since words are separated by spaces, increment when a space is spotted
        if (character == ' ')
            count++;
        //consulted with TA, when reaching endline, due to the messiness, we decrement the counts by two, also since endline spaces are not indications of a word (after the first one)
        if (character=='\n')
        {
            count=count-2;
        }
    }
    //there are two times with two spaces in a row
    return (count-2);
}
void textfile::linecounting (std::ifstream &fin)
{
    fin.clear();
    fin.seekg(std::ios::beg);
    std::string s;
// NOTE: save thought process for making future codes better
//    getline(fin,s);
//    char character = 0;
//    while (!fin.eof())
    //using getline to count one row at a time, thus incrementing linecount by 1
    while(getline(fin,s))
    {
//        if (character=='\n')
//        {
            linecount++;
//        }
    }
}
//operator overloading > and ==
bool textfile::operator >(textfile &a)
{
    //assume the operator is false until conditions met
    bool biggerthan = false;
    //similar to a.function(b) where one is implicit
    if (linecount> a.linecount)
        return biggerthan = true;
    else
        return false;
}
bool textfile::operator==(textfile &a)
{
    bool equal = false;
    if (linecount==a.linecount)
        return equal = true;
    else
        return false;
}
