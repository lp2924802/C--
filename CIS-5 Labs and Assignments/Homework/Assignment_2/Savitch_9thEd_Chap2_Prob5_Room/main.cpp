/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 18, 2022, 2:36 PM
 * Purpose:  Write a program that determines whether a meeting room is in violation
 *              of fire law regulations regarding the maximum room capacity.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int roomCap, numPpl; //Room capacity and number of people in room (# of people)
    int numDiff; //Difference between room occupancy and maximum capacity (# of people)
    
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> roomCap >> numPpl;
    
    if (numPpl > roomCap){
        cout << "Meeting cannot be held." << endl;
        
        numDiff = numPpl - roomCap; //Determine number of people to reduce room occupancy by (# of people)
        
        cout << "Reduce number of people by " << numDiff << " to avoid fire violation.";
    }
    else {
        cout << "Meeting can be held." << endl;
        
        numDiff = roomCap - numPpl; //Determine number of people able to increase room occ. by (# of people)
        
        cout << "Increase number of people by " << numDiff << " will be allowed without violation.";
    }

    return 0;
}