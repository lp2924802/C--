/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Postl
 *
 * Created on January 4, 2022, 6:24 PM
 */

/*
 * Homework Assignment 1
 * Chapter 2 - Gaddis
 * Lauren Postlethwaite
 * 
 * Programming Problem #6
 * 11. Distance per Tank of Gas*/

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * A car with a 20-gallon tank averages 23.5 miles per gallon
 * when driven in town, and 28.9 miles per gallon when driven on the
 * highway. Write a program that calculates and displays the 
 * distance the car can travel on one tank of gas when driven in town
 * and when driven on the highway.
 */

int main(int argc, char** argv) {

    int gals = 20; // Gallons of gas in the car
    float mpgTwn = 23.5; // Miles per gallon in town
    float mpgHwy = 28.9; // Miles per gallon on the highway
    float distTwn; // Distance car can travel in town
    float distHwy; // Distance car can travel on the highway
    
    distTwn = gals * mpgTwn;
    distHwy = gals * mpgHwy;
    
    cout << " Your car can travel " << distTwn << " miles on one tank of gas" << endl;
    cout << " when driven in town and " << distHwy << " miles when driven on" << endl;
    cout << " the highway." << endl;
    
    return 0;
}

