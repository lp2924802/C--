/* 
 * File:   main.cpp
 * Version: V1.35
 * Author: Lauren Postlethwaite
 * Created on February 2, 2022, 4:43 PM
 * Purpose: Project 1: Yahtzee Game. Dice bracketed and die holding mechanism
 *              now removed into a function to clean up the program. Goal of
 *              this version is to minimize user inputs necessary to roll and
 *              hold dice each turn. 
 */

#include <cstdlib> //Random Number Library
#include <ctime> //Time Library
#include <iostream> //Input/Output Library
#include <iomanip> //Formatting Library
#include <string> //String Variable Type
#include <windows.h>
using namespace std;

//Function Prototypes
void getIntro(); //Game Introduction --> NEEDS TO BE WRITTEN
void yesNo(char&); //Yes/no input validation --> DONE
void turnVal(char&); //Turn response validation
int getNum(char, char); //Integer input validation
void getCard(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int); //Print/display scorecard
string * getLb(int,bool); //Decide what type of die label to return
string * brLb(int); //Get bracketed die string --> DONE
string * numLb(int); //Get only number die string
void dieStat(bool&); //Hold or return die and change roll status --> DONE


//Begin Here
int main(int argc, char** argv) {
    
    //RANDOM NUMBER SEED********************************************************
     srand(static_cast<unsigned int>(time(0)));
    
    //UPPER SECTION SCORECARD VARIABLES*****************************************
    int num1US=0, num2US=0, num3US=0, num4US=0, num5US=0, num6US=0; //Scores for 1-6's, initialized to zero
    int tot1t6=0, bonUS=0, totUS=0; //Total for 1-6's, bonus points, total for upper section, initialized to zero
    bool full1US=false, full2US=false, full3US=false, full4US=false, full5US=false, full6US=false;//If 1-6 spots taken, initialized to false/open
    //**************************************************************************
    
    //LOWER SECTION SCORECARD VARIABLES*****************************************
    int num3k=0, num4k=0, numFH=0, numSmS=0, numLgS=0, numYtz=0, numChc=0; //Scores for 3 kind, 4 kind, full house, small str., large str, Yahtzee, and chance
    int ytzB1=0, ytzB2=0, ytzB3=0, ytzB4=0; //Yahtzee bonus slots, initialized to zero
    bool full3k=false, full4k=false, fullFH=false, fullSms=false, fullLgS=false, fullYtz=false, fullChc=false; //Same as LS scores but with slot indicators, initialized to false
    bool fullYB1=false, fullYB2=false, fullYB3=false, fullYB4=false; //Flags for Yahtzee bonus slots
    int ytzBtot=0, totLS=0, grTot=0; //Yahtzee bonus total, total of lower section, grand total, initialized to zero
    //**************************************************************************
    
    //DICE-RELATED VARIABLES AND CONSTANTS**************************************
    int die1 = 1, die2 = 1, die3 = 1, die4 = 1, die5 = 1; //Five dice, initialized to 1
    const int D_1 = 1, D_2 = 2, D_3 = 3, D_4 = 4, D_5 = 5; //Dice number indicators
    string * strD1, * strD2, * strD3, * strD4, * strD5; //String outputs for dice
    bool rOne = true, rTwo = true, rThree = true, rFour = true, rFive = true; //Dice roll indicators, initialized to true
    //**************************************************************************
    
    //PLAYER-DECISION VARIABLES AND CONSTANTS***********************************
    char turn; //Player turn response indicator, 'R' to roll again, 'H' to hold dice for next roll, and 'E' to end turn
    char dice='d', value='v'; //Arbitrary flags to identify maximum value when sending integer input to be validated
    char holdDie, retrn, holdAgn, box; //Character input for die number to hold, yes/no to return die from hand, hold more dice, box to fill
    int holdInt, i=0; //Integer version of holdDie
    int roll = 1; //Roll user is on, initialized to 1
    int nRolls = 3; //Maximum number of rolls per turn
    char ready; //Gameplay flag
    bool all = false; //Flag indicating that all spaces have been filled --> Game over (Note: flag does NOT include Yahtzee Bonus spaces because these are optional as per the rules of the game)
    //**************************************************************************
    
    //getIntro; //Get game introduction

    cout<<"Ready to play? (Y/N) "; //Prompt beginning of game
    cin>>ready; //Get input
    yesNo(ready); //Validate input 

    //GAMEPLAY HERE --> (One loop = One entire game)****************************
    while (ready=='y' || ready=='Y'){
        
        getCard(num1US,num2US,num3US,num4US,num5US,num6US,tot1t6,bonUS,totUS,num3k,num4k,numFH,numSmS,numLgS,numYtz,numChc,ytzB1,ytzB2,ytzB3,ytzB4,ytzBtot,totLS,grTot); 
        
        //ROLL FOR TURN --> (Each iteration = one entire "turn")
        while (!all){ //While all scorecard spaces NOT filled
            //Roll dice
            //Roll loop
            for (roll=1; roll<=nRolls; roll++){
                //Roll dice 
                if (rOne == true){
                    die1 = rand()%6+1;
                    strD1 = getLb(die1,rOne);
                }
                if (rTwo == true){
                    die2 = rand()%6+1;
                    strD2 = getLb(die2,rTwo);
                }
                if (rThree == true){
                    die3 = rand()%6+1;
                    strD3 = getLb(die3,rThree);
                }
                if (rFour == true){
                    die4 = rand()%6+1;
                    strD4 = getLb(die4,rFour);
                }
                if (rFive == true){
                    die5 = rand()%6+1;
                    strD5 = getLb(die5,rFive);
                }

                //Display dice roll
                cout<<endl<<right<<setw(28)<<"Roll #"<<roll<<":"<<endl;
                cout<<right<<setw(7)<<"Die # "<<setw(5)<<"#"<<D_1<<setw(6)<<"#"<<D_2<<setw(6)<<"#"<<D_3<<setw(6)<<"#"<<D_4<<setw(6)<<"#"<<D_5<<endl;
                cout<<right<<setw(13)<<* strD1<<"  "<<setw(5)<<* strD2<<"  "<<setw(5)<<* strD3<<"  "<<setw(5)<<* strD4<<"  "<<setw(5)<<* strD5<<endl;
                
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
                if (roll<nRolls){
                    
                    if (rOne && rTwo && rThree && rFour && rFive) { //If all dice can still be rolled then there's none to return, so there's no need to mention returning dice
                        cout<<endl<<"Enter the number(s) of any dice to hold for the next roll, 'R' to roll again, or 'E' to end your turn: ";
                    }
                    else { //One or more dice held --> mention returning dice
                        cout<<endl<<"Enter the number(s) of any dice to hold or return for the next roll, 'R' to roll again, or 'E' to end your turn: ";
                    }
                    
                    cin>>turn; //Get input
                    turnVal(turn); //Validate input
                    
                    //If player chooses to keep/return dice
                    while (turn=='1' || turn=='2' || turn=='3' || turn=='4' || turn=='5'){
                            
                        holdInt = getNum(turn,dice); //Validate and convert character input for die holding
                        
                        switch (holdInt){
                            case 1: {
                                dieStat(rOne); //Switch roll status for Die #1
                                strD1 = getLb(die1,rOne); //Get new string label for Die #1
                                break;
                            }
                            case 2: {
                                dieStat(rTwo); //Switch roll status for Die #2
                                strD2 = getLb(die2,rTwo); //Get new string label for Die #2
                                break;
                            }
                            case 3: {
                                dieStat(rThree); //Switch roll status for Die #3
                                strD3 = getLb(die3,rThree); //Get new string label for Die #3
                                break;
                            }
                            case 4: {
                                dieStat(rFour); //Switch roll status for Die #4
                                strD4 = getLb(die4,rFour); //Get new string label for Die #4
                                break;
                            }
                            case 5: {
                                dieStat(rFive); //Switch roll status for Die #5
                                strD5 = getLb(die5,rFive); //Get new string label for Die #5
                                break;
                            }
                            default: {
                                cout<<"Error in holdInt Switch Case block"<<endl;
                            }
                        }
                        
                        //Display new dice lineup
                        cout<<right<<setw(7)<<"Die # "<<setw(5)<<"#"<<D_1<<setw(6)<<"#"<<D_2<<setw(6)<<"#"<<D_3<<setw(6)<<"#"<<D_4<<setw(6)<<"#"<<D_5<<endl;
                        cout<<right<<setw(13)<<* strD1<<"  "<<setw(5)<<* strD2<<"  "<<setw(5)<<* strD3<<"  "<<setw(5)<<* strD4<<"  "<<setw(5)<<* strD5<<endl;
                        
                        cin>>turn; //Get input
                        turnVal(turn); //Validate input
                
                    }
                    //Other turn choices/responses
                    if (turn=='e' || turn=='E'){ //Ending turn
                        roll=10; //Set roll count to 10 to break for loop
                    }
                    else if (turn=='r' || turn=='R'){
                        cout<<"Rolling dice...";
                    }

                }
                    
            }
            
            //Output final roll
            cout<<endl<<"Final Roll: "<<die1<<", "<<die2<<", "<<die3<<", "<<die4<<", "<<die5<<endl;    
            //Determine score placement
            cout<<endl<<"Please enter which box you would like to place your score: ";
            cin>>box;
            
            //Reset dice rolls
            rOne=true;
            rTwo=true;
            rThree=true;
            rFour=true;
            rFive=true; 
                
        }
            
    }
    
    return 0;
}




