/* ttt_Board.h
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: Declaration for all the functions and member variables for the TicTacToeGame derived class
*/

#pragma once
#include "GameBase.h"

//Declaration of the Game Class
class TicTacToeGame: public GameBase{
    public: 
    virtual void print();

//This function determines if the game is won by X or O
    virtual bool done();
// This function determines if the game is drawn or not
    virtual bool draw();
// This method determines whose turn it is, calls prompt() and stores all the useful data 
// of the game. It will also print the board if a move is made. 
    virtual int turn();

// Constructor
    TicTacToeGame();
// Destructor
    ~TicTacToeGame();
// overload operator to print the game board
    friend std::ostream& operator << (std::ostream & os, const TicTacToeGame & ttt);

    private: 

};

std::ostream& operator << (std::ostream & os, const TicTacToeGame & ttt);