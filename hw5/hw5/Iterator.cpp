/*
        PIC 10B 2B, Homework 5
        Purpose: Linked List of int types
        Author: Wenchen Shi
        Date: 11/24/2021
*/
#include <array>
#include "Iterator.h"
#include <iostream>
#include <stdio.h>
#include <cassert>
using namespace std;
Iterator::Iterator(){
    position = NULL;
    container = NULL;
}
Node* Iterator::get_position()
{
    return position;
}
int Iterator::operator*() const
{
    assert(position != nullptr);
    return position->value;
}
Iterator& Iterator::operator++(int x)
{
    assert(position != nullptr);
    position = position->next;
    return *this;
}
Iterator& Iterator::operator--(int x)
{
    assert(position != nullptr);
    position = position->previous;
    return *this;
}
bool Iterator::operator==(const Iterator& b)
{
    return position == b.position;
}
bool Iterator::operator!=(const Iterator& b)
{
    return position != b.position;
}
