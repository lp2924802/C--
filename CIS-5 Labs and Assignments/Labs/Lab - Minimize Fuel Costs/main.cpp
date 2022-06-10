/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 6, 2022, 1:20 AM
 * Purpose:  Lab 1 Minimize Fuel Costs. Design a program to determine
 *           the cost of gas in $/gal at two different gas stations, 
 *           with the final cost adjusted to reflect the added cost of 
 *           driving to each respective gas station. Display results.
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip> // For setprecision

using namespace std;

//User Defined Libraries

//Global Constants
const unsigned char CNVPERC = 100;// Conversion to %

int main(int argc, char** argv) {
    
    // Vehicle Variables
    float gGage = 0.75,  // (%) Gas Gauge % full
        tnkSize = 22,  // (gal) Size of tank in gallons
            mpg = 17,  // (miles/gal) Miles per gallon
            galReq; // (gal) Gallons required at fill-up
    
    // Gas Station 1 (GS 1) Variables
    float cst1 = 4.25, // ($/gal) Cost of regular gas in $/gallons @ GS 1
            miles1 = 10, // (miles) Miles to GS 1
            cstFup1, // ($) Cost to fill up @ GS 1 
            totDis1, // (miles) Total distance back & forth from GS 1
            galDrv1, // (gals) Gals of gas used driving back & forth from GS 1
            cstDrv1, // ($) Cost of driving back & forth from GS 1
            totCst1, // ($) Total cost of GS 1 when including drive
            totPpg1; // ($/gal) Total cost in $/gallons @ GS 1 with drive
 
    // Gas Station 2 (GS 2) Variables
    float cst2 = 4.09, // ($/gal) Cost of regular gas in $/gallons @ GS 2
            miles2 = 20, // (miles) Miles to GS 2
            cstFup2, // ($) Cost to fill up @ GS 2
            totDis2, // (miles) Total distance back & forth from GS 2
            galDrv2, // (gals) Gals of gas used driving back & forth from GS 2
            cstDrv2, // ($) Cost of driving back & forth from GS 2
            totCst2, // ($) Total cost of GS 2 when including drive
            totPpg2; // ($/gal) Total cost in $/gallons @ GS 2 with drive
 
      
    galReq = tnkSize * (1 - gGage); // Calculate gals req at fill-up 
    
    // GAS STATION 1
    cstFup1 = galReq * cst1; // (gal * $/gal = $) Calculate cost to fill up @ GS 1
    totDis1 = 2 * miles1; // (miles) Calculate total distance back & forth from GS 1
    galDrv1 = totDis1 / mpg; // (miles / (miles/gal) = gals) Calculate total gals used driving back & forth from GS 1
    cstDrv1 = cst1 * galDrv1; // ($/gal * gal = $) Calculate cost of drive back & forth from GS 1
    totCst1 = cstFup1 + cstDrv1; // ($) Calculate cost of fill up + drive for GS 1
    totPpg1 = totCst1 / galReq; // ($ / gal = $/gal) Calculate final cost of fill up + drive for GS 1
 
        // GAS STATION 2
    cstFup2 = galReq * cst2; // (gal * $/gal = $) Calculate cost to fill up @ GS 2
    totDis2 = 2 * miles2; // (miles) Calculate total distance back & forth from GS 2
    galDrv2 = totDis2 / mpg; // (miles / (miles/gal) = gals) Calculate total gals used driving back & forth from GS 2
    cstDrv2 = cst2 * galDrv2; // ($/gal * gal = $) Calculate cost of drive back & forth from GS 2
    totCst2 = cstFup2 + cstDrv2; // ($) Calculate cost of fill up + drive for GS 2
    totPpg2 = totCst2 / galReq; // ($ / gal = $/gal) Calculate final cost of fill up + drive for GS 2
    
    //Display the outputs
    cout << "\n  MINIMIZE FUEL COSTS: This program is designed to determine" << endl;
    cout << "  the cost of gas in $/gallon at two different gas stations" << endl;
    cout << "  when including the distance of the gas station into the" << endl;
    cout << "  final cost of gas." << endl;
    cout << "\n\t--------------------------------------" << endl;
    cout << "\t          VEHICLE INFORMATION" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t       Gas Gauge = " << gGage * CNVPERC << "% full" << endl;
    cout << "\t    Size of Tank = " << tnkSize << " gallons" << endl;
    cout << "\t     Gas Mileage = " << mpg << " miles/gallon" << endl;
    cout << "\t      Gas Needed = " << galReq << " gallons" << endl;
    cout << "\n\t--------------------------------------" << endl;
    cout << "\t             GAS STATION 1" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t     Regular Gas = $" << cst1 << "/gallon" << endl;
    cout << "\t        Distance = " << miles1 << " miles away" << endl;
    cout << "\t      Final Cost = $" << fixed << setprecision(2) << totPpg1 << "/gallon" << endl;
    cout << "\n\t--------------------------------------" << endl;
    cout << "\t             GAS STATION 2" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t     Regular Gas = $" << cst2 << "/gallon" << endl;
    cout << "\t        Distance = " << fixed << setprecision(0) << miles2 << " miles away" << endl;
    cout << "\t      Final Cost = $" << fixed << setprecision(2) << totPpg2<< "/gallon" << endl;
    

    return 0;
}