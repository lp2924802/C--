/**************************************************************************** 
 * File:   main.cpp                                                         *
 * Version: V2.3.1                                                          *
 * Author: Lauren Postlethwaite                                             *
 * Created on February 8, 2022, 10:58 PM                                    *     
 * Purpose: Project 2: Yahtzee Game. Continued modularization and debugging *   
 *                     of initial program to accommodate newly added        *
 *                     arrays.                                              *
 ***************************************************************************/


//Libraries
#include <cstdlib> //Random Number Library
#include <ctime> //Time Library
#include <iostream> //Input/Output Library
#include <iomanip> //Formatting Library
#include <string> //String Variable Type
#include <cmath> //Mathematics Library
#include <fstream> //File Open/Close Library
#include <algorithm> //Functions Library
using namespace std;


//Function Prototypes
/****************************************************************************
 *  Function Order/Hierarchy:                                               *
 *  1.0 Main Code                                                           * 
 *      1.1 Game Introduction                                               *
 *      1.2 Yes/No Input Validation                                         *
 *      1.3 Get Scorecard                                                   *
 *          1.3.1 Thin "Upper" Section Border                               *
 *          1.3.2 Thin "Lower" Section Border                               *
 *          1.3.3 Thick "Upper" Section Border                              *
 *          1.3.4 Thick "Lower" Section Border                              *
 *      1.4 Get String Label for Die                                        *
 *          1.4.1 Get Only Number Die Output                                *
 *          1.4.2 Get Bracketed Die Output                                  *
 *      1.5 Turn Response Validation                                        *
 *      1.6 Integer Input Validation                                        *
 *      1.7 Hold or Return Die                                              *
 *      1.8 Display Dice Upper Table                                                    *
 *      1.9 Score Upper                                                     *
 ***************************************************************************/
char getIntro(fstream&); //1.1 Game Introduction
void yesNo(char&); //1.2 Yes/No Input Validation
void getCard(fstream&); //1.3 Get Scorecard
void thinUS(fstream&); //1.3.1 Thin "Upper" Section Border
void thinLS(fstream&); //1.3.2 Thin "Lower" Section Border
void thckUS(fstream&, char); //1.3.3 Thick "Upper" Section Border
void thckLS(fstream&, char); //1.3.4 Thick "Lower" Section Border
string * getLb(int,bool); //1.4 Get String Label for Die
string * numLb(int); //1.41 Get Only Number Die Output
string * brLb(int); //1.42 Get Bracketed Die Output
void turnVal(char&); //1.5 Turn Response Validation
int getNum(char, char); //1.6 Integer Input Validation
void dieStat(bool&); //1.7 Hold or Return Die
void dspDice(const int[],int); //1.8 Display Dice
int scoreUS(char,int,int,int,int,int); //1.8 Score Upper Section



//1.0 MAIN CODE
/****************************************************************************
 *  Name: main(int,char) --> Main Function                                  *
 *  Description: Starting and ending point for the program execution.       *
 ***************************************************************************/
