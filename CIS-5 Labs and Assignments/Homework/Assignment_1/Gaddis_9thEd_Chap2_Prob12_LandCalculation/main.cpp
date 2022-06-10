/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Postl
 *
 * Created on January 5, 2022, 12:33 PM
 */

/*
 * Homework Assignment 1
 * Chapter 2 - Gaddis
 * Lauren Postlethwaite
 * 
 * Programming Problem #7
 * 12. Land Calculation*/

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * One acre of land is equivalent to 43,560 square feet. Write a
 * program that calculates the number of acres in a tract of land with
 * 391,876 square feet.
 */
int main(int argc, char** argv) {

    const int SQ_FT_ACRE = 43560; // Square feet per acre
    int landFt = 391876; // Size of land in square feet
    int landAcs; // Size of land in acres
    
    landAcs = landFt / SQ_FT_ACRE;
    
    cout << " There are " << landAcs << " acres in a tract of land with " << landFt << " square feet.";
    return 0;
}

