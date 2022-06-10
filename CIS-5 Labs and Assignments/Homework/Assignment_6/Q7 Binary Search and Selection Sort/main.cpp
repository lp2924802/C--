/* 
 * File:   main.cpp
 * Author:      Lauren Postlethwaite
 * Created on:  February 6, 2022, 8:18 PM
 * Purpose:  Binary Search
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
void selSrt(int [],int);
bool binSrch(int [],int,int,int&);
void swap(int &, int &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;

    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);

    //Sorted List
    selSrt(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
    if(binSrch(array,SIZE,val,indx))
       cout<<val<<" was found at indx = "<<indx<<endl;

    //Exit stage right or left!
    return 0;
}

//Binary Search Function
bool binSrch(int arr[], int SIZE, int value, int &indx){
    
    int i = 0, last = SIZE - 1;

    while (i <= last) {
        
        int mid = i + (last - i)/2;
        
        if (arr[mid] == value) {
            indx = mid;
            return true;
        }
        
        if (arr[mid] < value) 
            i = mid + 1;
        else
            last = mid - 1;
    }
    
    return false;
    
}
//Selection Sort Algorithm
void selSrt(int arr[], int SIZE){
    
    int minIndx, minVal;
    
    for (int start = 0; start < (SIZE - 1); start++) {
        
        minIndx = start;
        minVal = arr[start];
        
        for (int index = start + 1; index < SIZE; index++) {
            
            if (arr[index] < minVal) {
                
                minVal = arr[index];
                minIndx = index;
            }
        }
        
        swap(arr[minIndx], arr[start]);
    }
}

//Swap Function
void swap(int &varA, int &varB){
    
    int temp = varA;
    varA = varB; 
    varB = temp;
}

//Fill Array Function
void fillAry(int arr[], int SIZE){
    
    for (int i=0; i<SIZE; i++){
        cin>>arr[i];
    }

} 

//Print Array Function
void prntAry(int arr[], int SIZE, int rows){
    int j=0;
    
    for (int i=0; i<SIZE; i++){
        cout<<arr[i]<<" ";
        
        j = i+1;
        
        if ((j%10)==0){
            cout<<endl;
        }

    }
    cout<<endl;
}