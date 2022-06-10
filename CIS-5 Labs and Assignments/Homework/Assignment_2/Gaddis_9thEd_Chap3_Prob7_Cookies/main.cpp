/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 15, 2022, 12:18 AM
 * Purpose:  Write a program that asks the user to input how many cookies
 *          he or she actually ate and then reports how many total calories
 *          were consumed.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float cookies;
    float srvng;
    float totCal;
    const float C_PER_SVG = 4; //4 cookies/serving
    const float CAL_SVG = 300; //300 calories/serving
    
    
    //Display the outputs
    cout << "Calorie Counter" << endl;
    cout << "How many cookies did you eat?" << endl;
    cin >> cookies;
    
    srvng = cookies / C_PER_SVG;
    totCal = srvng * CAL_SVG;
    
    cout << "You consumed " << fixed << setprecision(0) << totCal << " calories.";


    //Exit stage right or left!
    return 0;
}