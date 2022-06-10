/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Postl
 *
 * Created on January 4, 2022, 6:18 PM
 */

/*
 * Homework Assignment 1
 * Chapter 2 - Gaddis
 * Lauren Postlethwaite
 * 
 * Programming Problem #5
 * 10. Miles per Gallon*/

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * A car holds 15 gallons of gasoline and can travel 375 miles before
 * refueling. Write a program that calculates the number of miles per
 * gallon the car gets. Display the result on the screen.
 */
int main(int argc, char** argv) {
    int gallons = 15; // Total gallons of gasoline car can hold
    int miles = 375; // Miles traveled before refueling
    float mpg; // Miles per gallon
    
    mpg = miles / gallons; 
    
    cout << " Your car gets " << mpg << " miles per gallon.";
    return 0;
}