int main(int argc, char** argv) {
    
    //RANDOM NUMBER SEED*****************************************************
     srand(static_cast<unsigned int>(time(0)));
    
    //UPPER SECTION (US) SCORECARD VARIABLES*********************************
    const int VALS = 6; //Number of potential dice values
    int numUS[VALS]; //Score in each box of US
    bool fullUS[VALS]; //Flag for if box is taken
     int num1US=0, num2US=0, num3US=0, num4US=0, num5US=0, num6US=0; 
    //Scores for 1-6's, initialized to zero
    int tot1t6=0, bonUS=0, totUS=0; 
    //Total for 1-6's, bonus points, total for upper section, init to zero
    bool full1US=false, full2US=false, full3US=false, full4US=false, 
            full5US=false, full6US=false;//If 1-6 spots taken, init. to false
    //***********************************************************************
    
    //LOWER SECTION SCORECARD VARIABLES**************************************
    //Scores for 3 kind, 4 kind, full house, small str., large str, Yahtzee, chance
    int num3k=0, num4k=0, numFH=0, numSmS=0, numLgS=0, numYtz=0, numChc=0; 
    //Yahtzee bonus slots, initialized to zero
    int ytzB1=0, ytzB2=0, ytzB3=0, ytzB4=0; 
    //Same as LS scores but with slot indicators, initialized to false
    bool full3k=false, full4k=false, fullFH=false, fullSms=false, fullLgS=false, 
            fullYtz=false, fullChc=false; 
    //Flags for Yahtzee bonus slots
    bool fullYB1=false, fullYB2=false, fullYB3=false, fullYB4=false; 
    //Yahtzee bonus total, total of lower section, grand total, initialized to zero
    int ytzBtot=0, totLS=0, grTot=0; 
    fstream scorecd; //File stream for scorecard
    string line; //Line to read scorecard
    //***********************************************************************
    
    //DICE-RELATED VARIABLES AND CONSTANTS***********************************
    const int NUM = 5; //Number of dice in game
    const int D_VAL[NUM] = {1,2,3,4,5};
    int dice[NUM] = {1,1,1,1,1}; //Int array of all five dice
    string * strDice[NUM];
    bool roll[NUM] = {true,true,true,true,true};

    
    //PLAYER-DECISION VARIABLES AND CONSTANTS********************************
    //Player turn response indicator, 'R' to roll again, 
        //'H' to hold dice for next roll, and 'E' to end turn
    char turn; 
    //Arbitrary flags to ID max value when sending int input to be validated
    char diceX='d', valueX='v';
    //Character input for die number to hold, yes/no to return die from hand, 
        //hold more dice, box to fill
    char holdDie, retrn, holdAgn, box; 
    int holdInt, i=0; //Integer version of holdDie
    int rollCt = 1; //Roll user is on, initialized to 1
    int nRolls = 3; //Maximum number of rolls per turn
    char ready; //Gameplay flag
    //Flag indicating that all spaces have been filled --> Game over 
        //(Note: flag does NOT include Yahtzee Bonus spaces because these 
        //are optional as per the rules of the game)
    bool all = false; 
    //***********************************************************************
    
    //INITIALIZE SCORECARD FILE**********************************************
    
    scorecd.open("ytzGame.txt", ios::out); //Create/open scorecard file
    
    if(!scorecd){
        cout<<"File did not open!"; //Notify of file error
    }
    
    getCard(scorecd); 

    scorecd.close(); //Re-close card for now to fully initialize it
    //***********************************************************************
    
    scorecd.open("ytzGame.txt", ios::in); //Reopen scorecard to read
    
    ready = getIntro(scorecd); //Get game introduction

    
    //GAMEPLAY HERE --> (One loop = One entire game)*************************
    while (ready=='y' || ready=='Y'){
        

        cout<<"\033[2J\033[1;1H"; //Clear screen
        scorecd.clear(); //Clear the EOF flag
        scorecd.seekg(0, ios::beg); //Go back to the beginning of 
                                        //scorecard file
        getline(scorecd,line,'@'); //Get the scorecard info
        cout<<line; //Display the info

                
        //ROLL FOR TURN --> (Each iteration = one entire "turn")
        while (!all){ //While all scorecard spaces NOT filled
            //Roll dice
            //Roll loop
            for (rollCt=1; rollCt<=nRolls; rollCt++) {
                for (int i=0; i<NUM; i++){
                    //Roll dice
                    if (roll[i]){
                        dice[i] = rand()%6+1;
                    }
                    strDice[i] = getLb(dice[i],roll[i]);
                }
                 
                cout<<"\033[2J\033[1;1H"; //Clear screen
                scorecd.clear(); //Clear the EOF flag
                scorecd.seekg(0, ios::beg); //Go back to the beginning of 
                                                //scorecard file
                getline(scorecd,line,'@'); //Get the scorecard info
                cout<<line<<endl; //Display the info

                //Display top part of dice roll table
                dspDice(D_VAL,rollCt);

                //Roll outcomes
                cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"<<right<<setw(6)
                        <<* strDice[0]<<setw(6)<<"\u250a"<<setw(6)<<* 
                        strDice[1]<<setw(6)<<"\u250a"<<setw(6)<<* strDice[2]
                        <<setw(6)<<"\u250a"<<setw(6)<<* strDice[3]<<setw(6)
                        <<"\u250a"<<setw(6)<<* strDice[4]<<setw(6)<<"\u2551"
                        <<endl;
                
                //Bottom border
                //Dice # space
                cout<<"\t\u255a";
                for (int q=0; q<13; q++){
                    cout<<"\u2550";
                }
                cout<<"\u2569";
                //First four dice spaces
                for (int w=0; w<4; w++){
                    for (int q=0; q<9; q++){
                        cout<<"\u2550";
                    }
                cout<<"\u2567";
                }
                //Last dice space
                for (int q=0; q<9; q++){
                    cout<<"\u2550";
                }
                cout<<"\u255d\n";
                  
                       
            //Indicate if Yahtzee
            /*if (die1==die2 && die2==die3 && die3==die4 && die4==die5){
                if (numYtz==0){
                    cout<<"\n\t"<<left<<setw(63)<<"                               Yahtzee!\n"; 
                }
                else if (numYtz==50) {
                    cout<<"\n\t"<<left<<setw(63)<<"                            Yahtzee Bonus!\n";
                }  
            } */
            
                //Player responds by either rolling again, holding dice for next roll, or ending turn
                if (rollCt<nRolls){
                    
                    if (roll[0] == roll[1] && roll[1] == roll[2] && roll[2] == roll[3] 
                            && roll[3] == roll[4] && roll[4] == true) { //If all dice can still be rolled then there's none to return, so there's no need to mention returning dice
                        cout<<"\n\t   Enter the number(s) of any dice to hold for the next roll, "
                                "\n\t   'R' to roll again, or 'E' to end your turn: ";
                    }
                    else { //One or more dice held --> mention returning dice
                        cout<<"\n\t   Enter the number(s) of any dice to hold or return for the\n"
                                "\t   next roll, 'R' to roll again, or 'E' to end your turn: ";
                    }
                    
                    cin>>turn; //Get input
                    turnVal(turn); //Validate input
                    
                    cout<<"\033[2J\033[1;1H"; //Clear screen
                    scorecd.clear(); //Clear the EOF flag
                    scorecd.seekg(0, ios::beg); //Go back to the beginning of scorecard file
                    getline(scorecd,line,'@'); //Get the scorecard info
                    cout<<line<<endl; //Display the info
                    

                    
                    //If player chooses to keep/return dice
                    while (turn=='1' || turn=='2' || turn=='3' || turn=='4' || turn=='5'){
                            
                        holdInt = getNum(turn,diceX); //Validate and convert character input for die holding
                        
                        dieStat(roll[(holdInt-1)]); //Switch roll status for Die
                        strDice[(holdInt-1)] = getLb(dice[(holdInt-1)],roll[holdInt-1]);
                        
                        
                        //Keep this screen clear, it prevents repeat rolls from 
                            //showing if multiple dice are held
                        cout<<"\033[2J\033[1;1H"; //Clear screen
                        scorecd.clear(); //Clear the EOF flag
                        //Go back to the beginning of scorecard file
                        scorecd.seekg(0, ios::beg); 
                        getline(scorecd,line,'@'); //Get the scorecard info
                        cout<<line<<endl; //Display the info 
                        
                        //Display top part of dice roll table
                        dspDice(D_VAL,rollCt);
                
                        //Roll outcomes
                        cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"
                                <<right<<setw(6)<<* strDice[0]<<setw(6)
                                <<"\u250a"<<setw(6)<<* strDice[1]<<setw(6)
                                <<"\u250a"<<setw(6)<<* strDice[2]<<setw(6)
                                <<"\u250a"<<setw(6)<<* strDice[3]<<setw(6)
                                <<"\u250a"<<setw(6)<<* strDice[4]<<setw(6)
                                <<"\u2551"<<endl;
                
                        //Bottom border
                        //Dice # space
                        cout<<"\t\u255a";
                        for (int q=0; q<13; q++){
                            cout<<"\u2550";
                        }
                        cout<<"\u2569";
                        //First four dice spaces
                        for (int w=0; w<4; w++){
                            for (int q=0; q<9; q++){
                                cout<<"\u2550";
                            }
                        cout<<"\u2567";
                        }
                        //Last dice space
                        for (int q=0; q<9; q++){
                            cout<<"\u2550";
                        }
                        cout<<"\u255d\n";
                
                        cout<<"\n\t"<<left<<setw(63)<<"   Enter the number(s) "
                                "of any dice to hold or return for the\n"
                                "\t   next roll, 'R' to roll again, or 'E' to "
                                "end your turn: ";
                        cin>>turn; //Get input
                        turnVal(turn); //Validate input
                       
                    }
                    
                    cout<<"\033[2J\033[1;1H"; //Clear screen
                    scorecd.clear(); //Clear the EOF flag
                    scorecd.seekg(0, ios::beg); //Go back to the beginning 
                                                    //of scorecard file
                    getline(scorecd,line,'@'); //Get the scorecard info
                    cout<<line<<endl; //Display the info
                    
                        
                   //Display top part of dice roll table
                    dspDice(D_VAL,rollCt);
                
                    //Roll outcomes
                    cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"<<right
                            <<setw(6)<<* strDice[0]<<setw(6)<<"\u250a"
                            <<setw(6)<<* strDice[1]<<setw(6)<<"\u250a"
                            <<setw(6)<<* strDice[2]<<setw(6)<<"\u250a"
                            <<setw(6)<<* strDice[3]<<setw(6)<<"\u250a"
                            <<setw(6)<<* strDice[4]<<setw(6)<<"\u2551"
                            <<endl;
                
                    //Bottom border
                    //Dice # space
                    cout<<"\t\u255a";
                    for (int q=0; q<13; q++){
                        cout<<"\u2550";
                    }
                    cout<<"\u2569";
                    //First four dice spaces
                    for (int w=0; w<4; w++){
                        for (int q=0; q<9; q++){
                            cout<<"\u2550";
                        }
                    cout<<"\u2567";
                    }
                    //Last dice space
                    for (int q=0; q<9; q++){
                        cout<<"\u2550";
                    }
                    cout<<"\u255d\n";;    
                    //Other turn choices/responses
                    if (turn=='e' || turn=='E'){ //Ending turn
                        rollCt=10; //Set roll count to 10 to break for loop
                    }

                }
            }       
            }
            
            cout<<"\033[2J\033[1;1H"; //Clear screen
            scorecd.clear(); //Clear the EOF flag
            scorecd.seekg(0, ios::beg); //Go back to the beginning of 
                                            //scorecard file
            getline(scorecd,line,'@'); //Get the scorecard info
            cout<<line<<endl; //Display the info
            
                        
            //Display top part of dice roll table
                dspDice(D_VAL,rollCt);
                
            //Roll outcomes
            cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"<<right<<setw(6)
                    <<* strDice[0]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[1]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[2]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[3]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[4]<<setw(6)<<"\u2551"<<endl;
                
            //Bottom border
            //Dice # space
            cout<<"\t\u255a";
            for (int q=0; q<13; q++){
                cout<<"\u2550";
            }
            cout<<"\u2569";
            //First four dice spaces
            for (int w=0; w<4; w++){
                for (int q=0; q<9; q++){
                    cout<<"\u2550";
                }
            cout<<"\u2567";
            }
            //Last dice space
            for (int q=0; q<9; q++){
                cout<<"\u2550";
            }
            cout<<"\u255d\n";     
            //Indicate if Yahtzee
                /*
                if (die1==die2 && die2==die3 && die3==die4 && die4==die5){
                    if (numYtz==0){
                        cout<<"\n\t"<<left<<setw(63)
                                <<"                               Yahtzee!\n"; 
                    }
                    else if (numYtz==50) {
                        cout<<"\n\t"<<left<<setw(63)
                                <<"                            Yahtzee Bonus!\n";
                    }  
                } */
            //Determine score placement
            cout<<"\n\t  Please enter which box you would like to place your score: ";
            cin>>box;
            
            //NOTE: Check loop needs to be added for score placement input 
            
            if (box=='x'){
                all=true;
            }

            //Reset dice rolls
            for (i=0; i<NUM; i++){
                roll[i]=true;
            }
 
        }
        
        cout<<"\t  Play again? (Y/N): ";
        cin>>ready; //Get input
        yesNo(ready); //Validate input
        
        if (ready=='n' || ready=='N'){
            scorecd.close(); //Close scorecard file
        }

    return 0;
}


