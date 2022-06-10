/* 
 * File:   main.cpp
 * Author:      Lauren Postlethwaite
 * Created on:  February 4, 2022, 11:27 PM
 * Purpose:     Standard Deviation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float MAXRAND=pow(2,31)-1;

//Function Prototypes
void  init(float [],int);//Initialize the array
void  print(float [],int,int);//Print the array
float avgX(float [],int);//Calculate the Average
float stdX(float [],int);//Calculate the standard deviation

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
 

    //Display the outputs
    //print(test,SIZE,5);
    cout<<"The average            = "<<fixed<<setprecision(7)<<avgX(test,SIZE)<<endl;
    cout<<"The standard deviation = "<<fixed<<setprecision(7)<<stdX(test,SIZE)<<endl;

    //Exit stage right or left!
    return 0;
}

//Initialize the array
void init(float arr[], int size){
    
    for (int i=0; i<size; i++){
        cin>>arr[i];
    }
    
    
}

//Calculate the mean
float avgX(float nums[], int sizes){
    
    //Declare local variables
    float sum = 0; //Sum of numbers, initialized to zero
    float avg = 0;
    
    for (int i=0; i<sizes; i++){
        //Add value of that array item 
        sum += nums[i];
    }
    
    avg = sum / static_cast<float>(sizes);
    //Divide by total numbers to get average
    return avg;
}


float stdX(float nums[], int sizes){
    
    //Declare local variables
    float arr[sizes]; //Array holding the (Xi-mean)^2 values
    float diff = 0, holder = 0;
    float avg, sum = 0, denom, last, std;
    
    denom = sizes - 1;
    
    
    avg = avgX(nums,sizes);
    
    for (int i=0; i<sizes; i++){
        
        diff = avg - nums[i];
        holder = pow(diff,2.0);

        sum += holder;
        
    }

    last = sum/denom;
    
    std = sqrt(last);
    
    return std;

}
