/* 
 * File:   main.cpp
 * Version: V1.22
 * Author: Lauren Postlethwaite
 * Created on January 31, 2022, 4:17 PM
 * Purpose: Project 1: Yahtzee Game
 */

#include <iostream> //I/O Library
#include <iomanip>  //Formatting Library
#include <string>   //String Variable
#include <cstdlib>  //Random Number Library
#include <ctime>    //Time Library
#include <windows.h> //Curious if this works...
using namespace std;

//Function Prototypes
void yesNo(char&); //Yes/no input validation
int getNum(char, char); //Integer input validation
void getTrn(int&,int&,int&,int&,int&); //Get final dice rolls from player turn
const char* label(bool&,int,int,char); //Get dice output labels


//Begin Here
int main(int argc, char** argv) {
    
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int die1 = 1,die2 = 1,die3 = 1,die4 = 1,die5 = 1; //Five dice, initialized to 1
    char ready; //Gameplay flag
    char again; //Roll again flag
    
    cout<<"Let's play a game..."<<endl;
    
    cout<<"Starting Dice: "<<die1<<", "<<die2<<", "<<die3<<", "<<die4<<", "<<die5<<endl;
    
    getTrn(die1,die2,die3,die4,die5);
    
    cout<<"Now your dice are: "<<die1<<", "<<die2<<", "<<die3<<", "<<die4<<", "<<die5<<endl;

    return 0;
}


//THREE ROLL TURN FUNCTION******************************************************
void getTrn(int &refDie1, int &refDie2, int &refDie3, int &refDie4, int &refDie5){
   //Declare local variables
    int nRolls = 3; //Number of rolls in a turn (For later)
    int roll = 1; //Current roll, initialized to 1
    int yesInt;
    char keep, ret, yesDie;
    char die = 'd'; //ID for die count
    char val = 'v'; //ID for die value
    const char chgKeep = 'x'; //Flag to keep
    const char chgRet = 'r'; //Flag to return
    bool rOne = true, rTwo = true, rThree = true, rFour = true, rFive = true;
    char again = 'y'; //Roll again checker, initialized to yes
    string d1, d2, d3, d4, d5; //String names for dice
    
    //Character conversions for die strings
    const char* charD1;
    const char* charD2;
    const char* charD3;
    const char* charD4;
    const char* charD5;
    
    //Roll loop
    for (roll=1; roll<=nRolls; roll++){
        //Roll dice 
        if (rOne == true){
            refDie1 = rand()%6+1;
            d1 = to_string(refDie1);
        }
        if (rTwo == true){
            refDie2 = rand()%6+1;
            d2 = to_string(refDie2);
        }
        if (rThree == true){
            refDie3 = rand()%6+1;
            d3 = to_string(refDie3);
        }
        if (rFour == true){
            refDie4 = rand()%6+1;
            d4 = to_string(refDie4);
        }
        if (rFive == true){
            refDie5 = rand()%6+1;
            d5 = to_string(refDie5);
        }
        
      
        //List Roll Outcome
        cout<<endl<<"Roll #"<<roll<<": "<<d1<<", "<<d2<<", "<<d3<<", "
                            <<d4<<", "<<d5<<endl;
        
        //If you have more rolls left
        if (roll<3){
            cout<<endl<<"Roll again? (Y/N) ";
            cin>>again; //Get input
            yesNo(again); //Validate input
            
            //Respond to "Roll again" input
            if (again=='n' || again=='N')
                roll = 1000;
            else if (again=='y' || again=='Y'){
                
                //Decide if keeping any dice
                cout<<"Keep any dice? (Y/N) ";
                cin>>keep; //Get input
                yesNo(keep); //Validate input
                
                //While loop for keeping dice
                while (keep=='y' || keep=='Y'){
                    //Pick dice to keep
                    cout<<"Input the # of the die you want to keep: ";
                    cin>>yesDie; //Get input
                    yesInt = getNum(yesDie,die); //Validate and convert yesDie input
                    
                    //Switch function to change string output of dice
                    switch(yesInt){
                        case 1: {
                            charD1 = label(rOne,yesInt,refDie1,chgKeep);
                            string d1(charD1);
                            break;
                        }
                        case 2: {
                            charD2 = label(rTwo,yesInt,refDie2,chgKeep);
                            string d2(charD2);
                            break;
                        }
                        case 3: {
                            charD3 = label(rThree,yesInt,refDie3,chgKeep);
                            string d3(charD3);
                            break;
                        }
                        case 4: {
                            charD4 = label(rFour,yesInt,refDie4,chgKeep);
                            string d4(charD4);
                            break;
                        }
                        case 5: {
                            charD5 = label(rFive,yesInt,refDie5,chgKeep);
                            string d5(charD5);
                            break;
                        }
                        default: {
                            cout<<"Bad code"<<endl;
                        }
                    }
                    cout<<"Current Dice: "<<d1<<", "<<d2<<", "<<d3<<", "<<d4<<", "<<d5<<endl;
                    //Prompt pick again
                    cout<<endl<<"Keep more dice? (Y/N) ";
                    cin>>keep; //Get input
                    yesNo(keep); //Validate input
                  
                }
                
                //Prompt return dice
                cout<<"Return any dice? (Y/N) ";
                cin>>ret; //Get input
                yesNo(ret); //Validate input
                
                //While loop for returning dice
                while (ret=='y' || ret=='Y'){
                    //Pick dice to return
                    cout<<"Input the # of the die you want to return: ";
                    cin>>yesDie; //Get input
                    yesInt = getNum(yesDie,die); //Validate and convert yesDie input
                    
                    //Switch function to change string output of dice
                    switch(yesInt){
                        case 1: {
                            charD1 = label(rOne,yesInt,refDie1,chgRet);
                            string d1(charD1);
                            cout<<d1;
                            break;
                        }
                        case 2: {
                            charD2 = label(rTwo,yesInt,refDie2,chgRet);
                            string d2(charD2);
                            break;
                        }
                        case 3: {
                            charD3 = label(rThree,yesInt,refDie3,chgRet);
                            string d3(charD3);
                            break;
                        }
                        case 4: {
                            charD4 = label(rFour,yesInt,refDie4,chgRet);
                            string d4(charD4);
                            break;
                        }
                        case 5: {
                            charD5 = label(rFive,yesInt,refDie5,chgRet);
                            string d5(charD5);
                            break;
                        }
                        default: {
                            cout<<"Bad code"<<endl;
                        }
                    }
                    
                    //Prompt return again
                    cout<<"Return more dice? (Y/N) ";
                    cin>>ret; //Get input
                    yesNo(ret); //Validate input
                  
                }
            }
            
            cout<<"Press enter to roll: "<<endl;
            cin.ignore(1000000000, '\n');
        }
    }
    
    return;

}


