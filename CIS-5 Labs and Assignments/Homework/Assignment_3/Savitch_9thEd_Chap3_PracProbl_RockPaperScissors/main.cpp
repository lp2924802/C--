/* 
 * File:   main.cpp
 * Author: Lauren Postlethwaite
 * Created on January 19, 2022, 6:57 PM
 * Purpose:  Write a program to score the paper-rock-scissor game.
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
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
    

    //Exit stage right or left!
    return 0;
}