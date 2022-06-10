/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Postl
 *
 * Created on January 4, 2022, 5:42 PM
 */

/*
 * Homework Assignment 1
 * Chapter 2 - Gaddis
 * Lauren Postlethwaite
 * 
 * Programming Problem #3
 * 6. Annual Pay*/
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Suppose an employee gets paid every two weeks and earns
 * $2,200 each pay period. In a year, the employee gets paid 26
 * times. Write a program that defines the following variables:
 * (payAmount, payPeriods, annualPay)
 * The program should calculate the employee's total annual pay by
 * multiplying the employee's pay amount by the number of pay
 * periods in a year and store the result in the annualPay variable.
 * Display the total annual pay on the screen.
 */

/* NOTE: VARIABLES WRITTEN LONGER THAN SEVEN CHARACTERS DUE TO
 * SPECIFICATIONS OF PROBLEM
 */
int main(int argc, char** argv) {

    float payAmount = 2200.0; // Employee's biweekly salary in dollars
    int payPeriods = 26; // Number of pay periods in one year
    float annualPay; // Employee's annual pay in dollars
    
    annualPay = payAmount * payPeriods;
    
    cout << " At a biweekly salary of $" << payAmount << ", you will make $" << annualPay << " in one year.";
    return 0;
}

