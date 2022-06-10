/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 24, 2022, 10:23 PM
 * Purpose:  Write a program to gauge the rate of inflation for the past year.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float getInfl(float, float); //Get Inflation Rate - Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float prcCur; //Current price
    float prcOld; //Old price
    float infl; //Inflation rate
    char again = 'y'; //Repeat checker
    
    do {
        
        cout << "Enter current price:" << endl;
        cin >> prcCur; //Input current price
        cout << "Enter year-ago price:" << endl;
        cin >> prcOld; //Input old price
        
        infl = getInfl(prcCur, prcOld); //Get inflation rate from getInfl function call
        
        cout << "Inflation rate: " << fixed << setprecision(2) << infl << "%" << endl;
        
        cout << endl << "Again:" << endl;
        cin >> again;
        
        if (again != 'n'){
            cout << endl;
        }
    } while (again != 'n');

    //Exit stage right or left!
    return 0;
}


//GET INFLATION RATE***********
float getInfl(float prcNow, float prcPast){
    
    float prcDif; //Difference between old and new price;
    float perOld; //Percentage of old price (decimal)
    float perFixd; //Percentage of old price (corrected to % value)
    
    prcDif = prcNow - prcPast; //Calculate difference in old and new prices
    perOld = prcDif / prcPast; //Calculate percent change
    perFixd = perOld * 100;
    
    return perFixd;
}