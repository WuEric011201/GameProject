/* Gomoku.h
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: Declaration for all the functions and member variables for the Gomoku derived class
*/

#pragma once
#include "GameBase.h"

//Declaration of the Game Class
class GomokuGame: public GameBase{
    public:
    // Constructor
    GomokuGame();
    // Destructor
    ~GomokuGame();
    // Print the board
    virtual void print();
    //This function determines if the game is won by X or O
    virtual bool done();
    // This function determines if the game is drawn or not
    virtual bool draw();
    // This method determines whose turn it is, calls prompt() and stores all the useful data 
    // of the game. It will also print the board if a move is made. 
    virtual int turn();
    // This function checks user inputs and stores it
    virtual int prompt(unsigned int & hor, unsigned int& ver);

    friend std::ostream& operator << (std::ostream & os, const GomokuGame & gg);
    private: 

};

std::ostream& operator << (std::ostream & os, const GomokuGame & gg);