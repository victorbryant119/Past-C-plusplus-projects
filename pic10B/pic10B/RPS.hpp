//
//  RPS.hpp
//  pic10B
//
//  Created by Victor Shi on 10/7/21.
//

#ifndef RPS_hpp
#define RPS_hpp

#include <stdio.h>
#include "main.cpp"
#include <iostream>
private:
    std::string name;
    RPS* beats;
    
public:
    RPS(std::string name, RPS* beats);
    
    void updateName(std::string newName);
    void updateBeats(RPS* newBeats);
};
//5. Write a class called RPS (stands for rock paper scissors). The hpp file outlines some important functions.
#endif /* RPS_hpp */