/*******************************************************************************
 *   Name:   dieStat(bool&) --> Hold or Return Die                             *                                                      *
 *   Description: This function is called when the player decides to either:   *
 *                  1. "Hold" a die to prevent it from rolling next turn,      *
 *                          OR                                                 *
 *                  2. Return a die that is currently being held so that it``` *
 *                      will roll next turn.                                   *
 *                The function accomplishes this by reading the roll status    *
 *                of the die, then either "holding" or returning the die       *
 *                (aka: switch the Boolean roll status of the die from true    *
 *                 to false or vice versa) accordingly.                        *
 ******************************************************************************/
void dieStat(bool &rStat){
    //If not held / still rollable
    if (rStat){
        rStat=false; //Mark die to NOT roll next turn
    }
    else if (!rStat){
        rStat=true; //Mark die to roll next turn
    }
    else{
        cout<<"Error in holdDie function."<<endl;
    }
}


//GET DIE LABELS
string *getLb(int die, bool roll){
    //Moment of truth here
    static string * name;
    name = new string;
    
    if (roll) //If roll is true / if die will be rolled
        name = numLb(die); //Get number die output
    else if (!roll){ //If roll is false / if die will NOT be rolled
        name = brLb(die);
    }
    return name;
}

//GET ONLY NUMBER DIE OUTPUT****************************************************
string * numLb(int die){
    //This would just be a number
    static string * numb;
    numb = new string;
    *numb = to_string(die);
    return numb;
}
/*******************************************************************************
 *   Name:   brLb(int) --> Get Bracketed Die Output                            *                                                      *
 *   Description: This function is called to return a string of the input      *
 *                integer surrounded by brackets. This is done to indicate     *
 *                to the player when a die is being held and will not be       *
 *                rolled during the next roll.                                 *
 ******************************************************************************/
