/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Postl
 *
 * Created on January 4, 2022, 5:55 PM
 */

/*
 * Homework Assignment 1
 * Chapter 2 - Gaddis
 * Lauren Postlethwaite
 * 
 * Programming Problem #4
 * 8. Total Purchase*/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Write a program that holds the prices of the five items in five
 * variables. Display each item's price, the subtotal of the sale, the
 * amount of sales tax, and the total. Assume the sales tax is 7
 * percent.
 */

int main(int argc, char** argv) {
    float item1 = 15.95; // Item 1 in dollars
    float item2 = 24.95; // Item 2 in dollars
    float item3 = 6.95; // Item 3 in dollars
    float item4 = 12.95; // Item 4 in dollars
    float item5 = 3.95; // Item 5 in dollars
    float subtot; // Subtotal cost in dollars
    float taxRate = 0.07; // Sales tax rate, where 1.00 is 100%
    float slesTax; // Total sales tax in dollars
    float totPur; // Total purchase in dollars
    
    subtot = item1 + item2 + item3 + item4 + item5;
    slesTax = subtot * taxRate;
    totPur = subtot + slesTax;
    
    cout << "  Item:      Price:" << endl;
    cout << " --------------------" << endl;
    cout << "  Item 1  =  $" << item1 << endl;
    cout << "  Item 2  =  $" << item2 << endl;
    cout << "  Item 3  =   $" << item3 << endl;
    cout << "  Item 4  =  $" << item4 << endl;
    cout << "  Item 5  =   $" << item5 << endl;
    cout << " --------------------" << endl;
    cout << "  Subtotal:  $" << subtot << endl;
    cout << " Sales Tax:   $" << fixed << setprecision(2) << slesTax << "   (Sales Tax = 7.00%)" << endl;
    cout << " --------------------" << endl;
    cout << "     Total:  $" << fixed << setprecision(2) << totPur;
    
    return 0;
}

