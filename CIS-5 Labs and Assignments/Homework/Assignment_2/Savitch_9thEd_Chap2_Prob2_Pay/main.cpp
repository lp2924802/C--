/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 18, 2019, 2:03 PM
 * Purpose: Write a program to calculate retroactive pay for employees that won a 7.6% raise.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;


int main(int argc, char** argv) {
    
    //Declare Variables
    float annSal, monSal; //Annual Salary, Monthly Salary ($)
    float raisPer = 0.076f; //Percentage raise (7.6%)
    float rtrPay; //Retroactive Pay ($)
    float nAnnSal, nMonSal; //New Annual Salary, New Monthly Salary ($)
    
    
    //Display the outputs
    cout << "Input previous annual salary." << endl;
    cin >> annSal;
    
    nAnnSal = annSal * (1 + raisPer); //Calculation of new annual salary ($)
    
    monSal = annSal / 12; //Calculation of old monthly salary ($)
    nMonSal = monSal * (1 + raisPer); //Calculation of new monthly salary ($)
    
    rtrPay = (nMonSal - monSal) * 6; //Difference between new and old monthly salaries x 6 ($)
    
    
    cout << left << setw(19) << "Retroactive pay"; 
    cout << "= $" << fixed << setprecision(2) << right << setw(7) << rtrPay << endl;
    cout << left << setw(19) << "New annual salary";
    cout << "= $" << fixed << setprecision(2) << right << setw(7) << nAnnSal << endl;
    cout << left << setw(19) << "New monthly salary"; 
    cout << "= $" << fixed << setprecision(2) << right << setw(7) << nMonSal;

    return 0;
}