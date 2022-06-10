/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 24, 2019, 11:23 AM
 * Purpose:  Write a program that asks the user for a positive integer no greater than 15.
 *              The program should then display a rectangle on the screen using the 
 *              character 'X'. The number entered by the user will be the length of each
 *              side of the rectangle.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string> //String Variable Type
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int num; //Input number
    char lttr; //Input letter
    string row; //Row of letters
    int i = 0; //Counter
    int j = 0; //Inner loop counter
    
    cin >> num >> lttr; //Input number and letter
    
    row.assign(num, lttr);
    
    for (i = 0; i < num - 1; i++) {
        cout << row << endl;
    }
    
    cout << row;

    //Exit stage right or left!
    return 0;
}
