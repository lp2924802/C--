/* 
 * File:   main.cpp
 * Author:      Lauren Postlethwaite
 * Created on:  February 6, 2022, 4:43 PM
 * Purpose:  Linear Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
bool linSrch(int [],int,int,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    val=50;
    fillAry(array,SIZE);
    
    //Display the outputs
    //prntAry(array,SIZE,10);
    if(linSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    
    //Exit stage right or left!
    return 0;
}

void fillAry(int arr[], int SIZE){
    
    for (int i=0; i<SIZE; i++){
        cin>>arr[i];
    }

} 

void prntAry(int arr[], int SIZE, int rows){
    int j=0;
    
    for (int i=0; i<SIZE; i++){
        cout<<arr[i]<<" ";
        
        j = i+1;
        
        if ((j%10)==0){
            cout<<endl;
        }

    }
}

bool linSrch(int arr[], int SIZE, int value, int &indx){
    
    bool found = false;
    
    for (int i=0; i<SIZE; i++){
        
        if (arr[i]==value){
            found=true;
            indx = i;
            i = SIZE +1;
        }
        
    }
    
    return indx;
    
}


