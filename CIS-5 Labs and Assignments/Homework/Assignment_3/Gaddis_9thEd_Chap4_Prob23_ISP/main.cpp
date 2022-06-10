/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2022, 6:44 PM
 * Purpose:  Write a program that calculates a customer's monthly bill.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    char package; //Package type
    unsigned int hours; //Number of hours
    int xtrHrs = 0; //Hours past limit, initialized to 0
    float rate = 0; //Hourly rate for extra hours, initialized to zero
    float base; //Base cost for package
    float cost; //Monthly bill
    
    
    //Display the outputs
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    
    cin >> package;
    
    if (package != 'A' && package != 'B' && package != 'C'){
        cout << "ERROR: Please enter A, B, or C" << endl;
    }
    
    cin >> hours;
    
    if (package == 'A'){
        base = 9.95;
        if (hours > 10){
            xtrHrs = hours - 10;
            rate = 2;
        }
    }
    else if (package == 'B'){
        base = 14.95;
        if (hours > 20){
            xtrHrs = hours - 20;
            rate = 1;
        }
    }
    else {
        base = 19.95;
    }
    
    cost = (xtrHrs * rate) + base;
    
    cout << "Bill = $" << setw(6) << fixed << setprecision(2) << cost;

    //Exit stage right or left!
    return 0;
}