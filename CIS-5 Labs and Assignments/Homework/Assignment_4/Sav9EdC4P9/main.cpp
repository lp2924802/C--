/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 24, 2022, 11:01 PM
 * Purpose:  Find the max of either two or three parameters of type float and
 *              return the largest of them. Display answer to one decimal
 *              place.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//Function Prototypes
float twoPar(float, float); //Two Parameter Function Prototype
float thrPar(float, float, float); //Three Parameter Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float num1, num2, num3; //Numbers to be input by user
    float lrgOf2; //Largest number from two numbers
    float lrgOf3; //Largest number from three numbers
    
    cout << "Enter first number:" << endl;
    cin >> num1;
    cout << endl << "Enter Second number:" << endl;
    cin >> num2;
    cout << endl << "Enter third number:" << endl;
    cin >> num3;
    
    lrgOf2 = twoPar(num1, num2); //Call two parameter function
    
    lrgOf3 = thrPar(num1, num2, num3); //Call three parameter function
    
    cout << endl << "Largest number from two parameter function:";
    cout << endl << lrgOf2 << endl;
    
    cout << endl << "Largest number from three parameter function:";
    cout << endl << lrgOf3 << endl;
    
    //Exit stage right or left!
    return 0;
}

//TWO PARAMETER FUNCTION*********
float twoPar(float inNum1, float inNum2){
    
    float lrgrNum; //Larger number of two inputs
    
    if (inNum1 > inNum2){
        lrgrNum = inNum1;
    }
    else {
        lrgrNum = inNum2;
    }
    
    return lrgrNum;
}


//THREE PARAMETER FUNCTION*********
float thrPar(float inNum1, float inNum2, float inNum3){
    
    float lrgrNum; //Larger number of three inputs
    
    if (inNum1 > inNum2){
        if (inNum1 > inNum3){
            lrgrNum = inNum1; //#1 larger than both #2 and #3 => #1 is largest
        }
        else {
            lrgrNum = inNum3; //#1 larger than #2, #3 larger than #1 => #3 is largest
        }
    }
    else if (inNum2 > inNum3) {
        lrgrNum = inNum2; //#2 larger than #3, #2 larger than #1 => #2 is largest
    }
    else {
        lrgrNum = inNum3; //#2 larger than #1, #2 NOT larger than #3 => #3 is largest
    }
    
    return lrgrNum;
}