//1.1 GAME INTRODUCTION
char getIntro(fstream &card){
    //Initialize local variables
    char input; //User input for if ready or not
    string headLne; //Line for header of introduction
    int i = 0; //Counter
    const int LINES = 8; //Number of lines to read from file
    
    for (i=0;i<LINES;i++){
        getline(card,headLne,'\n');
        cout<<headLne<<endl;
    }
    
     cout<<"\t\u2554";
                for (int q=0; q<63; q++){
                    cout<<"\u2550";
                }
                cout<<"\u2557\n";
    cout<<"\t\u2551"<<left<<setw(63)<<"                    "
            "Ready to play? (Y/N) "
            <<"\u2551\n"; //Prompt beginning of game
    cout<<"\t\u255a";
    for (int q=0; q<63; q++){
        cout<<"\u2550";
    }
    cout<<"\u255d\n\n\t   ";
    cin>>input; //Get input
    yesNo(input); //Validate input 
    
    return input;
}


//1.2 YES/NO INPUT VALIDATION
/****************************************************************************
 *   Name:   yesNo(char) --> Yes/No Input Checker                           *                                               *
 *   Description: This function performs input validation on any user input *
 *                of the "yes"/"no" format. Function loops and re-prompts   *
 *                user for input until the input is equal to either 'y',    *
 *                'Y', 'n', or 'N'. The function then returns the validated *
 *                user input.                                               *
 ***************************************************************************/
