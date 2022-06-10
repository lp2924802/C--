/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2019, 4:36 PM
 * Purpose:  Write a program that asks the user to enter three names, and then
 *              displays the names sorted in alphabetical order.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   //String Variable Type
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int count = 0; //Counter
    const int NAME_NUM = 3; //Number of names in nameIn array 
    string nameIn[NAME_NUM]; //Array to hold names
    string nameOut[NAME_NUM]; //Array to hold names in order

    
    //Display the outputs
    
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    
    for (count = 0; count < NAME_NUM; count++){
        cin >> nameIn[count]; //Input name
    }
    
    if (nameIn[0] < nameIn[1] && nameIn[0] < nameIn[2]){
        nameOut[0] = nameIn[0]; //Place first entry in first output slot
        if (nameIn[1] < nameIn[2]){
            nameOut[1] = nameIn[1]; //Place second entry in second output slot
            nameOut[2] = nameIn[2]; //Place third entry in third output slot
        }
        else {
            nameOut[1] = nameIn[2]; //Place third entry in second output slot
            nameOut[2] = nameIn[1]; //Place second entry in third output slot
        }
    }
    else if (nameIn[1] < nameIn[0] && nameIn[1] < nameIn[2]){
        nameOut[0] = nameIn[1]; //Place second entry in first output slot
        if (nameIn[0] < nameIn[2]) {
            nameOut[1] = nameIn[0]; //Place first entry in second output slot
            nameOut[2] = nameIn[2]; //Place third entry in third output slot
        }
        else {
            nameOut[1] = nameIn[2]; //Place third entry in second output slot
            nameOut[2] = nameIn[0]; //Place first entry in third output slot
        }
    }
    else {
        nameOut[0] = nameIn[2]; //Place third entry in first output slot
        if (nameIn[0] < nameIn[1]) {
            nameOut[1] = nameIn[0]; //Place first entry in second output slot
            nameOut[2] = nameIn[1]; //Place second entry in third output slot
        }
        else {
            nameOut[1] = nameIn[1]; //Place second entry in second output slot
            nameOut[2] = nameIn[0]; //Place first entry in third output slot
        }
    }
    
    cout << nameOut[0] << endl << nameOut[1] << endl << nameOut[2];

    //Exit stage right or left!
    return 0;
}