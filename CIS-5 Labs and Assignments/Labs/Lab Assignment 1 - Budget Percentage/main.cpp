
/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 10, 2022, 5:33 PM
 * Purpose:  Lab Assignment 1 - Budget/Percentage. Design a program to determine
 *           calculate the military budget as a percentage of the federal
 *           budget. 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Global Constants
const unsigned char CNVPER = 100; // Conversion to 100% 

/*
 * 
 */
int main(int argc, char** argv) {

    // Define and initialize variables
    float natBdg = 6820; // National Budget for 2021 in billions of $
    float dodBdg = 752.9; // DOD Budget for 2021 in billions of $
    float nasaBdg = 25.2; // NASA Budget for 2021 in billions of $
    float milPer, nasaPer; // Military and NASA percent of total national budget
    
    milPer = (dodBdg / natBdg) * CNVPER;
    nasaPer = (nasaBdg / natBdg) * CNVPER;
    
    cout << "In 2021, spending on the military made up " << fixed << setprecision(2) << milPer << "% of the total national" << endl;
    cout << "budget, while spending on NASA made up " << fixed << setprecision(2) << nasaPer << "% of the total national budget." << endl;
    
    return 0;
}

