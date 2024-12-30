//
//  main.cpp
//  Week 3 Thursday
//
//  Created by James Chapman on 10/12/21.
//

//TODO: GO OVER CODE FROM TUESDAY AT START

#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;

//1. Write a function tablePrinter() that takes a vector of inputs and a function and prints out a table like
/*
 x[0]   f(x[0])
 x[1]   f(x[1])
 ...
 x[n-1] f(x[n-1])
 */
double square(double x){
    return x*x;
}
double cubed (double x){
    return x*x*x;
}
void tablePrinter(vector<double> inputs, double (*f) (double)){
    for(int i = 0; i < inputs.size(); i++)
    {
        cout << inputs[i] << "    " << f(inputs[i])<< endl;
    }
}

//2. Write a class to store matrices. This can also be thought of as a 2d grid of values. Do not use vectors
//  Hint: If you are stuck, try doing this with vectors first.
//  Bonus: implement addition, multiplication, determinant, trace, etc.

class Matrix {
private:
    int nrows;
    int mcolumns;
    std::vector <std::vector<double>> mat ;
public:
    Matrix(int rows, int columns, vector <double> v);                           //Write some reasonable constructors
    ~Matrix();                          //I will program this function
    
    void display();                     //displays the matrix
    double at(int r, int c);            //Accesses the value in the r'th row and c'th column
    double set(int r, int c, double x); //Sets the value in the r'th row and the c'th column
    
    Matrix operator+(Matrix& other); //optional
};

/*3. Implement the following classes
 
                  Shape3d
    /           /          \          \
 RectCube   Ellipsoid   Cylinder    Pyramid
    |           |
   Cube       Sphere
 
 This will be similar to the Shape2d exercise
 A. Use Point3d
 B. Start by programming Shape3d
    - Stores center
    - Has a function to move the shape
 C. Use inheritance
 D. Implement surfaceArea() and volume() functions
 */

class Point3d {
public:
    double x[3];
    
    Point3d(double arr[3]) {
        for(int i = 0; i < 3; i++)
            x[i] = arr[i];
    }
    
    Point3d(double a, double b, double c) {
        x[0] = a;
        x[1] = b;
        x[2] = c;
    }
    
    double norm() {
        return sqrt(x[0]*x[0] + x[1]*x[1] + x[2]*x[2]);
    }
    Point3d operator+(Point3d other) {
        return Point3d(x[0] + other.x[0], x[1] + other.x[1], x[2] + other.x[2]);
    }
    
    Point3d operator-(Point3d other) {
        return Point3d(x[0] - other.x[0], x[1] - other.x[1], x[2] - other.x[2]);
    }
    
    void display() {
        std::cout << "(" << x[0] << ", " << x[1] << ", " << x[2] << ")" << std::endl;
    }
};


int main() {
    vector <double> v {1,2,3};
    return 0;
}
