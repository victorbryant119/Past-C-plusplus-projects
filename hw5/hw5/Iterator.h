/*
        PIC 10B 2B, Homework 5
        Purpose: Linked List of int types
        Author: Wenchen Shi
        Date: 11/24/2021
*/
#include <iostream>
#include <stdio.h>
#include "Node.h"
#include <cassert>
#ifndef Iterator_h
#define Iterator_h
using namespace std;
class List;
class Node;
class Iterator{
private:
    Node* position;
//    const List* container;
    List* container;
    friend class List;
public:
    Iterator();
    Iterator begin();
    Iterator end();
    Node* get_position();
    int operator*() const;
    Iterator& operator++(int x);
    Iterator& operator--(int x);
    bool operator==(const Iterator& b);
    bool operator!=(const Iterator& b);
};
#endif /* Iterator_h */
