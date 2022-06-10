/* 
 * File:   main.cpp
 * Version: V1.31
 * Author: Lauren Postlethwaite
 * Created on February 2, 2022, 12:24 AM
 * Purpose: Project 1: Yahtzee Game. Scorecard now correctly appears (while
 *              empty) and the infinite For-Loop has been repaired).
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
void turnVal(char&); //Turn response validation
int getNum(char, char); //Integer input validation
void getCard(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int); //Print/display scorecard



//Begin Here
int main(int argc, char** argv) {
    
    //Random number seed
     srand(static_cast<unsigned int>(time(0)));
    
    //Declare general variables
     
    //Declare upper section scorecard variables
    int num1US=0, num2US=0, num3US=0, num4US=0, num5US=0, num6US=0; //Scores for 1-6's, initialized to zero
    int tot1t6=0, bonUS=0, totUS=0; //Total for 1-6's, bonus points, total for upper section, initialized to zero
    bool full1US=false, full2US=false, full3US=false, full4US=false, full5US=false, full6US=false;//If 1-6 spots taken, initialized to false/open
    //Declare lower section scorecard variables
    int num3k=0, num4k=0, numFH=0, numSmS=0, numLgS=0, numYtz=0, numChc=0; //Scores for 3 kind, 4 kind, full house, small str., large str, Yahtzee, and chance
    int ytzB1=0, ytzB2=0, ytzB3=0, ytzB4=0; //Yahtzee bonus slots, initialized to zero
    bool full3k=false, full4k=false, fullFH=false, fullSms=false, fullLgS=false, fullYtz=false, fullChc=false; //Same as LS scores but with slot indicators, initialized to false
    bool fullYB1=false, fullYB2=false, fullYB3=false, fullYB4=false; //Flags for Yahtzee bonus slots
    int ytzBtot=0, totLS=0, grTot=0; //Yahtzee bonus total, total of lower section, grand total, initialized to zero
     
    int gmeCt = 1; //Game number, initialized to 1
    int die1 = 1, die2 = 1, die3 = 1, die4 = 1, die5 = 1; //Five dice, initialized to 1
    const int D_1 = 1, D_2 = 2, D_3 = 3, D_4 = 4, D_5 = 5; //Dice number indicators
    char turn; //Player turn response indicator, 'R' to roll again, 'H' to hold dice for next roll, and 'E' to end turn
    char dice='d', value='v'; //Arbitrary flags to identify maximum value when sending integer input to be validated
    char holdDie, retrn, holdAgn, box; //Character input for die number to hold, yes/no to return die from hand, hold more dice, box to fill
    int holdInt; //Integer version of holdDie
    bool rOne = true, rTwo = true, rThree = true, rFour = true, rFive = true; //Dice roll indicators, initialized to true
    int roll = 1; //Roll user is on, initialized to 1
    int nRolls = 3; //Maximum number of rolls per turn
  
    char ready; //Gameplay flag
    //char again; //Roll again flag
    bool all = false; //Flag indicating that all spaces have been filled --> Game over (Note: flag does NOT include Yahtzee Bonus spaces because these are optional as per the rules of the game)

    //getIntro; //Get game introduction

    cout<<"Ready to play? (Y/N) "; //Prompt beginning of game
    cin>>ready; //Get input
    yesNo(ready); //Validate input 
    

    
    //GAMEPLAY HERE --> (One loop = One entire game)****************************
    while (ready=='y' || ready=='Y'){
        
        getCard(num1US,num2US,num3US,num4US,num5US,num6US,tot1t6,bonUS,totUS,num3k,num4k,numFH,numSmS,numLgS,numYtz,numChc,ytzB1,ytzB2,ytzB3,ytzB4,ytzBtot,totLS,grTot); 
        
        //ROLL FOR TURN --> (Each iteration = one "turn")
        while (!all){ //While all scorecard spaces NOT filled
            
            
            //Roll dice
            //Roll loop
            for (roll=1; roll<=3; roll++){
                //Roll dice 
                if (rOne == true){
                    die1 = rand()%6+1;
                    //d1 = to_string(refDie1);
                }
                if (rTwo == true){
                    die2 = rand()%6+1;
                    //d2 = to_string(refDie2);
                }
                if (rThree == true){
                    die3 = rand()%6+1;
                    //d3 = to_string(refDie3);
                }
                if (rFour == true){
                    die4 = rand()%6+1;
                    //d4 = to_string(refDie4);
                }
                if (rFive == true){
                    die5 = rand()%6+1;
                    //d5 = to_string(refDie5);
                }
                
                //Display dice roll
                cout<<endl<<right<<setw(28)<<"Roll #"<<roll<<":"<<endl;
                cout<<right<<setw(7)<<"Die # "<<setw(5)<<"#"<<D_1<<setw(6)<<"#"<<D_2<<setw(6)<<"#"<<D_3<<setw(6)<<"#"<<D_4<<setw(6)<<"#"<<D_5<<endl;
                cout<<right<<setw(13)<<die1<<"  "<<setw(5)<<die2<<"  "<<setw(5)<<die3<<"  "<<setw(5)<<die4<<"  "<<setw(5)<<die5<<endl;
                
                //Indicate if Yahtzee
                if (die1==die2 && die2==die3 && die3==die4 && die4==die5){
                    if (numYtz==0){
                        cout<<endl<<"Yahtzee!"<<endl; 
                    }
                    else if (numYtz==50) {
                        cout<<endl<<"Yahtzee Bonus!"<<endl;
                    }  
                }
            
                //Player responds by either rolling again, holding dice for next roll, or ending turn
                if (roll<3){
                    cout<<endl<<"Enter 'R' to roll again, 'H' to hold dice for the next roll or 'E' to end this turn: ";
                    cin>>turn; //Get input
                    turnVal(turn); //Validate input
                    
                    //Turn choices/responses
                    if (turn=='e' || turn=='E'){ //Ending turn
                        roll=10; //Set roll count to 10 to break for loop
                    }
                    else if (turn=='h' || turn=='H'){ //Hold dice for next turn
                        
                        do {
                        //Prompt which dice to hold this turn
                        cout<<endl<<"Enter the number of a die to hold it for the next roll: ";
                        cin>>holdDie; //Get input
                        holdInt=getNum(holdDie,dice); //Validate input
                        
                        //Flag dice as held according to input
                        if (holdInt==1) {
                            
                            if(rOne){ //If die not held yet
                                //Switch to holding die
                                rOne=false;
                                cout<<"Die #1 will not be rolled this turn."<<endl;
                            }
                            else if (!rOne){ //If already held
                                cout<<"Die #1 is already being held this turn. Would you like to return Die #1? (Y/N): ";
                                cin>>retrn; //Get input
                                yesNo(retrn); //Validate input
                                if (retrn=='y' || retrn=='Y'){
                                    rOne=true;
                                    cout<<"Die #1 will be rolled this turn."<<endl;
                                }
                            }
                        }
                        else if (holdInt==2) {
                            
                            if(rTwo){ //If die not held yet
                                //Switch to holding die
                                rTwo=false;
                                cout<<"Die #2 will not be rolled this turn."<<endl;
                            }
                            else if (!rTwo){ //If already held
                                cout<<"Die #2 is already being held this turn. Would you like to return Die #2? (Y/N): ";
                                cin>>retrn; //Get input
                                yesNo(retrn); //Validate input
                                if (retrn=='y' || retrn=='Y'){
                                    rTwo=true;
                                    cout<<"Die #2 will be rolled this turn."<<endl;
                                }
                            }
                        }
                        else if (holdInt==3) {
                            
                            if (rThree){ //If die not held yet
                                //Switch to holding die
                                rThree=false;
                                cout<<"Die #3 will not be rolled this turn."<<endl;
                            }
                            else if (!rThree){ //If already held
                                cout<<"Die #3 is already being held this turn. Would you like to return Die #3? (Y/N): ";
                                cin>>retrn; //Get input
                                yesNo(retrn); //Validate input
                                if (retrn=='y' || retrn=='Y'){
                                    rThree=true;
                                    cout<<"Die #3 will be rolled this turn."<<endl;
                                }
                            }
                        }
                        else if (holdInt==4) {
                            
                            if (rFour){ //If die not held yet
                                //Switch to holding die
                                rFour=false;
                                cout<<"Die #4 will not be rolled this turn."<<endl;
                            }
                            
                            else if (!rFour){ //If already held
                                cout<<"Die #4 is already being held this turn. Would you like to return Die #4? (Y/N): ";
                                cin>>retrn; //Get input
                                yesNo(retrn); //Validate input
                                if (retrn=='y' || retrn=='Y'){
                                    rFour=true;
                                    cout<<"Die #4 will be rolled this turn."<<endl;
                                }
                            }
                        }
                        else if (holdInt==5) {
                            
                            if (rFive){ //If die not held yet
                                //Switch to holding die
                                rFive=false;
                                cout<<"Die #5 will not be rolled this turn."<<endl;
                            }
                            else if (!rFive){ //If already held
                                cout<<"Die #5 is already being held this turn. Would you like to return Die #5? (Y/N): ";
                                cin>>retrn; //Get input
                                yesNo(retrn); //Validate input
                                if (retrn=='y' || retrn=='Y'){
                                    rFive=true;
                                    cout<<"Die #5 will be rolled this turn."<<endl;
                                }
                            }
                        }
                        else {
                            //Not supposed to happen
                            cout<<"ERROR: Did not successfully run the if/else statements to hold dice --> DEBUG"<<endl;
                        }
                        
                        //Prompt choose more dice to hold
                        cout<<endl<<"Press 'Y' to hold more dice, or 'N' to roll: ";
                        cin>>holdAgn; //Get input
                        yesNo(holdAgn);
                        
                        }while (holdAgn=='y' || holdAgn=='Y');
                    }
                    
                }
            
                
            }
            
        //Output final roll
        cout<<endl<<"Final Roll: "<<die1<<", "<<die2<<", "<<die3<<", "<<die4<<", "<<die5<<endl;    
        //Determine score placement
        cout<<endl<<"Please enter which box you would like to place your score: ";
        cin>>box;
    
        }
        
        
    }
    
    return 0;
}




//YES/NO INPUT CHECKER**********************************************************
void yesNo(char &input){
    //Loop while input is not yes/no format
    while (input!='y' && input!='Y' && input!='n' && input!='N'){
        cout<<"ERROR: Please enter either 'Y' or 'N': ";
        cin>>input;
    }
    return;
}
  
//TURN RESPONSE INPUT CHECKER***************************************************
void turnVal(char &tInput){
    //Loop while input is not in {R,H,E} format
    while (tInput!='r' && tInput!='R' && tInput!='h' && tInput!='H' && tInput!='e' && tInput!='E'){
        cout<<"ERROR: Please enter either 'R', 'H', or 'E': ";
        cin>>tInput;
    }
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
    
}




//NOTES
/* cout<<"\033[2J\033[1;1H"; <-- CLEAR SCREEN*/