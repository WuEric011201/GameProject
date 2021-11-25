/* GameBase.h
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: Declaration for all the functions and member variables for the Game base class
*/

#pragma once
#include "helper.h"

class GameBase{
    public:
    //this function will prints the game board and repeatedly calls turn() done() and draw()
    virtual int play();

    static GameBase* set_game(int num, char* arr[]);
    virtual ~GameBase();

    protected:     
    // constructor
    GameBase(int width_, int height_, int board_width_, int piece_length_);
 
    virtual void print() = 0;
    virtual bool done() = 0;
    virtual bool draw() = 0;
    virtual int turn() = 0;

    // This function checks user inputs and stores it
    virtual int prompt(unsigned int & hor, unsigned int& ver);

    // array of pairs to store the game moves
    std::vector<std::pair<int,int> >storeO;
    std::vector<std::pair<int,int> >storeX;
    // remembers whose turn it is
    bool whos_turn; 
    // remembers the current player
    std::string current_player;
    // remember who wins
    std::string who_wins;
    // remember the number of turns
    int num_turn ;
    int width; // total width and height
    int height; 
    int board_width; // actual board's width and height

    // 2-D array to store the game board of the game 
    std::string** position;

    // longest display string length
    int piece_length;
};