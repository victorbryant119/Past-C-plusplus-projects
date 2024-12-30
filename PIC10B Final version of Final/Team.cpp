/*
    PIC 10B, Final Exam - Part 2
    Problem 2: Team Athlete
    Author: Wenchen(Victor) Shi
    Date: 12/08/2021
*/
#include <stdio.h>
#include "Team.h"
#include "Athlete.h"
#include <sstream>
#include <string>
#include <fstream>
#include <queue>

//implement constructor
//takes a filename as a parameter and initializes a team of athletes from the file. The format of the input file will match that of the example file sampleAthleteData.txt.
//TODO: file can be opened and all work done in XCode; however, file cannot be oepend in Visual Studio
//TODO: NOTE FOR TA: the performance values, return best athletes and remove best athletes all work well and leads to all correct outputs in visual studio confirmed by calculator's calculations
//TODO: confirmed Works on one version of visual studio

Team::Team(std::string fileName): team_size(0)
{
    int athlete_ID;
    double vo2;
    double reaction_time;
    int balance;
    int strength;
    double mile_time;
    std::ifstream fin(fileName);
    std::string s="";
    if (fin.is_open())
    {
//    fin.open(fileName);
    //skip the first line since it is the "titles"
    std::getline(fin,s);
    //go through each line to increment team size by 1
    while(std::getline(fin,s))
    {
        // use istringstream to extract integers from the line
        std::istringstream instr(s);
        instr >> athlete_ID >> vo2 >> reaction_time >> balance >> strength >> mile_time;
        Athlete a(athlete_ID, vo2, reaction_time, balance, strength, mile_time);
        myTeam.push(a);
        team_size++;
    }
    fin.close();
    }
}

//implement getter function

int Team::get_team_size()
{
    return team_size;
}

//Removes the best athlete and returns them
Athlete Team::pop_best()
{
    //keep position for the current top
    Athlete a = myTeam.top();
    //remove the current top
    myTeam.pop();
    //decrement the size
    team_size--;
    //return the current top that is deleted
    return a;
}

//Returns the best athlete
Athlete Team::peek_best() const
{
    return myTeam.top();
}
