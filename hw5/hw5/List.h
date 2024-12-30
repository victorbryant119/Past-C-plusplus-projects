/*
        PIC 10B 2B, Homework 5
        Purpose: Linked List of int types
        Author: Wenchen Shi
        Date: 11/24/2021
*/
#include <iostream>
#include <stdio.h>
#include "Iterator.h"
#include "Node.h"
#include <cassert>
#ifndef List_h
#define List_h
using namespace std;
class Node;
class Iterator;
class List {
private:
    int size;
    Node* first;
    Node* last;
    friend class Iterator;
public:
    List();
    //destructor
//    ~List();
    //get the size of the list
    int get_size ();
    Iterator begin();
    Iterator end();
    void push_back(int data);
    Iterator erase (Iterator iter);
    // not provided by professor
    void push_front(Iterator pos, int data);
    void insert(Iterator pos, int data, int index);
    void sort();
    void reverse();
//    List* merge(List& newList);
    List merge(List& newList);
};
#endif /* List_h */
