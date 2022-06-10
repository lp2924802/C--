/* 
 * File:   main.cpp
 * Version: V1.3
 * Author: Lauren Postlethwaite
 * Created on February 1, 2022, 6:51 PM
 * Purpose: Project 1: Yahtzee Game
 */

#include <cstdlib> //Random Number Library
#include <ctime> //Time Library
#include <iostream> //Input/Output Library
#include <iomanip> //Formatting Library
#include <string> //String Variable Type
#include <windows.h>
using namespace std;

//Function Prototypes
void getIntro(); //Game Introduction
void yesNo(char&); //Yes/no input validation
int getNum(char, char); //Integer input validation
void getCard(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int); //Print/display scorecard



//Begin Here
int main(int argc, char** argv) {
    
    //Random number seed
     srand(static_cast<unsigned int>(time(0)));
    
    //Declare general variables
     
    //Declare upper section scorecard variables
    int num1US, num2US, num3US, num4US, num5US, num6US; //Scores for 1-6's
    int tot1t6, bonUS, totUS; //Total for 1-6's, bonus points, total for upper section
    bool full1US=false, full2US=false, full3US=false, full4US=false, full5US=false, full6US=false;//If 1-6 spots taken, initialized to false/open
    //Declare lower section scorecard variables
    int num3k, num4k, numFH, numSmS, numLgS, numYtz, numChc; //Scores for 3 kind, 4 kind, full house, small str., large str, Yahtzee, and chance
    int ytzB1, ytzB2, ytzB3, ytzB4; //Yahtzee bonus slots
    bool full3k=false, full4k=false, fullFH=false, fullSms=false, fullLgS=false, fullYtz=false, fullChc=false; //Same as LS scores but with slot indicators, initialized to false
    bool fullYB1=false, fullYB2=false, fullYB3=false, fullYB4=false; //Flags for Yahtzee bonus slots
    int ytzBtot, totLS, grTot; //Yahtzee bonus total, total of lower section, grand total
     
    /*int gmeCt = 1; //Game number, initialized to 1
    int die1 = 1,die2 = 1,die3 = 1,die4 = 1,die5 = 1; //Five dice, initialized to 1
    const int D_1 = 1, D_2 = 2, D_3 = 3, D_4 = 4, D_5 = 5; //Dice number indicators
    */ //Revisit if NOT allowed to do arrays, or can't figure them out
     
    const int DICE = 5; //Number of dice
    const int diceNum[DICE] = {1,2,3,4,5}; //Dice number indicators
    int diceVal[DICE] = {1,1,1,1,1}; //Value of each die, initialized to zero
    bool roll[DICE] = {true}; //Rollable  flag, initialized to true
    
    
    char ready; //Gameplay flag
    //char again; //Roll again flag
    bool all = false; //Flag indicating that all spaces have been filled
    
    //Declare scorecard variables
    
    

    cout<<"\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2557"<<endl;
    
    cout<<"\u2551"<<right<<setw(29)<<"\"UPPER\" SECTION       "<<"\u2551\u2551"<<right<<setw(32)<<"\"LOWER\" SECTION        "<<"\u2551"<<endl;
    
    cout<<"\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2566\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2563"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"      Aces"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"  3 of a kind"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2562\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2562"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"      Twos"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"  4 of a kind"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2562\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2562"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"     Threes"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"   Full House"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2562\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2562"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"      Fours"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"  SM Straight"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2562\u2551"<<left<<setw(16)<<" (sequence of 4)"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"      Fives"<<"\u2551"<<right<<setw(15)<<"\u2551"<<"\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2562"<<endl;
    
    cout<<"\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2562\u2551"<<left<<setw(16)<<"  LG Straight"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"      Sixes"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<" (sequence of 5)"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
   
    cout<<"\u255f\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2562"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"      TOTAL"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"     Yahtzee"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    cout<<"\u2551"<<left<<setw(16)<<"      SCORE"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"  (5 of a kind)"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u255f\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\u255f\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2562"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"      BONUS"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"     Chance"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u2551"<<left<<setw(16)<<"(If total >= 63)"<<"\u2551"<<right<<setw(18)<<"\u2551\u255f"<<"\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u256b\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2508"
            "\u2508\u2508\u2508\u2508\u2508\u2508\u2508\u2562"<<endl;
    
    cout<<"\u255f\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\u2551"<<left<<setw(16)<<"     Yahtzee"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
   
    cout<<"\u2551"<<left<<setw(16)<<"    TOTAL OF"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"      Bonus"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    cout<<"\u2551"<<left<<setw(16)<<"\"UPPER\" SECTION"<<"\u2551"<<right<<setw(18)<<"\u2551\u2551"<<right<<setw(19)<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<"\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2569\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2563"<<endl;
    
    cout<<right<<setw(34)<<"\u2551"<<left<<setw(16)<<"    TOTAL OF"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    cout<<right<<setw(34)<<"\u2551"<<left<<setw(16)<<"\"LOWER\" SECTION"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<right<<setw(34)<<"\u2560"<<"\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2563"<<endl;
    
    cout<<right<<setw(34)<<"\u2551"<<left<<setw(16)<<"    TOTAL OF"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    cout<<right<<setw(34)<<"\u2551"<<left<<setw(16)<<"\"UPPER\" SECTION"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
     cout<<right<<setw(34)<<"\u2560"<<"\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2563"<<endl;
    
    cout<<right<<setw(34)<<"\u2551"<<left<<setw(16)<<"      GRAND"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    cout<<right<<setw(34)<<"\u2551"<<left<<setw(16)<<"      TOTAL"<<"\u2551"<<right<<setw(18)<<"\u2551"<<endl;
    
    cout<<right<<setw(34)<<"\u255a"<<"\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
            "\u2550\u2550\u2550\u2550\u255d"<<endl;
    
    //getIntro; //Get game introduction

    /*cout<<"Ready to play? (Y/N) "; //Prompt beginning of game
    cin>>ready; //Get input
    yesNo(ready); //Validate input */
    
    
   
        
    
    
    /*
    //GAMEPLAY HERE --> (One loop = One entire game)****************************
    while (ready=='y' || ready=='Y'){
        
        cout<<setw(3)<<"Hi";
        
        //ROLL FOR TURN --> (Each iteration = one "turn")
        while (!all){ //While all scorecard spaces NOT filled
            cout<<"Hi"<<endl;
        }
    }
*/
    return 0;
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



//PRINT SCORECARD***************************************************************
void getCard(int aces, int twos, int threes, int fours, int fives, int sixes, int totNum, int bonUS, int totUS, int kind3, int kind4, int fHouse, int smSt, int lgSt, int ytz, int chance, int yb1, int yb2, int yb3, int yb4, int ybTot, int totLS, int grTot){
    
    //Left column
    cout<<"\u2503"<<"\u2502"<<endl;
}




//NOTES
/* cout<<"\033[2J\033[1;1H"; <-- CLEAR SCREEN*/