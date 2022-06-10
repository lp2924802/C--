/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2022, 5:55 PM
 * Purpose:  Write a program that asks for the beginning balance and the number
 *              of checks written. Compute and display the bank's service fees
 *              for the month.
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
    float balance; //Bank account balance
    unsigned int checks; //Number of checks
    float perChk; //Price per check
    float chkFee; //Check Fee 
    float monFee = 10; //Monthly Fee, initialized to $10 
    float lowBal; //Low Balance Fee
    float newBal; //New Balance 
   
    //Program
    
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    
    cin >> balance >> checks; //Input balance and number of checks
    
    //CHECK FOR OVERDRAWN ACCOUNT
    if (balance < 0){
        cout << "Warning: Account Overdrawn!" << endl;
    }
    
    //CHECK FOR LOW BALANCE
    if (balance < 400) {
        lowBal = 15;
    }
    
    //DETERMINE PRICE PER CHECK
    if (checks < 20) {
        perChk = 0.10;
    }
    else if (checks < 40) {
        perChk = 0.08; 
    }
    else if (checks < 60) {
        perChk = 0.06;
    }
    else {
        perChk = 0.04;
    }
    
    //DETERMINE PRICE OF CHECKS 
    chkFee = checks * perChk;
 
    
    //DETERMINE NEW BALANCE 
    newBal = balance - monFee - chkFee - lowBal;
    
    //DISPLAY RESULTS
    cout << left << setw(12) << "Balance" << "$" << right << setw(9)
        << fixed << setprecision(2) << balance << endl;
    cout << left << setw(12) << "Check Fee" << "$" << right << setw(9)
        << fixed << setprecision(2) << chkFee << endl;
    cout << left << setw(12) << "Monthly Fee" << "$" << right << setw(9)
        << fixed << setprecision(2) << monFee << endl;
    cout << left << setw(12) << "Low Balance" << "$" << right << setw(9)
        << fixed << setprecision(2) << lowBal << endl;
    cout << left << setw(12) << "New Balance" << "$" << right << setw(9)
        << fixed << setprecision(2) << newBal;

    //Exit stage right or left!
    return 0;
}