string * brLb(int die){
    //Return bracketed version of die value
    static string * brk;
    brk = new string;
    
    if (die==1){
        *brk = "[1]";
    }
    else if (die==2){
        *brk = "[2]";
    }
    else if (die==3){
        *brk = "[3]";
    }
    else if (die==4){
        *brk = "[4]";
    }
    else if (die==5){
        *brk = "[5]";
    }
    else if (die==6){
        *brk = "[6]";
    }
    else {
        cout<<"***Error in getBr function***"<<endl;
    }
    
    return brk;
}


/*******************************************************************************
 *   Name:   yesNo(char) --> Yes/No Input Checker                              *                                               *
 *   Description: This function performs input validation on any user input    *
 *                of the "yes"/"no" format. Function loops and re-prompts      *
 *                user for input until the input is equal to either 'y', 'Y'   *
 *                'n', or 'N'. The function then returns the validated         *
 *                user input.                                                  *
 ******************************************************************************/
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
    while (tInput!='r' && tInput!='R' && tInput!='h' && tInput!='H' && tInput!='e' && tInput!='E'
            && tInput!='1' && tInput!='2' && tInput!='3' && tInput!='4' && tInput!='5'){
        cout<<"ERROR: Please enter either the number of a die as a digit (1 to 5), 'R', or 'E': ";
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