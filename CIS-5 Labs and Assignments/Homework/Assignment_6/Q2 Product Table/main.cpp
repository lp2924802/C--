/* 
 * File:   main.cpp
 * Author:  Lauren Postlethwaite
 * Created: February 4, 2022, 4:28 PM 
 * Purpose:  Product Table
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6;

//Function Prototypes
void fillTbl(int [][COLS],int);
void prntTbl(const int [][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS=6;
    int tblProd[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    fillTbl(tblProd,ROWS);
    
    cout<<"Think of this as a Product/Muliplication Table"<<endl;
    //Display the outputs
    prntTbl(tblProd,ROWS);

    //Exit stage right or left!
    return 0;
}


void fillTbl(int nums[][COLS],int ROWS){
    
    for (int i=0; i<ROWS; i++){
        
        
        for (int j=0; j<COLS; j++){
            
            nums[i][j] = (i+1) * (j+1);
            
        }
    }
    
    
}

void prntTbl(const int sums[][COLS],int ROWS){
    

    cout<<right<<setw(24)<<"          C o l u m n s"<<endl;
    cout<<right<<setw(6)<<"|"<<setw(4)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<
                setw(4)<<"4"<<setw(4)<<"5"<<setw(4)<<"6"<<endl;
    cout<<string(34,'-')<<endl;
    
    for (int i=0; i<ROWS; i++){
        
        if (i==1)
            cout<<"R"<<right<<setw(3)<<(i+1)<<" |";
        else if (i==2)
            cout<<"O"<<right<<setw(3)<<(i+1)<<" |";
        else if (i==3)
            cout<<"W"<<right<<setw(3)<<(i+1)<<" |";
        else if (i==4)
            cout<<"S"<<right<<setw(3)<<(i+1)<<" |";
        else
            cout<<right<<setw(4)<<(i+1)<<" |";
        
        for (int j=0; j<COLS; j++){
        
            
            if (j==5)
                cout<<right<<setw(4)<<sums[i][j]<<endl;
            else
                cout<<right<<setw(4)<<sums[i][j];
        }
        
    }
}