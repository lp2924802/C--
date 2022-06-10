/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2022, 7:16 PM
 * Purpose:  Write a program that accepts a year written as a four-digic Arabic (ordinary)
 *              numeral and outputs the year written in Roman numerals.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   //String Variable Type
using namespace std;



//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    unsigned int year; //Input year
    int thous; //Thousands
    int remThou; //Remainder after thousands
    int hunds; //Hundreds
    int remHund; //Remainder after hundreds
    int tens; //Tens
    int ones; //Ones
    string romNums; //Roman numerals
    string addNums; //Roman numerals to add on
    string temp; //Placeholder 
    
    //Display the outputs
    cout << "Arabic to Roman numeral conversion." << endl;
    cout << "Input the integer to convert." << endl;
    
    cin >> year;
    
    if (year < 1000 || year > 3000){
        cout << year << " is Out of Range!";
        return(0);
    }
    
    //DETERMINE THOUSANDS
    thous = year / 1000;
    
    //REMAINDER AFTER THOUSANDS
    remThou = year % 1000;
    
    //DETERMINE HUNDREDS
    hunds = remThou / 100;
    
    //REMAINDER AFTER HUNDREDS
    remHund = remThou % 100;
    
    //DETERMINE TENS
    tens = remHund / 10;
    
    //REMAINDER AFTER TENS / DETERMINE ONES 
    ones = tens % 10;
    
    
    //******************************
    //START WITH ONES
    if (ones <= 3){
        addNums.append(ones, 'I');
    }
    else if (ones == 4){
        addNums = "IV";
    }
    else if (ones == 5){
        addNums = "V";
    }
    else if (ones <= 8){
        addNums = "V";
        addNums.append( ones - 5, 'I');
    }
    else if (ones == 9){
        addNums = "IX";
    }
    
    romNums = addNums; //Place determined ones into roman numeral slot
    addNums.clear(); //Clear adding slot
    
    //*******************************
    //ADD TENS
    if (tens <= 3){
        addNums.append(tens, 'X');
    }
    else if (tens == 4){
        addNums = "XL";
    }
    else if (tens == 5){
        addNums = "L";
    }
    else if (tens <= 8){
        addNums = "L";
        addNums.append( ones - 5, 'X');
    }
    else if (tens == 9){
        addNums = "XC";
    }
    
    temp = romNums; //Put into temporary spot
    romNums = addNums; //Put in tens spot
    romNums.append(temp); //Put ones back on
    addNums.clear(); //Clear adding spot
    
    //*******************************
    //ADD HUNDREDS
    if (hunds <= 3){
        addNums.append(hunds, 'C');
    }
    else if (hunds == 4){
        addNums = "CD";
    }
    else if (hunds == 5){
        addNums = "D";
    }
    else if (hunds <= 8){
        addNums = "D";
        addNums.append( ones - 5, 'C');
    }
    else if (hunds == 9){
        addNums = "CM";
    }
    
    temp = romNums; //Put into temp spot
    romNums = addNums; //Add in hundreds 
    romNums.append(temp); //Add on previous
    addNums.clear(); //Clear adding spot
    
    //***********************************
    //ADD THOUSANDS
    addNums.append(thous, 'M');
    
    temp = romNums; 
    romNums = addNums;
    romNums.append(temp);
    
    cout << year << " is equal to " << romNums;
 
    //Exit stage right or left!
    return 0;
}