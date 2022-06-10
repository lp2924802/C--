/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2022, 4:53 PM
 * Purpose:  Write a program that asks the user to enter the number of books
 *              he or she has purchased this month and then displays the
 *              number of points awarded.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    unsigned int books; //Books purchased
    int points; //Points earned
    
    
    //Display the outputs
    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> books;
    
    if (books == 0)
        points = 0;
    else if (books == 1)
        points = 5;
    else if (books ==2)
        points = 15;
    else if (books == 3)
        points = 30;
    else
        points = 60;
    
    
    cout << left << setw(16) << "Books purchased" << "=" << right << setw(3) << books << endl;
    cout << left << setw(16) << "Points earned" << "=" << right << setw(3) << points;

    //Exit stage right or left!
    return 0;
}