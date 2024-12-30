/*
       PIC 10B 2B, Homework 3
       Purpose: comparing two files
       Author: Wenchen (Victor) Shi
       Date: 11/5/2019
*/
#ifndef textfile_h
#define textfile_h
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
class textfile
{
    private:
        std::ifstream* fin;
        std::string filename;
        int linecount = 0;
    public:
        textfile(std::ifstream* fin);
        int characternumber (std::ifstream &fin);
        int wordnumber (std::ifstream &fin);
        void linecounting (std::ifstream &fin);
        bool comparetwofiles ();
        void set_name (std::string newname);
        std::string get_name ();
        bool operator>(textfile &a);
        bool operator==(textfile &a);
};

#endif /* textfile_hpp */
