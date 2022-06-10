/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 23, 2022, 4:31 PM
 * Purpose:  Write a program with a loop that lets the user enter a series of integers
 *              and afterward displays the largest and smallest numbers entered.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    signed int inInt; //Input integer
    signed int smllInt; //Smallest integer
    signed int bigInt; //Largest integer
    int i = 0; //Counter
    const int END = 1; //End for loop
   
    for (i = 0; i < END; i++){
        
        cin >> inInt;
        smllInt = inInt;
        bigInt = inInt;
    }
    
    while (inInt != -99) {
        
        if (inInt > bigInt) {
            bigInt = inInt; //Replace old largest int with new largest int
        }
        
        if (inInt < smllInt) {
            smllInt = inInt; //Replace old smallest int with new smallest int 
        }
        
        cin >> inInt; //Input integer
    }
    
    cout << left << setw(9) << "Smallest" << "number in the series is " << smllInt << endl;
    cout << setw(9) << "Largest" << "number in the series is " << bigInt;
    

    //Exit stage right or left!
    return 0;
}