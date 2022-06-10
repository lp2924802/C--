/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 15, 2022, 7:10 PM
 * Purpose:  Write a program that asks the user to enter the replacement cost of a building
 *              and then displays the minimum amount of insurance he or she should buy for
 *              the property
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float house; //Cost of house in $
    float ratio = 0.8; //Proportion of house to insure
    float insure; //Amount of insurance needed in $
    
    cout << "Insurance Calculator" << endl;
    cout << "How much is your house worth?" << endl;
    cin >> house;
    
    insure = house * ratio;
    
    cout << "You need $" << insure << " of insurance.";
    

    //Exit stage right or left!
    return 0;
}