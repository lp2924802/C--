/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 15, 2022, 7:18 PM
 * Purpose:  Write a program that converts Fahrenheit temperatures to Celsius temperatures.
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
    //Set the random number seed
    
    //Declare Variables
    float degF; //Degrees in Fahrenheit
    float degC; //Degrees in Celsius
    float inBr; //Section inside brackets of C = 5/9(F-32) eqn
    float ratio; //Initialized to 5/9
    
    ratio = 5.0/9.0;
    
    
    //Display the outputs
    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Fahrenheit" << endl;
    
    cin >> degF;
    
    inBr = degF - 32;
    degC = inBr * ratio;
    
    cout << fixed << setprecision(1) << degF << " Degrees Fahrenheit = " << degC << " Degrees Centigrade";

    //Exit stage right or left!
    return 0;
}