/* 
 * File:   main.cpp
 * Author:  Lauren Postlethwaite
 * Created: February 4, 2022, 4:47 PM 
 * Purpose:  Reverse the Array
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

//Function Prototypes
void  init(int [],int);//Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int);;//Reverse the array


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=50;
    int test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    //print(test,SIZE,10);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,10);

    //Exit stage right or left!
    return 0;
}


void init(int arr[], int SIZE){
    
    
    for (int i=0; i<SIZE; i++){
        cin>>arr[i];
    }
}



void print(int arr[], int SIZE, int row){
    
    int i = 0, k = 1; 
    
    
    for (int i=0; i<SIZE; i++){
        
        if (k==10){
            cout<<left<<setw(3)<<arr[i]<<endl;
            k=0; //Reset row counter
        }
        else
            cout<<left<<setw(3)<<arr[i];
        
        k++;    
    }
}

void revrse(int arr[], int SIZE){
    
    int indx;
    int revArr[SIZE];
    
    indx = SIZE - 1;
    
    for (int i=0; i<SIZE; i++){
        
        revArr[i] = arr[indx - i];
    }
    
    for (int i=0; i<SIZE; i++)
        arr[i] = revArr[i];
    
}
