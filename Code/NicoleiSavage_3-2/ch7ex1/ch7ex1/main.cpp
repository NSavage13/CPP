//
//  main.cpp
//  ch7ex1
//
//  Created by Nico Savage on 4/25/23.
//
/*
 Define an enumeration type triangleType that has the values scalene, isosceles, equilateral, and noTriangle.

 Write a function triangleShape that takes as parameters three numbers, each of which represents the length of a side of the triangle. The function should return the shape of the triangle. (Note: In a triangle, the sum of the lengths of any two sides is greater than the length of the third side.)

 Write a program that prompts the user to input the length of the sides of a triangle and outputs the shape of the triangle.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

enum triangleType {scalene, isosceles, equilateral, noTriangle};

// triangleType declares the type of return for the function
triangleType triagnleShape(double s1,double s2,double s3){
    if (s1+s2<=s3 || s1+s3<=s2 || s3+s2<=s1){
        return noTriangle;
    }else if (s1==s2 && s1==s3){
        return equilateral;
    }else if(s1==s2 || s1==s3 || s2==s3){
        return isosceles;
    }else {
        return scalene;
    }
}

int main() {
    double a,b,c;
    
    cout << "Enter the length of three sides of a triangle.\n";
    cin >> a >> b >> c;
    
    triangleType type = triagnleShape(a, b, c);
    if(type == scalene){
        cout << "This is a scalene triangle.\n";
    }else if(type == isosceles){
        cout << "This is a isosceles triangle.\n";
    }else if(type == equilateral){
        cout << "This is a equilateral triangle.\n";
    }else {
        cout << "This is not a valid triangle.\n";
    }
    
    return 0;
}
