/*
        PIC 10B 2B, Homework 5
        Purpose: Linked List of int types
        Author: Wenchen Shi
        Date: 11/24/2021
*/
/*
//TODO: NOTE: the print out of list does not have the last number included in visual studio, however, it works perfectly fine on XCODE FIXXED
 ////TODO: function won't print out in visual studio, worked well on XCode
 //TODO: tried using pointer instead, worked on XCode, however generated errors on visual studio
 //TODO: ended up deleting destructor in order to make the errors go away
*/
#include <iostream>
#include <stdio.h>
#include "List.h"
#include "Node.h"
#include "Iterator.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(int argc, const char * argv[]) {
    List list;
    List newList;
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(5);
    newList.push_back(7);
    newList.push_back(11);
    Iterator Iterator;
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    cout << "Please input a set of nonnegative numbers for a List" << endl;
    cout << "(Enter -1 when you are finished): " << endl << endl;
    int input = 0;
    while(true)
    {
        cin >> input;
        if (input < 0)
            break;
        else
            list.push_back(input);
    }
    cout << "Your list is: " << endl;
    cout << "(";
    for (Iterator = list.begin(); Iterator!=list.end(); Iterator++)
    {
        if (count < list.get_size()-1)
            cout << *Iterator << ", ";
        else
            cout << *Iterator;
        count++;
    }
    //Visual studio error, Xcode prints out the last number in the for loop above FIXEDD!
    cout << ")" << endl << endl;
// check insertion and then augmented list
    int index = 0;
    int value = 0;
    while (true)
    {
        cout << "Select an index for insertion (enter -1 when finished): ";
        cin >> index;
        if (index == -1)
            break;
        cout << "Select a value for insertion: ";
        cin >> value;
        if (value == -1)
            break;
        //testing
//        list.push_front(list.begin(), value);
        list.insert(list.begin(), value, index);
    }
    cout << endl << endl;
    cout << "The augmented list is: "<< endl;
    cout << "(";
    for (Iterator = list.begin(); Iterator!=list.end(); Iterator++)
    {
        if (count2 < list.get_size()-1)
            cout << *Iterator << ", ";
        else
            cout << *Iterator;
        count2++;
    }
    cout << ")" << endl << endl;
    cout << "When we sort the previous list we obtain" << endl;
    cout << "(";
    // call the sort function
     list.sort();
    for (Iterator = list.begin(); Iterator!=list.end(); Iterator++)
    {
        if (count3 < list.get_size()-1)
            cout << *Iterator << ", ";
        else
            cout << *Iterator;
        count3++;
    }
    cout << ")" << endl;
    //reverse list
    cout << "And this sorted list in reverse order is"<< endl;
    cout << "(";
    list.reverse();
    for (Iterator = list.begin(); Iterator!=list.end(); Iterator++)
    {
        if (count4 < list.get_size()-1)
            cout << *Iterator << ", ";
        else
            cout << *Iterator;
        count4++;
    }
    cout << ")" << endl;
    cout << "If we merge this list with the list ";
    //print out the list
    cout <<" (";
    for (Iterator = newList.begin(); Iterator!=newList.end(); Iterator++)
    {
        if (count6 < newList.get_size()-1)
            cout << *Iterator << ", ";
        else
            cout << *Iterator;
        count6++;
    }
    cout << ")";
    //end of the print out of newlist
    cout << " we obtain" << endl;
    cout <<"(";
//    List* mergelist = list.merge(newList);
    //mergelist->begin() mergelist->end() mergelist->get_size()-1
    List mergelist = list.merge(newList);
    for (Iterator = mergelist.begin(); Iterator!=mergelist.end(); Iterator++)
    {
        if (count5 < mergelist.get_size()-1)
            cout << *Iterator << ", ";
        else
            cout << *Iterator;
        count5++;
    }
    cout << ")" << endl;
    //delete pointer
//    delete mergelist;
    return 0;
}
