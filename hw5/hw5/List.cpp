/*
        PIC 10B 2B, Homework 5
        Purpose: Linked List of int types
        Author: Wenchen Shi
        Date: 11/24/2021
*/
#include "List.h"
#include <iostream>
#include <stdio.h>
#include <cassert>
using namespace std;
List::List(){
    size = 0;
    first = nullptr;
    last = nullptr;
}
//destructor to clean up all the new pointers
//List::~List(){
//    //run through every node to delete pointers
//    for (Iterator pos = this->begin(); pos!= this->end(); pos++)
//    {
//        delete pos.position;
//    }
//}
Iterator List::begin()
{
    Iterator iter;
    iter.position = first;
    iter.container = this;
    return iter;
}
Iterator List::end()
{
    Iterator iter;
    iter.position = nullptr;
    iter.container = this;
    return iter;
}
//help non-members get size
// not necessary but good for codetesting
int List::get_size(){
    return size;
}
void List::push_back(int data)
{
    Node* newNode = new Node(data);
    if (last == nullptr)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        newNode->previous = last;
        last->next = newNode;
        last = newNode;
    }
    size++;
}
//provided by professor's notes
Iterator List::erase(Iterator iter)
{
    assert(iter.position!= NULL);
    Node* remove = iter.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    if (remove == first)
        first = after;
    else
        before->next = after;
    if (remove == last)
        first = before;
    else
        after->previous = before;
    delete remove;
    Iterator r;
    r.position = after;
    r.container = this;
    size--;
    return r;
}
// similar to push back except insert from the end
void List::push_front(Iterator pos, int data)
{
    Node* newNode = new Node(data);
    newNode->next=pos.position;
    pos.position->previous=newNode;
    first = newNode;
    size++;
}
//provided by professor but made major changes
//take in index
void List::insert(Iterator pos,int data, int index)
{
    Node* newNode = new Node(data);
    //use pushfront to insert at the beginning
    if (index == 0)
    {
        push_front(pos, data);
        return;
    }
    //use pushback to insert at the end
    else if (index == get_size())
    {
        push_back(data);
        return;
    }
    for (int i=0; i<index-1; i++)
    {
        pos++;
    }
    newNode->next=pos.position->next;
    newNode->previous = pos.position;
    pos.position->next = newNode;
    newNode->next->previous = pos.position->next;
    size++;
}
// put the numbers in the correct order
// compare and swap position
// push_front,size--
//bubble sort, sort up the elements to its current position
//draw graphs
void List::sort()
{
    // nested loop: to
    // Need to update the nodes inside the list
    // the initial condition should be related to size
    bool isSorted = false;
    Iterator iter2;
//    iter2 = begin();
    for (int i=0; i<size-1; i++)
    {
        iter2=begin();
        for (int j=0; j<size-i-1; j++)
        {
            //need to update the nodes inside the list
            //swap the position of current with the position of next
            if (iter2.position->next==nullptr)
            {
                break;
            }
            if (*iter2 > iter2.position->next->value)
            {
                int temp = iter2.position->value;
                iter2.position->value = iter2.position->next->value;
                iter2.position->next->value = temp;
                isSorted = false;
            }
                iter2++;
        }
    }
}

//reverse the list
void List::reverse()
{
   // use current1 to change the pointers as a sacrifice
    //always have two pointers to reserve pointer spots
    Node* current = first;
    Node* prev = NULL;
    Node* next = NULL;
//    while (current2 != nullptr)
    while (current != NULL)
    {
//        current2->next = current2->previous;
//        current2->previous = current1;
//        current1 = current2;
//        current2 = current2->previous;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    //current two and one are next to each other
    // if current2 is null then current 1 is last
//    last = current1;
    first = prev;
}

// return a list instead of doing void
//List* List::merge(List& newList)
//{
//    List* list = new List;
//    //keep count and update the new size of the merged list
//    int sizecount = size;
//    Iterator a = this->begin();
//    Iterator b = newList.begin();
//    for (int i = 1; i<sizecount-1; i++)
//    {
//        if (a!= this->end())
//        {
//            (*list).push_back(*a);
//            a++;
//        }
//        if (b!= newList.end())
//        {
//            (*list).push_back(*b);
//            //increment the sizecount added from the newList
//            sizecount++;
//            b++;
//        }
//    }
//    return list;
//}
//TODO: function won't print out in visual studio, worked fine on XCode
//TODO: tried using pointer instead, worked on XCode, however generated errors on visual studio
List List::merge(List& newList)
{
//    List* list = new List;
    List list;
    //keep count and update the new size of the merged list
    int sizecount = size;
    Iterator a = this->begin();
    Iterator b = newList.begin();
    for (int i = 1; i<sizecount-1; i++)
    {
        if (a!= this->end())
        {
            list.push_back(*a);
            a++;
        }
        if (b!= newList.end())
        {
            list.push_back(*b);
            //increment the sizecount added from the newList
            sizecount++;
            b++;
        }
    }
    return list;
}