void yesNo(char &input){
    //Loop while input is not yes/no format
    while (input!='y' && input!='Y' && input!='n' && input!='N'){
        cout<<"\t ERROR: Please enter either 'Y' or 'N': ";
        cin>>input;
    }
    return;
}


//1.3 GET SCORECARD
/****************************************************************************  
 *  Name:   getCard(int...) --> Get Scorecard                               *     
 *  Description:  This function displays a blank Yahtzee Scorecard that     *
 *                the player will place their scores into throughout the    *
 *                game. In theory, this function should only be called      *
 *                once at the beginning of every game.                      *
 ***************************************************************************/
void getCard(fstream &card){
    
    //TOP BORDER OF YAHTZEE BANNER*******************************************   
    card<<"\t\u2554";
    for (int q=0; q<63; q++){
        card<<"\u2550";
    }
    card<<"\u2557\n";

    //YAHTZEE TITLE BANNER WITH DICE*****************************************   
    card<<"\t\u2551____            __   __         _       _                "
            "      \u2551\n";
    card<<"\t/\\' .\\    _____  \\ \\ / /  __    | |__   | |_   ____   ___  "
            "  __ \u2551\n";
    card<<"       /: \\___\\  / .  /\\  \\ V /  / _` | | '_ \\  | __| |_  / "
            " / _ \\  / _ \\ \n";
    card<<"       \\' / . / /____/..\\  | |  | (_| | | | | | | |_   / /  |  "
            "__/ |  __/\n";
    card<<"\t\\/___/  \\'  '\\  /  |_|   \\__,_| |_| |_|  \\__| /___|  \\___"
            "|  \\___|\n";   
    card<<"\t\u2551        \\'__'\\/                                        "
            "        \u2551\n"; 
       
    //BOTTOM BORDER OF YAHTZEE BANNER****************************************   
    card<<"\t\u255a";
              
    for (int q=0; q<63; q++){
        card<<"\u2550";
    }
    card<<"\u255d\n"; 

    //TOP BORDER OF "UPPER" SECTION******************************************
    thckUS(card,'t');
    
    //TOP BORDER OF "LOWER" SECTION******************************************
    thckLS(card,'t');

    card<<"\t\u2551"<<right<<setw(29)<<"\"UPPER\" SECTION       "
            <<"\u2551\u2551"<<right<<setw(32)<<"\"LOWER\" SECTION        "
            <<"\u2551\n"; 
    
    //LOWER BORDER OF "UPPER" SECTION TITLE BLOCK****************************
     card<<"\t\u2560";
    for (int q=0; q<16; q++){
        card<<"\u2550";
    }
    card<<"\u2566";
    for (int q=0; q<12; q++){
        card<<"\u2550";
    }
    card<<"\u2563\u2560";
    
    //LOWER BORDER OF "LOWER" SECTION TITLE BLOCK****************************
    for (int q=0; q<16; q++){
        card<<"\u2550";
    }
    card<<"\u2566";
    for (int q=0; q<15; q++){
        card<<"\u2550";
    }
    card<<"\u2563\n";
    
    //ACES - SUM OF ALL 1'S**************************************************
    //3 OF A KIND - SUM OF ALL DICE IF 3 DICE HAVE THE SAME VALUE************
    card<<"\t\u2551"<<left<<setw(16)<<"      Aces"<<"\u2551"<<right<<setw(18)
            <<"\u2551\u2551"<<left<<setw(16)<<"  3 of a kind"<<"\u2551"
            <<right<<setw(19)<<"\u2551\n";
    
    thinUS(card);
    thinLS(card);
    
    //TWOS - SUM OF ALL 2'S**************************************************
    //4 OF A KIND - SUM OF ALL DICE IF 4 DICE HAVE THE SAME VALUE************
    card<<"\t\u2551"<<left<<setw(16)<<"      Twos"<<"\u2551"<<right<<setw(18)
            <<"\u2551\u2551"<<left<<setw(16)<<"  4 of a kind"<<"\u2551"
            <<right<<setw(19)<<"\u2551\n";
    thinUS(card);
    thinLS(card);
    
    //THREES - SUM OF ALL 3'S************************************************
    //FULL HOUSE - 25 PTS IF 2 OF 1 VALUE OF DICE AND 3 OF ANOTHER VALUE*****
    card<<"\t\u2551"<<left<<setw(16)<<"     Threes"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"   Full House"
            <<"\u2551"<<right<<setw(19)<<"\u2551\n";
    thinUS(card);
    thinLS(card);

    //FOURS - SUM OF ALL 4'S*************************************************
    //SMALL STRAIGHT - 30 PTS IF SEQUENCE OF 4*******************************
    //(sequence of 4)--> statement from SM Straight**************************
    card<<"\t\u2551"<<left<<setw(16)<<"      Fours"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"  SM Straight"
            <<"\u2551"<<right<<setw(19)<<"\u2551\n";
    thinUS(card);
    card<<"\u2551"<<left<<setw(16)<<" (sequence of 4)"<<"\u2551"<<right
            <<setw(19)<<"\u2551\n";
    
    //FIVES - SUM OF ALL 5'S*************************************************
    //LARGE STRAIGHT - 40 PTS IF SEQUENCE OF 5*******************************
    card<<"\t\u2551"<<left<<setw(16)<<"      Fives"<<"\u2551"<<right
            <<setw(15)<<"\u2551";
    thinLS(card);
    thinUS(card);
    card<<"\u2551"<<left<<setw(16)<<"  LG Straight"<<"\u2551"<<right
            <<setw(19)<<"\u2551\n";
    
    //SIXES - SUM OF ALL 6'S*************************************************
    //(sequence of 5)--> statement from LG Straight**************************
    card<<"\t\u2551"<<left<<setw(16)<<"      Sixes"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<" (sequence of 5)"
            <<"\u2551"<<right<<setw(19)<<"\u2551\n";
    thckUS(card,'m');
    thinLS(card);
    
    //TOTAL SCORE - SUM OF SCORES FROM 1-6***********************************
    //YAHTZEE - 50 PTS IF ALL 5 DICE HAVE THE SAME VALUE*********************
    card<<"\t\u2551"<<left<<setw(16)<<"      TOTAL"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"     Yahtzee"
            <<"\u2551"<<right<<setw(19)<<"\u2551\n";
    
    card<<"\t\u2551"<<left<<setw(16)<<"      SCORE"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"  (5 of a kind)"
            <<"\u2551"<<right<<setw(19)<<"\u2551\n";
    thckUS(card,'m');    
    thinLS(card);
    
    //BONUS - 35 PTS IF TOTAL SCORE >= 63************************************
    //CHANCE - SUM OF ALL THE VALUES OF ALL DICE IN HAND*********************
    card<<"\t\u2551"<<left<<setw(16)<<" BONUS (+35pts)"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"     Chance"
            <<"\u2551"<<right
            <<setw(19)<<"\u2551\n";
    
    card<<"\t\u2551"<<left<<setw(16)<<"(If total \u226563) "<<"\u2551"<<right   
            <<setw(18)<<"\u2551\u255f";
    for (int q=0; q<16; q++){
        card<<"\u2508";
    }
    card<<"\u256b";
    for (int v=0; v<4; v++){
        for (int q=0; q<3; q++){
            card<<"\u2508";
        }
        if (v<3)
            card<<"\u252c";
    }
    card<<"\u2562"<<endl;
   
    
    //***********************************************************************
    //YAHTZEE BONUS - 100 PTS FOR EACH ADDITIONAL YAHTZEE********************
    thckUS(card,'m');
    card<<"\u2551"<<left<<setw(16)<<"     Yahtzee"<<"\u2551"<<right
            <<setw(6)<<"\u250a"<<right<<setw(6)<<"\u250a"<<setw(6)<<"\u250a"
            <<setw(7)<<"\u2551\n";
   
    //TOTAL OF "UPPER" SECTION - TOTAL SCORE + BONUS*************************
    card<<"\t\u2551"<<left<<setw(16)<<"    TOTAL OF"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"      Bonus";
    
    card<<"\u255f";
    
    //Bottom Yahtzee Bonus border
    for (int v=0; v<4; v++){
        for (int q=0; q<3; q++){
            card<<"\u2508";
        }
        if (v<3)
            card<<"\u2534";
    }
    card<<"\u2562\n";
    
    //"UPPER" SECTION display line and blank Yahtzee Bonus total space
    card<<"\t\u2551"<<left<<setw(16)<<"\"UPPER\" SECTION"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<right<<setw(19)<<"\u2551"<<right
            <<setw(19)<<"\u2551\n";
    
    thckUS(card,'b');
    thckLS(card,'m');

    //TOTAL OF "LOWER" SECTION - SUM OF REMAINING SECTIONS*******************
    card<<"\t\u2554";
    for (int q=0; q<28; q++){
        card<<"\u2550";
    }
    card<<"\u2557 \u2551"<<left<<setw(16)<<"    TOTAL OF"<<"\u2551"<<
            right<<setw(19)<<"\u2551\n";
 
    card<<"\t\u2551"<<right<<setw(28)<<"SCORECARD INPUT CODES    "
            <<"\u2551 \u2551"<<left<<setw(16)<<"\"LOWER\" SECTION"<<"\u2551"
            <<right<<setw(19)<<"\u2551\n";
    
    card<<"\t\u2551"<<left<<setw(11)<<" 1 = Aces "<<right<<setw(17)
            <<" a/b = 3/4 kind "<<"\u2551 ";
    thckLS(card,'m');
    
    //REPEAT OF "UPPER" SECTION TOTAL****************************************
    card<<"\t\u2551"<<left<<setw(11)<<" 2 = Twos"<<right<<setw(17)
            <<" c = Full House "<< "\u2551 \u2551"<<left<<setw(16)
            <<"    TOTAL OF"<<"\u2551"<<right<<setw(19)<<"\u2551\n";
    card<<"\t\u2551"<<left<<setw(11)<<" 3 = Threes"<<right<<setw(17)
            <<" d = SM straight "<<"\u2551 \u2551"<<left<<setw(16)
            <<"\"UPPER\" SECTION"<<"\u2551"<<right<<setw(19)<<"\u2551\n";
    
    card<<"\t\u2551"<<left<<setw(11)<<" 4 = Fours"<<right<<setw(17)
            <<" e = LG straight "<<"\u2551 ";
    thckLS(card,'m');
    
    //GRAND TOTAL - SUM OF "UPPER" AND "LOWER" SECTIONS**********************
    card<<"\t\u2551"<<left<<setw(11)<<" 5 = Fives"<<right<<setw(17)
            <<" f = Yahtzee "<<"\u2551 \u2551"<<left<<setw(16)<<
            "      GRAND"<<"\u2551"<<right<<setw(19)<<"\u2551\n";
    card<<"\t\u2551"<<left<<setw(11)<<" 6 = Sixes"<<right<<setw(17)
            <<" g = Chance "<<"\u2551 \u2551"<<left<<setw(16)<<
            "      TOTAL"<<"\u2551"<<right<<setw(19)<<"\u2551\n";
    
    //Bottom border of Scorecard Input Codes Section
    card<<"\t\u255a";
    for (int q=0; q<28; q++){
        card<<"\u2550";
    }
    card<<"\u255d ";
    //Bottom border of "Lower" Section
    thckLS(card,'b');
    
}


