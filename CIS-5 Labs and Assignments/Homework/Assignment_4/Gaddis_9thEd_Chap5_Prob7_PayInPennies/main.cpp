/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 23, 2022, 4:05 PM
 * Purpose:  Write a program that calculates how much a person would earn over a period of
 *              time if his or her salary is one penny the first day and two pennies the
 *              second day, and continues to double each day.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Formatting Library
#include <cmath>    //Math Library
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int count = 0; //Counter, initialized to zero
    int sum = 0; //Sum of wages, initialized to zero
    int income; //Income for that day (cents)
    unsigned int inDays; //Input days worked (days)
    float earned; //Income earned (dollars)
    
    cin >> inDays; //Input days worked
    
    while (count < inDays)
    {
        income = pow(2.0, count); //Get doubled income for day 
        sum = sum + income; //Add doubled income to sum of incomes 
        
        count++; //Increment counter
    }
    
    
    cout << "Pay = $" << fixed << setprecision(2) << sum / 100.0;

    //Exit stage right or left!
    return 0;
}
