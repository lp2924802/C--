/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Postl
 *
 * Created on January 4, 2022, 5:16 PM
 */

/*
 * Homework Assignment 1
 * Chapter 2 - Gaddis
 * Lauren Postlethwaite
 * 
 * Programming Problem #10
 * 20. How Much Paint*/

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * A particular brand of paint covers 340 square feet per gallon.
 * Write a program to determine and report approximately how many
 * gallons of paint will be needed to paint two coats on a wooden
 * fence that is 6 feet high and 100 feet long.
 */
int main(int argc, char** argv) {

    int height = 6; // Height of fence in feet
    int length = 100; // Length of fence in feet
    int area; // Area of fence in feet^2
    int totArea; // Area that needs to be painted in feet^2
    int paint = 340; // Square feet covered per gallon of paint
    int gals; // Number of gallons of paint needed
    
    area = height * length;
    totArea = 4 * area; // *4 because 2 coats paint and 2 sides of fence
    gals = totArea / paint;
    
    // +1 added to offset the division operator always rounding down
    cout << "  You will need approximately " << gals + 1 << " gallons of paint in order to paint" << endl;
    cout << "  two coats on a wooden fence that is " << height << " feet tall and " << length << " feet long.";
    
    return 0;
}

