/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2022, 6:15 PM
 * Purpose:  Write a program that asks for the names of three runners and the time
 *              it took each of them to finish a race. 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   //String Variable Type
#include <iomanip>  //Formatting
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int SIZE = 3; //Size of arrays
    string name[SIZE]; //Runners
    unsigned int times[SIZE]; //Times of runners 
    string tempN; //Placeholder 
    int i, j, min, tempT; //Counters and minimum time value placeholder
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    
    for (i = 0; i < SIZE; i++){
        
        cin >> name[i] >> times[i];
    }
    
    i = 0; //Reset count to 0 
    
    //Move boundary of unsorted subarray one by one
    for (i = 0; i < SIZE - 1; i++){
        
        min = i; //Set current to minimum 
        
        //Find the minimum element in the unsorted array
        for (j = i + 1; j < SIZE; j++) {
            
            if (times[j] < times[min]){
                min = j;
            }
            
            //Swap the newly found minimum element with the first element
            tempT = times[min];
            tempN = name[min];
            times[min] = times[i];
            name[min] = name[i];
            times[i] = tempT;
            name[i] = tempN;
            
        }
    }
    
    i = 0; //Reset i to zero again
    
    for (i = 0; i < SIZE; i++){
        cout << name[i] << "\t" << setw(3) << times[i];
        
        if (i == 0 || i == 1){
            cout << endl;
        }
        
    }

    //Exit stage right or left!
    return 0;
}
