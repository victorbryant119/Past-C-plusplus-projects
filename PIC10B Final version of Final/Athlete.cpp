/*
    PIC 10B, Final Exam - Part 2
    Problem 2: Team Athlete
    Author: Wenchen(Victor) Shi
    Date: 12/08/2021
*/
#include <stdio.h>
#include "Athlete.h"
//Constructor: initialize all variables

Athlete::Athlete(int new_athlete_ID, double new_vo2, double new_reaction_time, int new_balance, int new_strength, double new_mile_time): athlete_ID(new_athlete_ID),vo2(new_vo2),reaction_time(new_reaction_time),balance(new_balance),strength(new_strength),mile_time(new_mile_time){
    performance = (vo2/mile_time)+(strength*balance)/(1+reaction_time)/(1+reaction_time);
}

//implement all getter functions

int Athlete::get_athlete_ID() const
{
    return athlete_ID;
}

double Athlete::get_vo2() const
{
    return vo2;
}

double Athlete::get_reaction_time() const
{
    return reaction_time;
}

int Athlete::get_balance() const
{
    return balance;
}

int Athlete::get_strength() const
{
    return strength;
}

double Athlete::get_mile_time() const
{
    return mile_time;
}

double Athlete::get_performance() const
{
    return performance;
}

//implement operator overloading
bool Athlete::operator<(const Athlete& other) const
{
    return performance<other.performance;
}

std::ostream& operator<<(std::ostream& outStream, const Athlete& value)
{
    outStream << "Athlete " << value.athlete_ID << " has performance " << value.get_performance();
    return outStream;
}
