/*
        PIC 10B 2B, Homework 5
        Purpose: Linked List of int types
        Author: Wenchen Shi
        Date: 11/24/2021
*/
#include <iostream>
#include <stdio.h>
#include "Node.h"
#include <string>
#include <cassert>
using namespace std;
Node::Node()
{
    previous = nullptr;
    next = nullptr;
}
Node::Node(int val){
    value = val;
    previous = nullptr;
    next = nullptr;
}
Node* Node::get_next()
{
    return next;
}
// implement the previous and next
