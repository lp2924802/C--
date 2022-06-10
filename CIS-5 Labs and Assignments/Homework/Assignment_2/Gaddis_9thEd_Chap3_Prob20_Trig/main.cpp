/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 15, 2022, 7:28 PM
 * Purpose:  Write a program that asks the user for an angle, entered in degrees. The program should
 *              then display the sine, cosine, and tangent of the angle. 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
#include <cmath>    //Mathematical Equations/Operations
using namespace std;

const float PI = 3.14159265; //Pi

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float angle; //Value of input angle
    float angFix; //Corrected angle value (from Rad to Deg)
    float sinAng; //Sine of angle
    float cosAng; //Cos of angle
    float tanAng; //Tan of angle
    float deg2Rad; //Radians to degrees conversion 180/PI
    
    deg2Rad = PI / 180; //Initialize conversion
    
    //Map inputs -> outputs
    cout << "Calculate trig functions" << endl;
    cout << "Input the angle in degrees." << endl;
    
    cin >> angle;
    
    angFix = angle * deg2Rad; //Correct angle value to degrees
    sinAng = sin(angFix);
    cosAng = cos(angFix);
    tanAng = tan(angFix);
    
    cout << "sin(" << angle << ") = " << fixed << setprecision(4) << sinAng << endl;
    cout << "cos(" << fixed << setprecision(0) << angle << ") = " << fixed << setprecision(4) << cosAng << endl;
    cout << "tan(" << fixed << setprecision(0) << angle << ") = " << fixed << setprecision(4) << tanAng;


    //Exit stage right or left!
    return 0;
}