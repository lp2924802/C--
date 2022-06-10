/* 
 * File:
 * Author: Lauren Postlethwaite
 * Date: 1/12/2022
 * Purpose: A1 Test Output Format
 * Version: 1.0
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float test1, test2, test3, test4, test5;
    float avgTest;
    
    //Map inputs -> outputs
    cout << "This program will calculate and display the average of five test scores." << endl;
    cout << "Enter your test scores below:" << endl;
    cout << " " << endl;
    
    cout << "Test Score #1 = "; //TEST #1
    cin >> test1;
    
    cout << "\nTest Score #2 = "; //TEST #2
    cin >> test2;
    
    cout << "\nTest Score #3 = "; //TEST #3
    cin >> test3;
    
    cout << "\nTest Score #4 = "; //TEST #4
    cin >> test4;
    
    cout << "\n Test Score #5 = " << endl; //TEST #5
    cin >> test5;
    
    avgTest = (test1 + test2 + test3 + test4 + test4) / 5;
    
    cout << "\nAverage Test Score = " << avgTest;
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}