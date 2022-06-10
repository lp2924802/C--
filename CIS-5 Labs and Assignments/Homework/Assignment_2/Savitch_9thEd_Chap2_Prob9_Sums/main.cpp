/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 18, 2022, 2:49 PM
 * Purpose:  Write a program that reads in ten whole numbers and that outputs the sum
 *              of all numbers greater than zero, the sum of all numbers less than
 *              zero (which will be a negative number or zero), and the sum of all
 *              numbers, weither positive, negative, or zero.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    signed int negSum = 0; //Negative sum, initialized to zero
    signed int posSum = 0; //Positive sum, initialized to zero 
    signed int totSum = 0; //Total sum, initialized to zero
    signed int numb[10]; //Array holding input numbers
    int count; //Loop counter
    const int NUM_INPT = 10; //Number of inputs in array
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    
    for (count = 0;  count < NUM_INPT; count++){
        cin >> numb[count];
        
        totSum = totSum + numb[count];
        
        if (numb[count] > 0){
            posSum = posSum + numb[count];
        }
        else{
            negSum = negSum + numb[count];
        }
        
            
        
    }
    
    cout << left << setw(13) << "Negative sum" << "=" << right << setw(4) << negSum << endl;
    cout << left << setw(13) << "Positive sum" << "=" << right << setw(4) << posSum << endl;
    cout << left << setw(13) << "Total sum" << "=" << right << setw(4) << totSum;

    //Exit stage right or left!
    return 0;
}