//1.3.1 THIN "UPPER" SECTION BORDER
/****************************************************************************
 *   Name:   thinUS(fstream &card) --> Thin "Upper" Section Border          *
 *   Description: This function is called to output a thin border/divider   *
 *                for the "Upper" Section of the Yahtzee Scorecard.         *
 ***************************************************************************/
void thinUS(fstream &card){
    
    card<<"\t\u255f";
    for (int q=0; q<16; q++){
        card<<"\u2508";
    }
    card<<"\u256b";
    for (int q=0; q<12; q++){
        card<<"\u2508";
    }
    card<<"\u2562";
    
}

//1.3.2 THIN "LOWER" SECTION BORDER
/****************************************************************************
 *   Name:   thinLS(fstream &card) --> Thin "Lower" Section Border          *
 *   Description: This function is called to output a thin border/divider   *
 *                for the "Lower" Section of the Yahtzee Scorecard.         *
 ***************************************************************************/
void thinLS(fstream &card){
    
    card<<"\u255f";
    for (int q=0; q<16; q++){
        card<<"\u2508";
    }
    card<<"\u256b"; 
    for (int q=0; q<15; q++){
        card<<"\u2508"; 
    }
    card<<"\u2562\n";
    
}

//1.3.3 THICK "UPPER" SECTION BORDER
/****************************************************************************
 *   Name:   thckUS(fstream &card, char type)                               *
 *                      --> Thick "Upper" Section Border                    *
 *   Description: This function is called to output a thick border/divider  *
 *                for the "Upper" Section of the Yahtzee Scorecard. There   *
 *                are three possible borders that can be called from this   *
 *                function, as indicated by their associated character:     *
 *                      1. t --> upper border                               *
 *                      2. m --> middle border                              *
 *                      3. b --> bottom border                              *
 ***************************************************************************/
