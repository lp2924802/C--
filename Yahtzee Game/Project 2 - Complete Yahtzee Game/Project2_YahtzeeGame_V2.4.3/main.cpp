/**************************************************************************** 
 * File:   main.cpp                                                         *
 * Version: V2.4.3                                                          *
 * Author: Lauren Postlethwaite                                             *
 * Created on February 9, 2022, 2:21 PM                                     *     
 * Purpose: Project 2: Yahtzee Game. All spaces in scorecard are able to    *
 *                     be printed onto. Upper section scores correctly.     *
 *                     Modularization has been going well, although the     *
 *                     program itself is still fairly long.                 *
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
 *      1.8 Display Dice Upper Table                                        *
 *      1.9 Score Dice                                                      *
 *          1.9.1 Get Index                                                 *
 *          1.9.? Score Upper Section                                       *
 *      1.10 Scorecard Input Code Validation                                *
 *      1.11 Determine Number of Each Die Value                             *
 ***************************************************************************/
char getIntro(fstream&); //1.1 Game Introduction
void yesNo(char&); //1.2 Yes/No Input Validation
void getCard(fstream&,int[],bool[]); //1.3 Get Scorecard
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
int scoreFn(int, int[], bool[], int[]); //1.9 Score Dice
int getIndx(char, bool[]); //1.9.1 Get Index
int scoreUS(int, int[]); //1.9.? Score Upper Section
void cdInVal(char&); //1.10 Scorecard Input Code Validation
void numVal(int[], int[]); //1.11 Determine Number of Each Die Value



//1.0 MAIN CODE
/****************************************************************************
 *  Name: main(int,char) --> Main Function                                  *
 *  Description: Starting and ending point for the program execution.       *
 ***************************************************************************/
