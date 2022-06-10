/* 
 * File:    main.cpp
 * Author:  Lauren Postlethwaite
 * Created on:  Jan 24, 2022, 1:05PM
 * Purpose:  Write a program that will read in the number of liters of gasoline consumed by the user's car and
 *              the number of miles traveled by the car and will then output the number of miles per gallon the
 *              car delivered.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
const float GL_P_LT = 0.264179; //Liters per gallon
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float mpgCalc(float, float); //MPG Calculation Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float gasLit; //Liters of gasoline (liters)
    float miles; //Miles traveled (miles)
    float mpg; //Miles per gallon (miles/gallon)
    char again = 'y'; //Repeat checker
    //Initialize or input i.e. set variable values
    
    do {
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> gasLit;
        cout << endl << "Enter number of miles traveled:" << endl;
        cin >> miles;
        
        mpg = mpgCalc(gasLit, miles);
        cout << endl << "miles per gallon:" << endl;
        cout << fixed << setprecision(2) << mpg << endl;
      
        cout << "Again:" << endl;
        cin >> again; 
        
        if (again != 'n'){
            cout << endl;
        }
      
    } while (again != 'n');

    //Exit stage right or left!
    return 0;
}

//MPG CALC FUNCTION******************
float mpgCalc(float liters, float distMls){
    
    float gals; //Amount of gas in gallons
    float mpgFnc; //MPG, function version
    
    gals = liters * GL_P_LT; //Convert liters to gallons
    mpgFnc = distMls / gals; //Calculate MPG
    
    return mpgFnc;
}