void thckUS(fstream &card, char type) {
    
    if (type=='t'){
        card<<"\t\u2554";
        for (int q=0; q<29; q++){
            card<<"\u2550";
        }
        card<<"\u2557";
    }
    
    if (type=='m'){
        card<<"\t\u2560";
        for (int q=0; q<16; q++){
            card<<"\u2550";
        }
        card<<"\u256c";
        for (int q=0; q<12; q++){
            card<<"\u2550";
        }
        card<<"\u2563";
    }
    
    if (type=='b'){
        card<<"\t\u255a";
        for (int q=0; q<16; q++){
            card<<"\u2550";
        }
        card<<"\u2569";
        for (int q=0; q<12; q++){
            card<<"\u2550";
        }
        card<<"\u255d";
    }
}


//1.3.4 THICK "LOWER" SECTION BORDER
/****************************************************************************
 *   Name:   thckLS(fstream &card, char type)                               *
 *                      --> Thick "Lower" Section Border                    *
 *   Description: This function is called to output a thick border/divider  *
 *                for the "Lower" Section of the Yahtzee Scorecard. There   *
 *                are three possible borders that can be called from this   *
 *                function, as indicated by their associated character:     *
 *                      1. t --> upper border                               *
 *                      2. m --> middle border                              *
 *                      3. b --> bottom border                              *
 ***************************************************************************/
