/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on   January 24, 2022, 4:23 PM
 * Purpose:  Modify your program from Sav9EdC4P1 so that it will take input for
 *              two cars and output the number of miles per gallon delivered
 *              by each car. Your program will also announce which car has the
 *              best fuel efficiency (highest number of miles per gallon).
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed.

const float GL_P_LT = 0.264179; //Liters per gallon (conversion)
//Function Prototypes

float mpgCalc(float, float); //MPG Calculation Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float gasLit1; //Liters of gasoline, car #1
    float gasLit2; //Liters of gasoline, car #2
    float miles1; //Miles traveled, car #1
    float miles2; //Miles traveled, car #2
    float mpg1; //Miles per gallon, car #1
    float mpg2; //Miles per gallon, car #2
    int bestCar; //Best car (according to its mpg)
    char again = 'y'; //Repeat checker
    
    do {
        cout << "Car 1" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> gasLit1; //Enter liters for Car 1 (liters)
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles1; //Enter miles traveled for Car 1 (miles)
        
        mpg1 = mpgCalc(gasLit1, miles1); //Call function to calculate mpg (Car #1)
        cout << "miles per gallon: " << fixed << setprecision(2) << mpg1 << endl;
        cout << endl;
        
        cout << "Car 2" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> gasLit2; //Enter liters for Car 2 (liters)
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles2; //Enter miles traveled for Car 2 (miles)
        
        mpg2 = mpgCalc(gasLit2, miles2); //Call function to calculate mpg (Car #2)
        cout << "miles per gallon: " << mpg2 << endl;
        
        if (mpg1 > mpg2){
            bestCar = 1; 
        }
        else {
            bestCar = 2;
        }
        
        cout << endl << "Car " << bestCar << " is more fuel efficient" << endl;
        cout << endl << "Again:" << endl;
        cin >> again;
        
        if (again != 'n') {
            cout << endl;
        }
        
    } while (again != 'n');

    //Exit stage right or left!
    return 0;
}


//MPG CALC FUNCTION***********************
float mpgCalc(float liters, float distMls){
    
    float gals; //Amount of gas in gallons
    float mpgFnc; //MPG, local
    
    gals = liters * GL_P_LT; //Convert liters to gallons
    mpgFnc = distMls / gals; //Calculate MPG
    
    return mpgFnc;
}