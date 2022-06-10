/* 
 * File:   main.cpp
 * Version: V1.2
 * Author: Lauren Postlethwaite
 * Created on January 29, 2022, 5:48 PM
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
            cout<<endl<<"Roll again? (Y/N) ";
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
    char keepD = 'y'; //Keep specific die
    char yesDie; //Number of the die to keep
    int yesInt; //Validated integer input
    int die = 1;
    int numDie = 5;
    string str1, str2, str3, str4, str5;
    string pick1, pick2, pick3, pick4, pick5; //What the dice look like if kept
    string openBr, closeBr, holdNum;
    bool hold1 = false, hold2 = false, hold3 = false, hold4 = false, hold5 = false; //Flag if dice has been picked
    
    //Initialize local variables
    openBr = "[";
    closeBr = "]";
    str1 = to_string(die1);
    str2 = to_string(die2);
    str3 = to_string(die3);
    str4 = to_string(die4);
    str5 = to_string(die5);
    
    cout<<endl<<"Keep any dice? (Y/N) ";
    cin>>keep; //Get input
    yesNo(keep); //Validate input
    
    while (keep=='y' || keep=='Y'){
         
        cout<<"Input the # of the die you want to keep: ";
        cin>>yesDie; //Get input
      
        yesInt = getNum(yesDie); //Validate and convert input
        
        if (yesInt==1 && hold1==false){
            //cout<<"Keep Die #1? (Y/N) ";
            //cin>>keepD; //Get input
            //yesNo(keepD); //Validate input
                
            //if (keepD=='y' || keepD=='Y'){
            pick1 = openBr.append(str1);
            str1 = pick1.append(closeBr);
            hold1 = true;
            rDie1 = false;
            //holdNum = " "; //Clear holding string
              
        }
        else if (yesInt==2 && hold2==false){
            //cout<<"Keep Die #2? (Y/N) ";
            //cin>>keepD; //Get input
            //yesNo(keepD); //Validate input
            
            //if (keepD=='y' || keepD=='Y'){
            pick2 = openBr.append(str2);
            str2 = pick2.append(closeBr);
            hold2 = true;
            rDie2 = false;
            //holdNum = " "; //Clear holding string
            
        }
        else if (yesInt==3 && hold3==false){
            //cout<<"Keep Die #3? (Y/N) ";
            //cin>>keepD; //Get input
            //yesNo(keepD); //Validate input
            
            //if (keepD=='y' || keepD=='Y'){
            pick3 = openBr.append(str3);
            str3 =pick3.append(closeBr);
            hold3 = true;
            rDie3 = false;
            //holdNum = " "; //Clear holding string
            
        }
        else if (yesInt==4 && hold4==false){
            //cout<<"Keep Die #4? (Y/N) ";
            //cin>>keepD; //Get input
            //yesNo(keepD); //Validate input
            
            //if (keepD=='y' || keepD=='Y'){
            pick4 = openBr.append(str4);
            str4 = pick4.append(closeBr);
            hold4 = true;
            rDie4 = false;
            //holdNum = " "; //Clear holding string
            
        }
        else if (yesInt==5 && hold5==false){
            //cout<<"Keep Die #5? (Y/N) ";
            //cin>>keepD; //Get input
            //yesNo(keepD); //Validate input
            
            //if (keepD=='y' || keepD=='Y'){
            pick5 = openBr.append(str5);
            str5 = pick5.append(closeBr);
            hold5 = true;
            rDie5 = false;
            //holdNum = " "; //Clear holding string
            
        }
        else{
            cout<<"No available dice to choose."<<endl;
        }
        cout<<endl<<"Current Roll: "<<str1<<", "<<str2<<", "<<str3<<", "<<str4<<", "<<str5<<endl;
        holdNum.clear(); //Clear holding string
                
        cout<<"Do you want to keep any more dice? (Y/N)  ";
        cin>>keep; //Get input
        yesNo(keep); //Validate input
        
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
                cout<<"ERROR: Input a number from 1 to 5."<<endl;
                cin>>numAgn; //Input again
            }
        }while (numOk==false);
        
        //Check if integer is in range
        if (numInt>=0 && numInt < 6){
            numLng = true; //Flag integer as in range
        }
        else {
            //Output error message
            cout<<"ERROR: Input a number from 1 to 5."<<endl;
            cin>>numAgn; //Input again
        }
    }while (numLng==false);
   
    return numInt;
}