/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 23, 2019, 12:46 AM
 * Purpose:  Write a program that asks the user for a positive integer value. Use a loop
 *              to get the sum of all the integers from 1 up to the number entered.
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int inNum; //Input integer
    int count = 1; //Counter, initialized to 1
    int sum = 0; //Sum of integers, initialized to 0
    
    cin >> inNum;
    
    while (count <= inNum) {
        sum = sum + count; //Add current count to sum 
        count++; //Increment counter 
    }
    
    cout << "Sum = " << sum;
    //Map inputs -> outputs
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}