void thckLS (fstream &card, char type) {
    
    if (type=='t'){
        card<<"\u2554";
        for (int q=0; q<32; q++){
            card<<"\u2550";
        }
        card<<"\u2557\n";
    }
    
    if (type=='m'){
        card<<"\u2560";
        for (int q=0; q<16; q++){
            card<<"\u2550";
        }
        card<<"\u256c";
        for (int q=0; q<15; q++){
            card<<"\u2550";
        }
        card<<"\u2563\n";
    }
    
    if (type=='b'){
        card<<"\u255a";
        for (int q=0; q<16; q++){
            card<<"\u2550";
        }
        card<<"\u2569";
        for (int q=0; q<15; q++){
            card<<"\u2550";
        }
        card<<"\u255d\n";
    }    
}


//1.4 GET STRING LABEL FOR DIE
/****************************************************************************
 *   Name:   getLb(int, bool) --> Get String Label for Die                  *
 *   Description: This function is called to return a string label of the   *
 *                integer value of the die that the function receives. This *
 *                function calls two further functions:                     *
 *                      1. numLb(int) --> Get Only Number Die Output        *
 *                      2. brLb(int) --> Get Bracketed Die Output           *
 ***************************************************************************/
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


//1.4.1 GET ONLY NUMBER DIE OUTPUT
/****************************************************************************
 *   Name:   numLb(int) --> Get Only Number Die Output                      *
 *   Description: This function is called to return a string of the input   *
 *                integer. This is done to indicate to the player when a    * 
 *                die is not being held and will be rolled during the next  * 
 *                roll.                                                     *
 ***************************************************************************/
string * numLb(int die){
    //This would just be a number
    
    static string * numb;
    string hold; //Holder string to append space onto integer 
                 //for better formatting
    
    hold = to_string(die); //Convert integer to string
    hold = hold.append(" "); //Append a space onto the string 
                             //for better formatting
    
    numb = new string;
    *numb = hold;
    
    return numb;
}


//1.4.2 GET BRACKETED DIE OUTPUT
/****************************************************************************
 *   Name:   brLb(int) --> Get Bracketed Die Output                         *
 *   Description: This function is called to return a string of the input   *
 *                integer surrounded by brackets. This is done to indicate  *
 *                to the player when a die is being held and will not be    *
 *                rolled during the next roll.                              *
 ***************************************************************************/
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
        cout<<"\t ***Error in getBr function***"<<endl;
    }
    
    return brk;
}


//1.5 TURN RESPONSE VALIDATION
/****************************************************************************
 *   Name:  turnVal(char) --> Turn Response Validation                      *
 *   Description: This function performs input validation on user input     *
 *                prompted for player to choose to keep/return dice, roll   *
 *                again, or end their turn. Function loops and re-prompts   *
 *                user for input until the input is equal to either '1',    *
 *                '2', '3', '4', '5', 'r', 'R', 'e', or 'E'. The function   *
 *                then returns the validated user input                     *
 ***************************************************************************/
void turnVal(char &tInput){
    //Loop while input is not in {R,H,E} format
    while (tInput!='r' && tInput!='R' && tInput!='e' && tInput!='E'  
            && tInput!='1' && tInput!='2' && tInput!='3' && tInput!='4' 
            && tInput!='5'){
        cout<<"\t ERROR: Please enter either the number of a die as a digit "
                "(1 to 5), 'R', or 'E': ";
        cin>>tInput;
    }
}


