/* 
 * File:   main.cpp
 * Version: V1.1
 * Author: Lauren Postlethwaite
 * Created on January 30, 2022, 12:58 AM
 * Purpose: Project 1: Yahtzee Game
 */

#include <iostream> //I/O Library
#include <iomanip>  //Formatting Library
#include <string>   //String Variable
#include <cstdlib>  //Random Number Library
#include <ctime>    //Time Library
#include <windows.h> //Curious if this works...
using namespace std;

//User Libraries

//Global/Universal Constants

//Function Prototypes
void yesNo(char&); //Yes/no input validator
int getNum(char); //Integer input validator
void getTrn(int&,int&,int&,int&,int&); //Get final dice rolls from player turn
void keepDie(bool&,bool&,bool&,bool&,bool&,int,int,int,int,int); //Decide if keeping any dice



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
    bool rOne = true, rTwo = true, rThree = true, rFour = true, rFive = true;
    char again = 'y'; //Roll again checker, initialized to yes
    
    
    for (roll=1; roll<=nRolls; roll++){
        //Roll dice 
        if (rOne == true)
            refDie1 = rand()%6+1;
        if (rTwo == true)
            refDie2 = rand()%6+1;
        if (rThree == true)
            refDie3 = rand()%6+1;
        if (rFour == true)
            refDie4 = rand()%6+1;
        if (rFive == true)
            refDie5 = rand()%6+1;
        //List Roll Outcome
        cout<<endl<<"Roll #"<<roll<<": "<<refDie1<<", "<<refDie2<<", "<<refDie3<<", "
                            <<refDie4<<", "<<refDie5<<endl;
        
        //If you have more rolls left
        if (roll<3){
            cout<<"Roll again? (Y/N) ";
            cin>>again; //Get input
            yesNo(again); //Validate input
            
            //Respond to "Roll again" input
            if (again=='n' || again=='N')
                roll = 1000;
            else if (again=='y' || again=='Y'){
                
                //Call keepDie function
                keepDie(rOne,rTwo,rThree,rFour,rFive,refDie1,refDie2,
                                refDie3,refDie4,refDie5);
                
            }
        }
    }
    
    return;

}

//KEEP DICE FUNCTION************************************************************
void keepDie(bool &rDie1, bool &rDie2, bool &rDie3, bool &rDie4, bool &rDie5,
                    int die1, int die2, int die3, int die4, int die5){
  
    //Declare local variables
    char keep = 'y'; //Keep dice checker, initialized to "yes"
    //char keepD = 'y'; //Keep specific die
    char dieVal; //Number of the die to keep
    int dieInt; //Validated integer input

    string pick1, pick2, pick3, pick4, pick5; //What the dice look like if kept
    string openBr, closeBr, step, holdNum;
    
    //Initialize local variables
    openBr = "[";
    closeBr = "]";
    
    pick1 = to_string(die1);
    pick2 = to_string(die2);
    pick3 = to_string(die3);
    pick4 = to_string(die4);
    pick5 = to_string(die5);
    
    cout<<"Keep any dice? (Y/N) ";
    cin>>keep; //Get input
    yesNo(keep); //Validate input
    
    cout<<"Input the value of the die to keep: ";
        cin>>dieVal; //Get input
      
        dieInt = getNum(dieVal); //Validate and convert input
    
    while (keep=='y' || keep=='Y'){
         
        cout<<"Input the value of the die to keep: ";
        cin>>dieVal; //Get input
      
        dieInt = getNum(dieVal); //Validate and convert input
        
        if (rDie1 == true){
            //Check if values match
            if (die1 == dieInt){
                //Change string output
                holdNum = to_string(die1);
                step = openBr.append(holdNum);
                pick1 = step.append(closeBr);
                //Flag die to not roll
                rDie1 = false;
            }
            //Output new roll string
            cout<<"Current Roll: "<<pick1<<", "<<pick2<<", "<<pick3<<", "<<pick4<<", "<<pick5<<endl;
            //Clear string values
            holdNum.clear();
            step.clear();
        }
        
        if (rDie2 == true){
            //Check if values match
            if (die2 == dieInt){
                //Change string output
                holdNum = to_string(die2);
                step = openBr.append(holdNum);
                pick2 = step.append(closeBr);
                //Flag die to not roll
                rDie2 = false;
            }
            //Output new roll string
            cout<<"Current Roll: "<<pick1<<", "<<pick2<<", "<<pick3<<", "<<pick4<<", "<<pick5<<endl;
            //Clear string values
            holdNum.clear();
            step.clear();
        }
        
        if (rDie3 == true){
            //Check if values match
            if (die3 == dieInt){
                //Change string output
                holdNum = to_string(die3);
                step = openBr.append(holdNum);
                pick2 = step.append(closeBr);
                //Flag die to not roll
                rDie3 = false;
            }
            //Output new roll string
            cout<<"Current Roll: "<<pick1<<", "<<pick2<<", "<<pick3<<", "<<pick4<<", "<<pick5<<endl;
            //Clear string values
            holdNum.clear();
            step.clear();
        }
        
        if (rDie4 == true){
            //Check if values match
            if (die4 == dieInt){
                //Change string output
                holdNum = to_string(die4);
                step = openBr.append(holdNum);
                pick4 = step.append(closeBr);
                //Flag die to not roll
                rDie4 = false;
            }
            //Output new roll string
            cout<<"Current Roll: "<<pick1<<", "<<pick2<<", "<<pick3<<", "<<pick4<<", "<<pick5<<endl;
            //Clear string values
            holdNum.clear();
            step.clear();
        }
        
        if (rDie5 == true){
            //Check if values match
            if (die5 == dieInt){
                //Change string output
                holdNum = to_string(die5);
                step = openBr.append(holdNum);
                pick2 = step.append(closeBr);
                //Flag die to not roll
                rDie5 = false;
            }
            //Output new roll string
            cout<<"Current Roll: "<<pick1<<", "<<pick2<<", "<<pick3<<", "<<pick4<<", "<<pick5<<endl;
            //Clear string values
            holdNum.clear();
            step.clear();
        }
        
        if (die1!=dieInt && die2!=dieInt && die3!=dieInt && die4!=dieInt && die5!=dieInt){
            cout<<"You don't have any "<<dieInt<<" dice."<<endl;
        }
        
        if (rDie1 == false && rDie2 == false && rDie3 == false && rDie4 == false && rDie5 == false){
            cout<<"No more dice available."<<endl;
        }
     
        cout<<"Input the value of another die to keep, or press 'N' to roll: ";
        cin>>dieVal; //Get input
        
        if (dieVal =='n' || dieVal == 'N'){
            keep = 'N';
        }
        else{
            dieInt = getNum(dieVal); //Validate and convert input
        }
      
    }
    
    
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
int getNum(char num){
    
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
                cout<<"ERROR: Input a number from 1 to 6."<<endl;
                cin>>numAgn; //Input again
            }
        }while (numOk==false);
        
        //Check if integer is in range
        if (numInt>=0 && numInt < 7){
            numLng = true; //Flag integer as in range
        }
        else {
            //Output error message
            cout<<"ERROR: Input a number from 1 to 6."<<endl;
            cin>>numAgn; //Input again
        }
    }while (numLng==false);
   
    return numInt;
}