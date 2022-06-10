/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 24, 2022, 11:32 PM
 * Purpose:  Write a program to display (specific pattern from book) given an
 *              input of 10.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int num; //Input number (will be 10)
    int i = 0; //Outer loop counter, initialized to zero
    int j = 0; //Inner loop counter, initialized to zero
    
    cin >> num; //Input number
    
    //For Loop => Counting Up
    for (i = 0; i < num; i++){
        
        for (j = 0; j <= i; j++){
            cout << "+";
        }
        
        cout << endl;
        cout << endl;
    }
    
    
    j = 0; //Reset outer loop counter to zero
    
    //For Loop => Counting Down
    for (i = num; i > 0; i--){
        
        for (j = 0; j <= i - 1; j++){
            cout << "+";
        }
        
        if (i > 1){
            cout << endl;
            cout << endl;
        }
        
    }

    //Exit stage right or left!
    return 0;
}