int main(int argc, char** argv) {
    
    //RANDOM NUMBER SEED
     srand(static_cast<unsigned int>(time(0)));
    
    //ARRAY ELEMENTS BREAKDOWN
    /************************************************************************
     * ONE CONSTANT:                                                        *
     *          1. const int VALS = 24 --> Number of spaces                 *  
     *                                                                      *
     * TWO PARALLEL ARRAYS:                                                 *
     *          1. int numSp[VALS] --> Score in each space                  *
     *          2. bool fullSp[VALS] --> Flag for if space is taken         *
     ***********************************************************************/
     
    //SCORECARD-RELATED VARIABLES AND CONSTANTS******************************
    const int VALS = 24; //Number of spaces in scorecard
    int numSp[VALS]; //Score for each space in scorecard
    bool fullSp[VALS]; //Flag for if space is taken
    fstream scorecd; //File stream for scorecard
    string line; //Line to read scorecard
    //***********************************************************************
    
    for (int i=0; i<VALS; i++){
        numSp[i] = 0;
        fullSp[i] = false;
    }
    
    //DICE-RELATED VARIABLES AND CONSTANTS***********************************
    const int NUM = 5; //Number of dice in game
    const int D_VAL[NUM] = {1,2,3,4,5};
    int dice[NUM] = {1,1,1,1,1}; //Int array of all five dice
    string * strDice[NUM];
    bool roll[NUM] = {true,true,true,true,true};
    const int D_COUNT = 6; //Possible die values
    int valCnt[D_COUNT] = {0,0,0,0,0,0};
    //***********************************************************************
    
    //PLAYER-DECISION VARIABLES AND CONSTANTS********************************
    char turn; //Input --> (1,5), 'R', or 'E'
    char box; //Input for where to place score on scorecard
    int indxVal; //Returned array index from box input
    int holdInt, i=0; //Integer version of holdDie
    int rollCt = 1; //Roll user is on, initialized to 1
    const int nRolls = 3; //Maximum number of rolls per turn
    char ready, pause; //New game? and Next turn or end early? (Y/N) Flags
    bool all = false, ytz; //Game over (all spots filled) flag
                        //DOES NOT INCLUDE YAHTZEE BONUS SPOTS!!!!!
    int score = 0; //Determined score from player's turn
    int ytzChk = 0; //Flag for if roll is a Yahtzee
    //***********************************************************************
    
    //INITIALIZE SCORECARD FILE**********************************************
    scorecd.open("ytzGame.txt", ios::out); //Create/open scorecard file
    
    if(!scorecd){
        cout<<"File did not open!"; //Notify of file error
    }
    
    getCard(scorecd,numSp,fullSp); 

    scorecd.close(); //Re-close card for now to fully initialize it
    //***********************************************************************
    
    scorecd.open("ytzGame.txt", ios::in); //Reopen scorecard to read
    
    ready = getIntro(scorecd); //Get game introduction

    
    //GAMEPLAY HERE --> (One loop = One entire game)*************************
    while (ready=='y' || ready=='Y'){
        
        all = false; //Set flag to false
        
        //CLEAR AND REDISPLAY SCORECARD**************************************
        cout<<"\033[2J\033[1;1H"; //Clear screen
        scorecd.clear(); //Clear the EOF flag
        scorecd.seekg(0, ios::beg); //Go back to the beginning of 
                                        //scorecard file
        getline(scorecd,line,'@'); //Get the scorecard info
        cout<<line; //Display the info
        //*******************************************************************
                
        //TAKE TURNS HERE --> (Each iteration = one entire "turn")***********
        while (!all){ //While all scorecard spaces NOT filled
            
            //ROLL DICE HERE --> (Each iteration = one roll******************
            for (rollCt=1; rollCt<=nRolls; rollCt++) {
                
                //Roll all available dice
                for (int i=0; i<NUM; i++){
                    //Roll die
                    if (roll[i]){
                        dice[i] = rand()%6+1;
                    } //End single array element dice roll for loop
                    //Get new string label for rolled die
                    strDice[i] = getLb(dice[i],roll[i]);
                } //End full array dice roll for loop
                
                //CLEAR AND REDISPLAY SCORECARD******************************
                cout<<"\033[2J\033[1;1H"; //Clear screen
                scorecd.clear(); //Clear the EOF flag
                scorecd.seekg(0, ios::beg); //Go back to the beginning of 
                                                //scorecard file
                getline(scorecd,line,'@'); //Get the scorecard info
                cout<<line<<endl; //Display the info
                //***********************************************************

                //Display top part of dice roll table
                dspDice(D_VAL,rollCt);

                //Roll outcomes**********************************************
                cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"<<right<<setw(6)
                        <<* strDice[0]<<setw(6)<<"\u250a"<<setw(6)<<* 
                        strDice[1]<<setw(6)<<"\u250a"<<setw(6)<<* strDice[2]
                        <<setw(6)<<"\u250a"<<setw(6)<<* strDice[3]<<setw(6)
                        <<"\u250a"<<setw(6)<<* strDice[4]<<setw(6)<<"\u2551"
                        <<endl;
                //***********************************************************
                
                //Bottom half of dice roll table*****************************
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
                //***********************************************************
                
                numVal(dice, valCnt); //Determine how many dice of each value
                
                //Determine if Yahtzee***************************************
                any_of(valCnt, valCnt+6, [](int q){return q==5;})?
                    ytz = true :
                    ytz = false;
                
                if (ytz){ //Display Yahtzee message
                    if(!fullSp[11]){
                        cout<<"\n\t"<<left<<setw(63)<<"           "
                                "                    Yahtzee!\n";
                    }
                    else if (fullSp[11]){
                        cout<<"\n\t"<<left<<setw(63)<<"         "
                            "                   Yahtzee Bonus!\n";
                    }
                }
                //End of Yahtzee Check***************************************
                
                //Player given choice to hold/return dice, roll again, 
                    //or end their turn  
                if (rollCt<nRolls){ //Choice only offered if NOT roll #3
                    
                    if (roll[0] == roll[1] && roll[1] == roll[2] && roll[2] 
                            == roll[3] && roll[3] == roll[4] && 
                            roll[4] == true) { //If all dice can still be 
                                //rolled then there's none to return, so 
                                //there's no need to mention returning dice
                        cout<<"\n\t   Enter the number(s) of any dice to "
                                "hold for the next roll, \n\t   'R' to roll "
                                "again, or 'E' to end your turn: ";
                    }
                    else { //One or more dice held --> mention returning dice
                        cout<<"\n\t   Enter the number(s) of any dice to "
                                "hold or return for the\n\t   next roll, "
                                "'R' to roll again, or 'E' to end your "
                                "turn: ";
                    }
                    
                    //Determine if Yahtzee***********************************
                    any_of(valCnt, valCnt+6, [](int q){return q==5;})?
                        ytz = true :
                        ytz = false;

                    if (ytz){ //Display Yahtzee message
                        if(!fullSp[11]){
                            cout<<"\n\t"<<left<<setw(63)<<"           "
                                    "                    Yahtzee!\n";
                        }
                        else if (fullSp[11]){
                            cout<<"\n\t"<<left<<setw(63)<<"         "
                                "                   Yahtzee Bonus!\n";
                        }
                    }
                    //End of Yahtzee Check***********************************
                    
                    cin>>turn; //Get input
                    turnVal(turn); //Validate input
                    
                    //CLEAR AND REDISPLAY SCORECARD**************************
                    cout<<"\033[2J\033[1;1H"; //Clear screen
                    scorecd.clear(); //Clear the EOF flag
                    scorecd.seekg(0, ios::beg); //Go back to the beginning 
                                                    //of scorecard file
                    getline(scorecd,line,'@'); //Get the scorecard info
                    cout<<line<<endl; //Display the info
                    //*******************************************************
                    
                    //If player chooses to keep/return dice******************
                    if (turn=='1' || turn=='2' || turn=='3' || turn=='4' 
                            || turn=='5'){ 
                    
                        //While player continues to input turn = (1,5)
                        while (turn=='1' || turn=='2' || turn=='3' || 
                                turn=='4' || turn=='5'){
                            
                            //Validate and convert input to integer
                            holdInt = getNum(turn,'d'); 
                            
                            //Switch roll status for die
                            dieStat(roll[(holdInt-1)]); 
                            //Get new string label for die
                            strDice[(holdInt-1)] = getLb(dice[(holdInt-1)]
                                    ,roll[holdInt-1]);
                        
                            //CLEAR AND REDISPLAY SCORECARD******************
                            //Keep this screen clear, it prevents repeat 
                            //rolls from showing if multiple dice are held
                            cout<<"\033[2J\033[1;1H"; //Clear screen
                            scorecd.clear(); //Clear the EOF flag
                            //Go back to the beginning of scorecard file
                            scorecd.seekg(0, ios::beg); 
                            getline(scorecd,line,'@'); //Get  scorecard info
                            cout<<line<<endl; //Display the info 
                        
                            //Display top part of dice roll table
                            dspDice(D_VAL,rollCt);
                
                            //Roll outcomes**********************************
                            cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"
                                    <<right<<setw(6)<<* strDice[0]<<setw(6)
                                    <<"\u250a"<<setw(6)<<* strDice[1]<<setw(6)  
                                    <<"\u250a"<<setw(6)<<* strDice[2]<<setw(6)
                                    <<"\u250a"<<setw(6)<<* strDice[3]<<setw(6)
                                    <<"\u250a"<<setw(6)<<* strDice[4]<<setw(6)
                                    <<"\u2551"<<endl;
                            //***********************************************
                
                            //Bottom part of dice roll table*****************
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
                            //***********************************************
                            
                            cout<<"\n\t"<<left<<setw(63)<<"   Enter the "
                                    "number(s) of any dice to hold or return"
                                    "for the\n\t   next roll, 'R' to roll "
                                    "again, or 'E' to end your turn: ";
                            cin>>turn; //Get input
                            turnVal(turn); //Validate input
                        } //End while turn = (1,5) section
                        
                        //CLEAR AND REDISPLAY SCORECARD**********************
                        cout<<"\033[2J\033[1;1H"; //Clear screen
                        scorecd.clear(); //Clear the EOF flag
                        scorecd.seekg(0, ios::beg); //Go back to the 
                                                        //beginning of the
                                                        //scorecard file
                        getline(scorecd,line,'@'); //Get the scorecard info
                        cout<<line<<endl; //Display the info
                        //***************************************************
                        
                        //Display top part of dice roll table
                         dspDice(D_VAL,rollCt);
                
                        //Roll outcomes**************************************
                        cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"<<right
                                <<setw(6)<<* strDice[0]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[1]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[2]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[3]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[4]<<setw(6)<<"\u2551"
                                <<endl;
                        //***************************************************
                    
                        //Bottom border of dice roll table*******************
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
                        //***************************************************
                    } //End turn = (1,5) if section
                    else if (turn=='e' || turn=='E'){ //Opt to end turn
                        rollCt = 10; //Set roll count past 3 to break loop
                    }
                    else if (turn=='r' || turn=='R'){
                        
                        //CLEAR AND REDISPLAY SCORECARD**********************
                        cout<<"\033[2J\033[1;1H"; //Clear screen
                        scorecd.clear(); //Clear the EOF flag
                        scorecd.seekg(0, ios::beg); //Go back to the 
                                                        //beginning of the
                                                        //scorecard file
                        getline(scorecd,line,'@'); //Get the scorecard info
                        cout<<line<<endl; //Display the info
                        //***************************************************

                       //Display top part of dice roll table
                        dspDice(D_VAL,rollCt);

                        //Roll outcomes**************************************
                        cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"<<right
                                <<setw(6)<<* strDice[0]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[1]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[2]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[3]<<setw(6)<<"\u250a"
                                <<setw(6)<<* strDice[4]<<setw(6)<<"\u2551"
                                <<endl;
                        //***************************************************

                        //Bottom border of dice roll table*******************
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
                        //***************************************************
                        
                    } //End turn == 'r' || 'R' else if section
                    else {
                        cout<<"ERROR IN TURN IF-ELSE IF BLOCK"<<endl;
                    }

                } //END IF BLOCK FOR PLAYERS WITH TURNS REMAINING************

            } //END FOR LOOP THAT HAS PLAYER KEEP ROLLING DICE***************
            
            //Left dice rolling loop --> display final dice outcome
                                   //--> choose where to place score
                                   //--> write score to scorecard
            
            //Going to put a clear and redisplay in here just because
            //CLEAR AND REDISPLAY SCORECARD**********************************
            cout<<"\033[2J\033[1;1H"; //Clear screen
            scorecd.clear(); //Clear the EOF flag
            scorecd.seekg(0, ios::beg); //Go back to the beginning of 
                                            //scorecard file
            getline(scorecd,line,'@'); //Get the scorecard info
            cout<<line<<endl; //Display the info
            //***************************************************************
                        
            //Display top part of dice roll table
                dspDice(D_VAL,3);
                
            //Roll outcomes**************************************************
            cout<<"\t\u2551"<<right<<setw(16)<<"\u2551"<<right<<setw(6)
                    <<* strDice[0]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[1]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[2]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[3]<<setw(6)<<"\u250a"<<setw(6)
                    <<* strDice[4]<<setw(6)<<"\u2551"<<endl;
            //***************************************************************
            
            //Bottom border**************************************************
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
            //***************************************************************
            
            //Determine if Yahtzee***************************************
            any_of(valCnt, valCnt+6, [](int q){return q==5;})?
                ytz = true :
                ytz = false;

            if (ytz){ //Display Yahtzee message
                if(!fullSp[11]){
                    cout<<"\n\t"<<left<<setw(63)<<"           "
                            "                    Yahtzee!\n";
                }
                else if (fullSp[11]){
                    cout<<"\n\t"<<left<<setw(63)<<"         "
                        "                   Yahtzee Bonus!\n";
                }
            }
            //End of Yahtzee Check***************************************   
            
            //Get scorecard input code
            cout<<"\n\t  Please enter which box you would like to place your "
                    "score: ";
            cin>>box; //Get scorecard input code
            cdInVal(box); //Validate input

            indxVal=getIndx(box,fullSp); //Get array index from box input
            
            numSp[indxVal] = scoreFn(indxVal,dice, fullSp, valCnt);
            
            //Write new data to file*****************************************
            scorecd.close(); //Re-close card for now to fully set it
            scorecd.open("ytzGame.txt", ios::out); //Open scorecard file

            if(!scorecd){ //If file fails to open
                cout<<"\tFile did not open!"; //Notify of file error
            }
    
            getCard(scorecd,numSp,fullSp); //Write new info to file
            scorecd.close(); //Close file again to "save" (in theory)
            scorecd.open("ytzGame.txt", ios::in); //Open file to read
            //***************************************************************
            
            //CLEAR AND REDISPLAY SCORECARD**********************************
            cout<<"\033[2J\033[1;1H"; //Clear screen
            scorecd.clear(); //Clear the EOF flag
            scorecd.seekg(0, ios::beg); //Go back to the beginning of 
                                            //scorecard file
            getline(scorecd,line,'@'); //Get the scorecard info
            cout<<line; //Display the info
            //**************************************************************
           
            //Reset dice rolls
            for (i=0; i<NUM; i++){
                roll[i]=true;
            }
            
            //If all spots full, mark all as true to end while loop
            if (all_of(fullSp, fullSp+5, [](bool i){return i;})){
                all = true;
            }
            
            if (!all){
                //Pause before next turn, give opportunity to end game early
                cout<<"\n\t Enter 'Y' to take next turn, or 'N' to end the "
                        "game: ";
                cin>>pause; //Get input
                yesNo(pause); //Validate input

                if (pause=='n' || pause=='N'){
                    all = true; //Set all to true to break while !all loop
                }
            }

        } //END WHILE LOOP THAT HAS PLAYER KEEP TAKING TURNS***************** 
        //Tally up final score
        
        //Prompt if player wants to play again
        cout<<"\n\t  Play again? (Y/N): ";
        cin>>ready; //Get input
        yesNo(ready); //Validate input
        
        for (int i=0; i<VALS; i++){
            numSp[i] = 0; //Reset all scorecard spaces to zero
            fullSp[i] = false; //Reset all "space taken" flags to false
        }
        
    } //END WHILE LOOP THAT HAS PLAYER KEEP PLAYING YAHTZEE GAMES************
    //End program
    
    scorecd.close(); //Close scorecard file
 
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
void getCard(fstream &card, int scores[], bool taken[]){
    
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
    card<<"\t\u2551"<<left<<setw(16)<<"      Aces"<<"\u2551"<<right
            <<setw(7)<<scores[0]<<"     \u2551\u2551"<<left<<setw(16)
            <<"  3 of a kind"<<"\u2551"
            <<right<<setw(9)<<scores[6]<<"      \u2551\n";
    
    thinUS(card);
    thinLS(card);
    
    //TWOS - SUM OF ALL 2'S**************************************************
    //4 OF A KIND - SUM OF ALL DICE IF 4 DICE HAVE THE SAME VALUE************
    card<<"\t\u2551"<<left<<setw(16)<<"      Twos"<<"\u2551"<<right<<setw(18)
            <<setw(7)<<scores[1]<<"     \u2551\u2551"<<left<<setw(16)
            <<"  4 of a kind"<<"\u2551"<<right<<setw(9)<<scores[7]
            <<"      \u2551\n";
    thinUS(card);
    thinLS(card);
    
    //THREES - SUM OF ALL 3'S************************************************
    //FULL HOUSE - 25 PTS IF 2 OF 1 VALUE OF DICE AND 3 OF ANOTHER VALUE*****
    card<<"\t\u2551"<<left<<setw(16)<<"     Threes"<<"\u2551"<<right
            <<setw(7)<<scores[2]<<"     \u2551\u2551"<<left<<setw(16)
            <<"   Full House"<<"\u2551"<<right<<setw(9)<<scores[8]
            <<"      \u2551\n";
    thinUS(card);
    thinLS(card);

    //FOURS - SUM OF ALL 4'S*************************************************
    //SMALL STRAIGHT - 30 PTS IF SEQUENCE OF 4*******************************
    //(sequence of 4)--> statement from SM Straight**************************
    card<<"\t\u2551"<<left<<setw(16)<<"      Fours"<<"\u2551"<<right
            <<setw(7)<<scores[3]<<"     \u2551\u2551"<<left<<setw(16)
            <<"  SM Straight"<<"\u2551"<<right<<setw(9)<<scores[9]
            <<"      \u2551\n";
    thinUS(card);
    card<<"\u2551"<<left<<setw(16)<<" (sequence of 4)"<<"\u2551"<<right
            <<setw(19)<<"\u2551\n";
    
    //FIVES - SUM OF ALL 5'S*************************************************
    //LARGE STRAIGHT - 40 PTS IF SEQUENCE OF 5*******************************
    card<<"\t\u2551"<<left<<setw(16)<<"      Fives"<<"\u2551"<<right
            <<setw(7)<<scores[4]<<"     \u2551";
    thinLS(card);
    thinUS(card);
    card<<"\u2551"<<left<<setw(16)<<"  LG Straight"<<"\u2551"<<right
            <<setw(9)<<scores[10]<<"      \u2551\n";
    
    //SIXES - SUM OF ALL 6'S*************************************************
    //(sequence of 5)--> statement from LG Straight**************************
    card<<"\t\u2551"<<left<<setw(16)<<"      Sixes"<<"\u2551"<<right
            <<setw(7)<<scores[5]<<"     \u2551\u2551"<<left<<setw(16)
            <<" (sequence of 5)"<<"\u2551"<<right<<setw(19)<<"\u2551\n";
    thckUS(card,'m');
    thinLS(card);
    
    //TOTAL SCORE - SUM OF SCORES FROM 1-6***********************************
    //YAHTZEE - 50 PTS IF ALL 5 DICE HAVE THE SAME VALUE*********************
    card<<"\t\u2551"<<left<<setw(16)<<"      TOTAL"<<"\u2551"<<right
            <<setw(7)<<scores[17]<<"     \u2551\u2551"<<left<<setw(16)
            <<"     Yahtzee"<<"\u2551"<<right<<setw(9)<<scores[11]
            <<"      \u2551\n";
    
    card<<"\t\u2551"<<left<<setw(16)<<"      SCORE"<<"\u2551"<<right
            <<setw(18)<<"\u2551\u2551"<<left<<setw(16)<<"  (5 of a kind)"
            <<"\u2551"<<right<<setw(19)<<"\u2551\n";
    thckUS(card,'m');    
    thinLS(card);
    
    //BONUS - 35 PTS IF TOTAL SCORE >= 63************************************
    //CHANCE - SUM OF ALL THE VALUES OF ALL DICE IN HAND*********************
    card<<"\t\u2551"<<left<<setw(16)<<" BONUS (+35pts)"<<"\u2551"<<right
            <<setw(7)<<scores[18]<<"     \u2551\u2551"<<left<<setw(16)
            <<"     Chance"<<"\u2551"<<right<<setw(9)<<scores[12]
            <<"      \u2551\n";
    
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
            <<setw(2)<<scores[13]<<"\u250a"<<right<<setw(2)<<scores[14]
            <<"\u250a"<<setw(2)<<scores[15]<<"\u250a"
            <<setw(2)<<scores[16]<<"\u2551\n";
   
    //TOTAL OF "UPPER" SECTION - TOTAL SCORE + BONUS*************************
    card<<"\t\u2551"<<left<<setw(16)<<"    TOTAL OF"<<"\u2551"<<right
            <<setw(7)<<scores[19]<<"     \u2551\u2551"<<left
            <<setw(16)<<"      Bonus"<<"\u255f";
    
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
            <<setw(9)<<scores[20]<<"      \u2551\n";
    
    thckUS(card,'b');
    thckLS(card,'m');

    //TOTAL OF "LOWER" SECTION - SUM OF REMAINING SECTIONS*******************
    card<<"\t\u2554";
    for (int q=0; q<28; q++){
        card<<"\u2550";
    }
    card<<"\u2557 \u2551"<<left<<setw(16)<<"    TOTAL OF"<<"\u2551"<<
            right<<setw(9)<<scores[21]<<"      \u2551\n";
 
    card<<"\t\u2551"<<right<<setw(28)<<"SCORECARD INPUT CODES    "
            <<"\u2551 \u2551"<<left<<setw(16)<<"\"LOWER\" SECTION"<<"\u2551"
            <<right<<setw(19)<<"\u2551\n";
    
    card<<"\t\u2551"<<left<<setw(11)<<" 1 = Aces "<<right<<setw(17)
            <<" a/b = 3/4 kind "<<"\u2551 ";
    thckLS(card,'m');
    
    //REPEAT OF "UPPER" SECTION TOTAL****************************************
    card<<"\t\u2551"<<left<<setw(11)<<" 2 = Twos"<<right<<setw(17)
            <<" c = Full House "<< "\u2551 \u2551"<<left<<setw(16)
            <<"    TOTAL OF"<<"\u2551"<<right<<setw(9)<<scores[22]
            <<"      \u2551\n";
    card<<"\t\u2551"<<left<<setw(11)<<" 3 = Threes"<<right<<setw(17)
            <<" d = SM straight "<<"\u2551 \u2551"<<left<<setw(16)
            <<"\"UPPER\" SECTION"<<"\u2551"<<right<<setw(19)<<"\u2551\n";
    
    card<<"\t\u2551"<<left<<setw(11)<<" 4 = Fours"<<right<<setw(17)
            <<" e = LG straight "<<"\u2551 ";
    thckLS(card,'m');
    
    //GRAND TOTAL - SUM OF "UPPER" AND "LOWER" SECTIONS**********************
    card<<"\t\u2551"<<left<<setw(11)<<" 5 = Fives"<<right<<setw(17)
            <<" f = Yahtzee "<<"\u2551 \u2551"<<left<<setw(16)<<
            "      GRAND"<<"\u2551"<<right<<setw(9)<<scores[23]
            <<"      \u2551\n";
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


//1.9 SCORE DICE
int scoreFn(int indx, int dice[], bool full[], int vals[]){
    
    int score;
    //const int DIES = 5;
    //const int VALS = 6;
    
    //Get Upper Section scores
    if (indx>=0 && indx<6){
        score = scoreUS(indx,dice);
    }
    else if (indx>=6 && indx<16){ 
        //Do stuff
    }
    
    return score;
}


//1.9.1 GET INDEX
/****************************************************************************
 *   Name:   getIndx(char box, bool taken[]) --> Get Index                  *
 *   Description: This function is called from the scoreFn function to      *
 *                determine the index of a dice roll to inform further      *
 *                scoring processes.                                        *
 ***************************************************************************/
int getIndx(char box, bool taken[]){
    int indx;
    
    if (box=='1')
        indx = 0;       
    else if (box=='2')
        indx = 1;
    else if (box=='3')
        indx = 2;
    else if (box=='4')
        indx = 3;
    else if (box=='5')
        indx = 4;
    else if (box=='6')
        indx = 5;
    else if (box=='a' || box=='A')
        indx = 6;
    else if (box=='b' || box=='B')
        indx = 7;
    else if (box=='c' || box=='C')
        indx = 8;
    else if (box=='d' || box=='D')
        indx = 9;
    else if (box=='e' || box=='E')
        indx = 10;
    else if (box=='f' || box=='F'){
        if (taken[11]){ //Yahtzee filled?
            if (taken[13]){ //YB1 filled?
                if (taken[14]){ //YB2 filled?
                    if (taken[15]){ //YB3 filled?
                        indx=16;
                    }
                    else if (!taken[15]){
                        indx=15;
                    }
                    else {
                        cout<<"Error in Get Index Value"<<endl;
                    }
                }
                else if (!taken[14]){
                    indx=14;
                }
                else {
                    cout<<"Error in Get Index Value"<<endl;
                }
            }
            else if (!taken[13]){
                indx = 13;
            }
            else {
                cout<<"Error in Get Index Value"<<endl;
            }
        }
        else if (!taken[11]){
            indx=11;
        }
        else {
            cout<<"Error in Get Index Value"<<endl;
        }
    }
    else if (box=='g' || box=='G')
        indx = 12;
    else
        cout<<"Error in Get Index Value"<<endl;
    
    return indx;
    
}



//1.9.? SCORE UPPER SECTION
/****************************************************************************
 *   Name:   scoreUS(int indx, int dice[]) --> Score Upper Section          *
 *   Description: This function is called from the scoreFn function to      *
 *                determine the score of a dice roll when a player wants    *
 *                to place their score in one of the Upper Section spaces.  *
 ***************************************************************************/
int scoreUS(int indx, int dice[]){
    //Declare local variables
    int score = 0; //Score for section, initialized to zero
    int number;
    number = indx + 1;
    const int MAX = 6;       
    
    for (int i=0; i<MAX; i++){
        if (dice[i]==number){
            score+=number;
        }
        else {
            score+=0;
        }
    }
    
    return score;
}


//1.10 SCORECARD INPUT CODE VALIDATION
void cdInVal(char &inpt){
    bool flag = false;
    char temp; 
    
    temp = tolower(inpt);
    
        //Loop while input is not in (1,6), (a,g) format
        while (temp!='a' && temp!='b' && temp!='c' && temp!='d' && temp!='e'
                && temp!='f' && temp!='g' && temp!='1' && temp!='2'
                && temp!='3' && temp!='4' && temp!='5' && temp!='6') {
            cout<<"\t ERROR: Please enter one of the scorecard input codes"
                    " listed above: ";
            cin>>temp;
        }
    
    inpt = temp;
    
}
    


//1.11 DETERMINE NUMBER OF EACH DIE VALUE
void numVal(int dice[], int vals[]){
    
    //Declare local variables
    const int DIES = 5;
    const int VALS = 6;
    int value = 0; //Value of die face in question
    
    for (int i=0; i<VALS; i++){ //Six iterations --> one for each die value
        
        value = i + 1;
        
        for (int j=0; j<DIES; j++){ //Five iterations --> one for each die
            
            if (dice[j]==value){ //Die fits in category
                vals[i]++; //Increase # of dice in category by one
            }
            
        } 
        //End dice loop
    }
    //End value loop
}


//NOTES
/* cout<<"\033[2J\033[1;1H"; <-- CLEAR SCREEN*/