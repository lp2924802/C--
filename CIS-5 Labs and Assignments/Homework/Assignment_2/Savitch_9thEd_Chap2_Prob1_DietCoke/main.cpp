/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 17, 2019, 12:36 AM
 * Purpose:  Find out how much soda my friend would need to consume to die from an
 *              artifical sweetener overdose.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

const float G_PER_LB = 453.592; //Grams per pound (grams/lb)

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    
    float wtHumnP; //Weight of person in (lbs)
    float wtHumnG; //Weight of person in (grams)
    float kllHumn; //Amount of sweetener to kill human (grams)
    
    float wtMouse = 35.0; //Weight of mouse (grams)
    float kllMous = 5.0; //Amount of sweetener to kill mouse (grams)
    
    float ratio; //Ratio of mass sweetener to mass of consumer for consumer to die (sweetener/consumer)
    
    float msSoda = 350.0; //Mass of one can of soda (grams)
    float swtSoda; //Amount of artifical sweetener in one can of soda (grams/can)
    int cans; //Number of cans of soda you can drink w/o dying (cans)
    const float PRP_SWT = 0.001f; //Proportion of soda that is artificial sweetener; 
    
    //Initialize or input i.e. set variable values
    
    
    
    ratio = kllMous / wtMouse; //Determine lethal ratio of sweetener to body mass (sweeter/consumer)
    swtSoda = msSoda * PRP_SWT; //Determine amount of artificial sweetener per can of soda (grams/can)
    
    //Map inputs -> outputs
    
    //Display the outputs
    
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;
    cin >> wtHumnP;
    
    wtHumnG = wtHumnP * G_PER_LB; //Calculate weight of human (grams)
    kllHumn = wtHumnG * ratio; //Calculate amount of sweetener to kill a human (grams)
    cans = kllHumn / swtSoda; // Calculate number of cans of soda human can drink (cans)
    
    
    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << cans << " cans";


    //Exit stage right or left!
    return 0;
}