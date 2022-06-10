/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19th, 2022, 8:53 AM
 * Purpose:  Basic Menu for Homework and Exams
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time library
#include <iomanip>   //Formatting Lbrary
#include <cmath>     //Math Library - Log Function
#include <string>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int choose;//Choose a problem
    
    //Initialize variables here
    do{
        //Display the menu
        cout<<endl;
        cout<<"Choose from the following Menu Items"<<endl;
        cout<<"Problem 0 - Books - Gaddis 9thEd Chap4 Prob11"<<endl;
        cout<<"Problem 1 - Sort Names - Gaddis 9thEd Chap4 Prob8"<<endl;
        cout<<"Problem 2 - Bank Charges - Gaddis 9thEd Chap4 Prob12"<<endl;
        cout<<"Problem 3 - Race - Gaddis 9thEd Chap4 Prob14"<<endl;
        cout<<"Problem 4 - ISP - Gaddis 9thEd Chap4 Prob23"<<endl;
        cout<<"Problem 5 - Rock Paper Scissors - Savitch 9thEd Chap3 PracProbl"<<endl;
        cout<<"Problem 6 - Roman Conversion - Savitch 9thEd Chap3 Prob3"<<endl;
        cout<<"Etc......"<<endl;
        cout<<"10 or greater, all negatives to exit"<<endl;
        cout<<endl;
        cin>>choose;
        
        //Display the Solution to the problems
        switch(choose){
            //CASE 0***********************************
            case 0:{  
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
                cout << left << setw(16) << "Points earned" << "=" << right << setw(3) << points << endl;
                break;}
            
            
            //CASE 1*******************************
            case 1:{    
                int count = 0; //Counter
                const int NAME_NUM = 3; //Number of names in nameIn array 
                string nameIn[NAME_NUM]; //Array to hold names
                string nameOut[NAME_NUM]; //Array to hold names in order

                //Display the outputs
    
                cout << "Sorting Names" << endl;
                cout << "Input 3 names" << endl;
    
                for (count = 0; count < NAME_NUM; count++){
                    cin >> nameIn[count]; //Input name
                }
    
                if (nameIn[0] < nameIn[1] && nameIn[0] < nameIn[2]){
                    nameOut[0] = nameIn[0]; //Place first entry in first output slot
                    if (nameIn[1] < nameIn[2]){
                        nameOut[1] = nameIn[1]; //Place second entry in second output slot
                        nameOut[2] = nameIn[2]; //Place third entry in third output slot
                    }
                    else {
                        nameOut[1] = nameIn[2]; //Place third entry in second output slot
                        nameOut[2] = nameIn[1]; //Place second entry in third output slot
                    }
                }
                else if (nameIn[1] < nameIn[0] && nameIn[1] < nameIn[2]){
                    nameOut[0] = nameIn[1]; //Place second entry in first output slot
                    if (nameIn[0] < nameIn[2]) {
                        nameOut[1] = nameIn[0]; //Place first entry in second output slot
                        nameOut[2] = nameIn[2]; //Place third entry in third output slot
                    }
                    else {
                        nameOut[1] = nameIn[2]; //Place third entry in second output slot
                        nameOut[2] = nameIn[0]; //Place first entry in third output slot
                    }
                }
                else {
                    nameOut[0] = nameIn[2]; //Place third entry in first output slot
                    if (nameIn[0] < nameIn[1]) {
                        nameOut[1] = nameIn[0]; //Place first entry in second output slot
                        nameOut[2] = nameIn[1]; //Place second entry in third output slot
                    }
                    else {
                        nameOut[1] = nameIn[1]; //Place second entry in second output slot
                        nameOut[2] = nameIn[0]; //Place first entry in third output slot
                    }
                }
    
                cout << nameOut[0] << endl << nameOut[1] << endl << nameOut[2];
                break;}
            
            
            //CASE TWO********************************
            case 2:{
                //Declare Variables
                float balance; //Bank account balance
                unsigned int checks; //Number of checks
                float perChk; //Price per check
                float chkFee; //Check Fee 
                float monFee = 10; //Monthly Fee, initialized to $10 
                float lowBal; //Low Balance Fee
                float newBal; //New Balance 

                //Program

                cout << "Monthly Bank Fees" << endl;
                cout << "Input Current Bank Balance and Number of Checks" << endl;

                cin >> balance >> checks; //Input balance and number of checks

                //CHECK FOR OVERDRAWN ACCOUNT
                if (balance < 0){
                    cout << "Warning: Account Overdrawn!" << endl;
                }

                //CHECK FOR LOW BALANCE
                if (balance < 400) {
                    lowBal = 15;
                }

                //DETERMINE PRICE PER CHECK
                if (checks < 20) {
                    perChk = 0.10;
                }
                else if (checks < 40) {
                    perChk = 0.08; 
                }
                else if (checks < 60) {
                    perChk = 0.06;
                }
                else {
                    perChk = 0.04;
                }

                //DETERMINE PRICE OF CHECKS 
                chkFee = checks * perChk;


                //DETERMINE NEW BALANCE 
                newBal = balance - monFee - chkFee - lowBal;

                //DISPLAY RESULTS
                cout << left << setw(12) << "Balance" << "$" << right << setw(9)
                    << fixed << setprecision(2) << balance << endl;
                cout << left << setw(12) << "Check Fee" << "$" << right << setw(9)
                    << fixed << setprecision(2) << chkFee << endl;
                cout << left << setw(12) << "Monthly Fee" << "$" << right << setw(9)
                    << fixed << setprecision(2) << monFee << endl;
                cout << left << setw(12) << "Low Balance" << "$" << right << setw(9)
                    << fixed << setprecision(2) << lowBal << endl;
                cout << left << setw(12) << "New Balance" << "$" << right << setw(9)
                    << fixed << setprecision(2) << newBal;
                break;}
            
            //CASE 3********************************
            case 3: {
                //Declare Variables
                const int SIZE = 3; //Size of arrays
                string name[SIZE]; //Runners
                unsigned int times[SIZE]; //Times of runners 
                string tempN; //Placeholder 
                int i, j, min, tempT; //Counters and minimum time value placeholder

                //Initialize or input i.e. set variable values

                //Map inputs -> outputs

                //Display the outputs

                cout << "Race Ranking Program" << endl;
                cout << "Input 3 Runners" << endl;
                cout << "Their names, then their times" << endl;

                for (i = 0; i < SIZE; i++){

                    cin >> name[i] >> times[i];
                }

                i = 0; //Reset count to 0 

                //Move boundary of unsorted subarray one by one
                for (i = 0; i < SIZE - 1; i++){

                    min = i; //Set current to minimum 

                    //Find the minimum element in the unsorted array
                    for (j = i + 1; j < SIZE; j++) {

                        if (times[j] < times[min]){
                            min = j;
                        }

                        //Swap the newly found minimum element with the first element
                        tempT = times[min];
                        tempN = name[min];
                        times[min] = times[i];
                        name[min] = name[i];
                        times[i] = tempT;
                        name[i] = tempN;

                    }
                }

                i = 0; //Reset i to zero again

                for (i = 0; i < SIZE; i++){
                    cout << name[i] << "\t" << setw(3) << times[i];

                    if (i == 0 || i == 1){
                        cout << endl;
                    }

                }
                break;}
            
            //CASE 4******************************  
            case 4: {
                //Declare Variables
                char package; //Package type
                unsigned int hours; //Number of hours
                int xtrHrs = 0; //Hours past limit, initialized to 0
                float rate = 0; //Hourly rate for extra hours, initialized to zero
                float base; //Base cost for package
                float cost; //Monthly bill


                //Display the outputs
                cout << "ISP Bill" << endl;
                cout << "Input Package and Hours" << endl;

                cin >> package;

                if (package != 'A' && package != 'B' && package != 'C'){
                    cout << "ERROR: Please enter A, B, or C" << endl;
                }

                cin >> hours;

                if (package == 'A'){
                    base = 9.95;
                    if (hours > 10){
                        xtrHrs = hours - 10;
                        rate = 2;
                    }
                }
                else if (package == 'B'){
                    base = 14.95;
                    if (hours > 20){
                        xtrHrs = hours - 20;
                        rate = 1;
                    }
                }
                else {
                    base = 19.95;
                }

                cost = (xtrHrs * rate) + base;

                cout << "Bill = $" << setw(6) << fixed << setprecision(2) << cost;    
            break;}
                                          
            //CASE 5*************************************    
            case 5: {
                //Declare Variables
                char player1, player2; //Player inputs

                //Display the outputs
                cout << "Rock Paper Scissors Game" << endl;
                cout << "Input Player 1 and Player 2 Choices" << endl;

                cin >> player1;

                if (player1 != 'R' && player1 != 'r' && player1 != 'P' && player1 != 'p'
                            && player1 != 'S' && player1 != 's'){
                                cout << "ERROR: Please enter R, P, or S" << endl;
                            }

                player1 = toupper(player1); //Set input to uppercase


                cin >> player2;

                if (player2 != 'R' && player2 != 'r' && player2 != 'P' && player2 != 'p'
                            && player2 != 'S' && player2 != 's'){
                                cout << "ERROR: Please enter R, P, or S" << endl;
                            }

                player2 = toupper(player2); //Set input to uppercase

                if (player1 == player2){
                    cout << "Nobody wins";
                }
                else if (player1 == 'R'){
                    if (player2 == 'P'){
                        cout << "Paper covers rock.";
                    }
                    else if (player2 == 'S'){
                        cout << "Rock breaks scissors.";
                    }
                }
                else if (player1 == 'P'){
                    if (player2 == 'R'){
                        cout << "Paper covers rock.";
                    }
                    else if (player2 == 'S'){
                        cout << "Scissors cuts paper.";
                    }
                }
                else if (player1 == 'S'){
                    if (player2 == 'R'){
                        cout << "Rock breaks scissors.";
                    }
                    else if (player2 == 'P'){
                        cout << "Scissors cuts paper.";
                    }
                }
            break;} 
            
            //CASE 6*********************************
            case 6: {
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
            break;}
            
            //CASE 7*********************************
            case 7: {
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
            break;}
            
            default:cout<<"Exiting the Menu"<<endl;
        }
    }while(choose>=0 && choose<=9);

    return 0;
}