//1.6 INTEGER INPUT VALIDATION
/****************************************************************************
 *   Name:  getNum(char,char) --> Integer Input Validation                  *
 *   Description: This function performs input validation on user input     *
 *                that was input as a character and determines if it is an  *
 *                integer before safely converting and returning an integer *
 *                version of the input character. The function also         *
 *                receives a character value that is assigned by the        *
 *                program, with 'd' (for "dice") indicating that the range  *
 *                of appropriate integer values is from (1,5), and 'v'      *
 *                (for "value") indicating that the range of appropriate    *
 *                integer values is from (1,6). The function receives these * 
 *                indicators because after converting the character into an *
 *                integer it also confirms whether or not the integer is    *
 *                within range.                                             *
 ***************************************************************************/
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
                    cout<<"\t ERROR: Input a number from 1 to 5. ";
                }
                else if (max=='v'){
                    cout<<"\t ERROR: Input a number from 1 to 6. ";
                }
                else {
                    cout<<"\t Bad code";
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
                cout<<"\t ERROR: Input a number from 1 to 5. ";
                cin>>numAgn; //Input again
            }
            else {
                cout<<"\t Bad code";
            }
        }
        else if (max=='v'){
            if (numInt>0 && numInt<7){
                numLng = true; //Flag integer as in range
            }
            else if (numInt<=0 || numInt>=7){
                //Output error message
                cout<<"\t ERROR: Input a number from 1 to 6. ";
                cin>>numAgn; //Input again
            }
            else {
                cout<<"\t Bad code";
            }
        }
    }while (numLng==false);
   
    return numInt;
}


//1.7 HOLD OR RETURN DIE
/****************************************************************************
 *   Name:   dieStat(bool&) --> Hold or Return Die                          *
 *   Description: This function is called when the player decides to        *
 *                either:                                                   *
 *                  1. "Hold" a die to prevent it from rolling next turn,   *
 *                          OR                                              *
 *                  2. Return a die that is currently being held so that    * 
 *                     it will roll next turn.                              *
 *                The function accomplishes this by reading the roll        *
 *                status of the die, then either "holding" or returning the *
 *                die (aka: switch the Boolean roll status of the die from  *
 *                true to false or vice versa) accordingly.                 *
 ***************************************************************************/
void dieStat(bool &rStat){
    //If not held / still rollable
    if (rStat){
        rStat=false; //Mark die to NOT roll next turn
    }
    else if (!rStat){
        rStat=true; //Mark die to roll next turn
    }
    else{
        cout<<"\t Error in holdDie function."<<endl;
    }
}


//1.8 DISPLAY DICE
void dspDice(const int D_VAL[], int rollCt){
       //Display dice roll
                //First bold border
                cout<<"\t\u2554";
                for (int q=0; q<63; q++){
                    cout<<"\u2550";
                }
                cout<<"\u2557\n";
                
                //Roll #
                cout<<"\t\u2551"<<"                            ROLL #"<<left
                        <<setw(29)<<rollCt<<"\u2551"<<endl;
                cout<<"\t\u2560";
                
                //Second bold border
                //Roll # space
                for (int q=0; q<13; q++){
                    cout<<"\u2550";
                }
                cout<<"\u2566";
                //First four dice spaces
                for (int s=0; s<4; s++){
                    for (int q=0; q<9; q++){
                        cout<<"\u2550";
                    }
                cout<<"\u2564";
                }
                //Last dice space
                for (int q=0; q<9; q++){
                    cout<<"\u2550";
                }
                cout<<"\u2563\n";
                
                //Die # space
                cout<<"\t\u2551 "<<right<<setw(12)<<"DIE #    "<<"\u2551"
                        <<setw(4)<<"#"<<D_VAL[0]<<setw(7)<<"\u250a"<<setw(4)<<"#"
                        <<D_VAL[1]<<setw(7)<<"\u250a"<<setw(4)<<"#"<<D_VAL[2]<<setw(7)
                        <<"\u250a"<<setw(4)<<"#"<<D_VAL[3]<<setw(7)<<"\u250a"<<setw(4)
                        <<"#"<<D_VAL[4]<<right<<setw(7)<<"\u2551"<<endl;
                
                //Dividing border between dice # and roll outcomes
                //Dice # space
                cout<<"\t\u2551"<<right<<setw(16)<<"\u255f";
                //First four dice spaces
                for (int w=0; w<4; w++){
                    for (int q=0; q<9; q++){
                        cout<<"\u2508";
                    }
                    cout<<"\u253c";
                }
                //Last dice space
                for (int q=0; q<9; q++){
                    cout<<"\u2508";
                }
                cout<<"\u2562\n";          
} 

//1.9 SCORE UPPER SECTION
int scoreUS(char box, int die1, int die2, int die3, int die4, int die5){
    //Declare local variables
    int score = 0; //Score for section, initialized to zero
    int number; //Number version of character for box
    char ok;
    number = box - '0'; //Convert box to integer
    
    if (die1==number)
        score += die1;
    if (die2==number)
        score += die2;
    if (die3==number)
        score += die3;
    if (die4==number)
        score += die4;
    if (die5==number)
        score += die5;
    
    return score;
}


//NOTES
/* cout<<"\033[2J\033[1;1H"; <-- CLEAR SCREEN*/