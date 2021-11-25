/* Lab4.cpp
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: Exactlly two command line argument should be passed into this main function the second 
one should be "TicTacToe" or "Gomoku".
If the right number of command line argument was passed, this main function will create a shared pointer 
pointing to an instance of the TicTacToeGame or GomokuGame class and calls the play() function. Any error 
generated will be catched
*/
#include <iostream>
#include "ttt_Board.h"
#include "GomokuGame.h"
using namespace std;

int main(int argc, char * argv[]){
    int result; 
    try{
        shared_ptr<GameBase> game_pointer(GameBase::set_game(argc, argv));
        if(game_pointer == NULL){ //if NULL is returning from set_game
            result = usageMessage( argv[(int)variables::Lab4], message); // errorlevel is -3
            return result; 
        }
        // play the game
        result =  game_pointer->play();
    }catch(bad_alloc& e){ //bad allocation
        cout<< "There is a bad allocation" <<e.what()<< endl;
        result = variables::bad_alloc_enum; // 30
    }catch (...){
        cout<< "There is an un-identified error" << endl;
        result =  variables::other_error; //any other error: 40
    }

    return result; 
}

const string message = "can only take in two command line arguments: one being the program name, one being 'TicTacToe' ";