//DIE LABEL RETURNER************************************************************
const char* label(bool &roll, int dieNum, int dieVal, char keepRet){
    //Local variables/constants
    string one = "1", two = "2", three = "3", four = "4", five = "5", six = "6";
    string oneBr = "[1]", twoBr = "[2]", threeBr = "[3]", fourBr = "[4]",
            fiveBr = "[5]", sixBr = "[6]";
    const char* newName;
    //If keepRet = 'x' --> Player attempting to keep die
    if (keepRet=='x'){
        //Die still rollable --> put into brackets
        if (roll){
            switch(dieVal){
                case 1: {
                    const char* newName = &oneBr[0];
                    break; 
                }
                case 2: {
                    const char* newName = &twoBr[0];
                    break;
                }
                case 3: {
                    const char* newName = &threeBr[0];
                    break;
                }
                case 4: {
                    const char* newName = &fourBr[0];
                    break;
                }
                case 5: {
                    const char* newName = &fiveBr[0];
                    break;
                }
                case 6: {
                    const char* newName = &sixBr[0];
                    break;
                }
                default: {
                    cout<<"Bad code"<<endl;
                }
            }
            //Mark die as held
            roll = false;
        }
        else if (!roll){
            cout<<"Die #"<<dieNum<<" is already being held."<<endl;
        }
        else{
            cout<<"Bad code"<<endl;
        } 
    }
    //If keepRet = 'r' --> Player attempting to return die
    else if (keepRet=='r'){
        if (roll){
            cout<<"Die #"<<dieNum<<" is not being held."<<endl;
        }
        else if (!roll){
            switch(dieVal){
                case 1: {
                    const char* newName = &one[0];
                    break;
                }
                case 2: {
                    const char* newName = &two[0];
                    break;
                }
                case 3: {
                    const char* newName = &three[0];
                    break;
                }
                case 4: {
                    const char* newName = &four[0];
                    break;
                }
                case 5: {
                    const char* newName = &five[0];
                    break;
                }
                case 6: {
                    const char* newName = &six[0];
                    break;
                }
                default: {
                    cout<<"Bad code"<<endl;
                }
            }
            //Mark die as returned
            roll = true;
        }
        else {
            cout<<"Bad code"<<endl;
        }
    }
    else {
        cout<<"Bad code"<<endl;
    }
    return newName;
}

//YES/NO INPUT CHECKER**********************************************************
void yesNo(char &input){
    //Loop while input is not yes/no format
    while (input!='y' && input!='Y' && input!='n' && input!='N'){
        cout<<"ERROR: Please enter either 'Y' or 'N':"<<endl;
        cin>>input;
    }
    return;
}
    

//VALIDATE INTEGER INPUT********************************************************
int getNum(char num, char max){
    
    //Declare local variables
    int chkNum; //Check number input
    int numInt; //Integer version of number
    char numAgn; //New/local version of number
    bool numOk = false; //Flag number as integer, initialized to false
    bool numLng = false; //Number length flag, initialized to false
    
    //Initialize local variables
    numAgn = num;
    
    do{
        do{
            //Check if input is an integer
            chkNum = isdigit(numAgn);
            
            //If integer -> flag as okay and convert char -> int
            if (chkNum){
                numOk = true;
                numInt = numAgn - '0';
            }
            else {
                //If not integer -> output error message and request input again
                if (max=='d'){
                    cout<<"ERROR: Input a number from 1 to 5. ";
                }
                else if (max=='v'){
                    cout<<"ERROR: Input a number from 1 to 6. ";
                }
                else {
                    cout<<"Bad code";
                }
                cin>>numAgn; //Input again
            }
        }while (numOk==false);
        
        //Check if integer is in range
        if (max=='d'){
            if (numInt>0 && numInt < 6){
                numLng = true; //Flag integer as in range
            }
            else if (numInt<=0 || numInt>=6){
                //Output error message
                cout<<"ERROR: Input a number from 1 to 5. ";
                cin>>numAgn; //Input again
            }
            else {
                cout<<"Bad code";
            }
        }
        else if (max=='v'){
            if (numInt>0 && numInt<7){
                numLng = true; //Flag integer as in range
            }
            else if (numInt<=0 || numInt>=7){
                //Output error message
                cout<<"ERROR: Input a number from 1 to 6. ";
                cin>>numAgn; //Input again
            }
            else {
                cout<<"Bad code";
            }
        }
    }while (numLng==false);
   
    return numInt;
}