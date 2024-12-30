/*
        PIC 10B 2B, Homework 5
        Purpose: Linked List of int types
        Author: Wenchen Shi
        Date: 11/24/2021
*/
#include <iostream>
#include <stdio.h>
#include <cassert>
#ifndef Node_h
#define Node_h
using namespace std;
class Iterator;
class List;
class Node {
public:
    Node ();
    Node (int val);
    Node* get_next();
private:
    int value;
    Node* previous;
    Node* next;
    friend class List;
    friend class Iterator;
};

#endif /* Node_h */
