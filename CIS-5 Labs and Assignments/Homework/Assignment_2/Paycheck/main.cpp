/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 15, 2022, 10:08 PM
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    
    int hours, oT = 0; //Hours worked, overtime hours worked (hours)
    float rate; //Pay rate ($/hr)
    float gross; //Gross pay ($)
    
    cout << "This program calculates the gross paycheck." << endl;
    cout << "Input the pay rate in $'s/hr and the number of hours." << endl;
    cin >> rate >> hours;
    
    
    //Compute overtime
    if (hours > 40){
        oT = hours - 40; //Determine number of overtime hours (hours)
        //Compute gross pay (overtime version) ($)
        gross = rate*40 + oT*2.0*rate; // Gross = (Payrate * 40hrs) + (Payrate * OT hrs * 2) ($)
    }
    else {
        //Compute gross pay (no overtime version) ($)
        gross = rate * hours;
    }
    
    cout << "Paycheck = $"; 
    cout << fixed << setprecision(2) << setw(7) << gross;
    
    return 0;
}