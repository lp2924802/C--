/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 14, 2022, 11:43 PM
 * Purpose:  Write a program that asks for five test scores. The program should calculate the average test score and display it. 
 *              the program should calculate the average test score and display it. The number displayed should be formatted in
 *              fixed-point notation, with one decimal point of precision. 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float test1, test2, test3, test4, test5;
    float avgTest;
    
    //Map inputs -> outputs
    cout << "Input 5 numbers to average." << endl;
    cin >> test1 >> test2 >> test3 >> test4 >> test5;
    
    avgTest = (test1 + test2 + test3 + test4 + test5) / 5;
    
    cout << "The average = " << fixed << setprecision(1) << avgTest;
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}