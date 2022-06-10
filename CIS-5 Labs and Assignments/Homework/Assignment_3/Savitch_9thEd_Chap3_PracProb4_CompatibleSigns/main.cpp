/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2022, 8:07 PM
 * Purpose:  Write a program to determine horoscope compatibility.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   //String Variable Type
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    string sign1, sign2; //Signs
    string elm1, elm2; //Elements of signs
    
    
    //Display the outputs
    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;
    
    cin >> sign1 >> sign2;
    
    //DETERMINE ELEMENT OF SIGN ONE
    if (sign1 == "Aries" || sign1 == "Leo" || sign1 == "Sagittarius"){
        elm1 = "Fire";
    }
    else if (sign1 == "Taurus" || sign1 == "Virgo" || sign1 == "Capricorn"){
        elm1 = "Earth";
    }
    else if (sign1 == "Gemini" || sign1 == "Libra" || sign1 == "Aquarius"){
        elm1 = "Air";
    }
    else if (sign1 == "Cancer" || sign1 == "Scorpio" || sign1 == "Pisces"){
        elm1 = "Water";
    }
    
    //DETERMINE ELEMENT OF SIGN TWO
    if (sign2 == "Aries" || sign2 == "Leo" || sign2 == "Sagittarius"){
        elm2 = "Fire";
    }
    else if (sign2 == "Taurus" || sign2 == "Virgo" || sign2 == "Capricorn"){
        elm2 = "Earth";
    }
    else if (sign2 == "Gemini" || sign2 == "Libra" || sign2 == "Aquarius"){
        elm2 = "Air";
    }
    else if (sign2 == "Cancer" || sign2 == "Scorpio" || sign2 == "Pisces"){
        elm2 = "Water";
    }
    
    //DETERMINE COMPATIBILITY 
    if (elm1 == elm2){
        cout << sign1 << " and " << sign2 << " are compatible " << elm1 << " signs.";
    }
    else {
        cout << sign1 << " and " << sign2 << " are not compatible signs.";
    }
        

    //Exit stage right or left!
    return 0;
}