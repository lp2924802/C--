/* 
 * File:  main.cpp 
 * Author: Lauren Postlethwaite
 * Created on January 24, 2022, 10:43 PM
 * Purpose:  Enhance previous program (Sav9EdC4P4) by having it also print out
 *              the estimated price of the item in one and in two years from 
 *              the time of the calculation.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//Function Prototypes
float getInfl(float, float); //Get Inflation Rate - Function Prototype
float futPrc (float, float, int); //Predict Future Price - Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float prcCur; //Current price
    float prcOld; //Old price
    float infl; //Inflation rate
    char again = 'y'; //Repeat checker
    
    do {
        
        cout << "Enter current price:" << endl;
        cin >> prcCur; //Input current price
        cout << "Enter year-ago price:" << endl;
        cin >> prcOld; //Input old price
        
        infl = getInfl(prcCur, prcOld); //Get inflation rate from getInfl function call
        
        cout << "Inflation rate: " << fixed << setprecision(2) << infl << "%" << endl;
        
        cout << endl << "Price in one year: $" << fixed << setprecision(2)
                        << futPrc(prcCur, infl, 1) << endl;
        cout << "Price in two year: $" << fixed << setprecision(2)
                        << futPrc(prcCur, infl, 2) << endl;
        
        cout << endl << "Again:" << endl;
        cin >> again;
        
        if (again != 'n'){
            cout << endl;
        }
    } while (again != 'n');

    //Exit stage right or left!
    return 0;
}


//GET INFLATION RATE***********
float getInfl(float prcNow, float prcPast){
    
    float prcDif; //Difference between old and new price;
    float perOld; //Percentage of old price (decimal)
    float perFixd; //Percentage of old price (corrected to % value)
    
    prcDif = prcNow - prcPast; //Calculate difference in old and new prices
    perOld = prcDif / prcPast; //Calculate percent change
    perFixd = perOld * 100;
    
    return perFixd;
}


//PREDICT FUTURE PRICE**********
float futPrc(float price, float inf, int years){
    
    float infDec; //Converted inflation percentage back to decimal format
    float infAdd; //Inflation added onto 1 so it can be used in simple multiplication
    float nxtPrc; //Next price (current + expected inflation)
    int i = 0; //Counter variable, initialized to zero
    
    infDec = inf / 100; //Convert inflation percentage back to decimal format 
    nxtPrc = price; //Initialize future price to current price
    infAdd = infDec + 1; //Determine multiplicative representation of inflation
    
    for (i = 0; i < years; i++){
        
        nxtPrc = nxtPrc * infAdd; //Calculate expected price for next year
        
    }
    
    return nxtPrc; //Return predicted price after # of years
}