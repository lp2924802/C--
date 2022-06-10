/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Postl
 *
 * Created on January 4, 2022, 4:57 PM
 * 
 */

/*
 * Homework Assignment 1
 * Chapter 2 - Gaddis
 * Lauren Postlethwaite
 * 
 * Programming Problem #1
 * 1. Sum of Two Numbers*/

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Write a program that stores the integers 50 and 100 in variables,
 * and stores the sum of these two in a variable named total. 
 */
int main(int argc, char** argv) {

    int varOne = 50;
    int varTwo = 100;
    int total;
    
    total = varOne + varTwo;
    
    cout << "This program stores the integers " << varOne << " and " << varTwo << " in variables." << endl;
    cout << "The sum of these two integers is stored in a variable named total and is equal to " << total << ".";
    
    return 0;
}

