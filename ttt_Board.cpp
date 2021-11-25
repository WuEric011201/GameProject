/* ttt_Board.cpp
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose:  This file implements all the functions for the TicTacToe derived class. print wil call the << operator. 
The overload << operator will print the board. The constructor will populate the container for game pieces. 
done() determines if the game is won by X or O. draw() determines if the game is drawn or 
not. turn() determines whose turn it is, calls prompt() and stores all the useful data of the game. 
The idea of the construction body is from: https://stackoverflow.com/questions/1946830/multidimensional-variable-size-array-in-c
*/
#include <iostream>
#include "ttt_Board.h"

using namespace std;

//print the board
void TicTacToeGame::print(){
    cout<<*this<<endl;
}


ostream& operator << (ostream & os, const TicTacToeGame & tictactoe_game){
    for(int i = 0; i <= ttt_dimension::total_width; ++i ){ // loop through 6 times i = 0-5
        if(i == ttt_dimension::total_width){ // last row 
            cout << "  ";
            for(int j = 0; j <= ttt_dimension::total_width-1;++j){ // display 0 - 4 
                cout.width(piece_length+1);
                cout<< j ;
            }
            break; //end the displaying 
        }

        for(int j = 0; j <=ttt_dimension::total_width; ++j){ // loop through 6 times j = 0-5
            if(j == 0 ) {
                cout << (4-i) << " "; // display 4 - 0
                continue;
            }
            if(tictactoe_game.position[i][j-1] == " "){ //check empty space 
                cout.width(piece_length+1);
                cout<< tictactoe_game.position[i][j-1];
            }else{
                cout.width(piece_length+1);
                cout<< tictactoe_game.position[i][j-1];
            }
        }
        cout << " "<< endl;
    }
    return os;
}

//Constructor of the derived class
TicTacToeGame::TicTacToeGame(): GameBase(ttt_dimension::total_width, ttt_dimension::total_width, 
    ttt_dimension::board_width, ttt_dimension::piece_length){
        const size_t dim =ttt_dimension::total_width;
        position = new string*[dim]; // each element is a pointer to an array.
        for(size_t i = 0; i < dim; ++i){
            position[i] = new string[dim]; // build rows
        }
        for(size_t i = 0; i < dim; ++i){
            for(size_t j = 0; j < dim; ++j){
                position[i][j] = " ";
            }
        }
    }     

// Destructor
TicTacToeGame::~TicTacToeGame(){
}
 
bool TicTacToeGame::done(){
    // check row
    for(int i = 1; i <= this->height-2; i++){
        if(!(this->position[i][1]== " ") && this->position[i][1]==this->position[i][2]
            && this->position[i][2]==this->position[i][3]){
           this->who_wins = this->position[i][1];
           return true;  
        }
    }
    //check column
    for(int j = 1; j <= this->width-2; j++){
        if(!(this->position[1][j] == " ")  && this->position[1][j]==this->position[2][j]
            && this->position[2][j] == this->position[3][j]){
           this->who_wins = this->position[1][j];
           return true; 
        }
    }
    //check two diagonals
    if(!(this->position[1][1]== " ") && this->position[1][1]==this->position[2][2]
        && this->position[2][2] == this->position[3][3]){
        this->who_wins = this->position[1][1];
        return true; 
    }
    if(!(this->position[3][1]== " ")  &&this->position[3][1]== this->position[2][2]
        && this->position[2][2] == this->position[1][3]){
        this->who_wins = this->position[3][1];
        return true;
    }
    return false; 
}

bool TicTacToeGame::draw(){
    //check if someone wins
    if(this->done()){
        return false; 
    }
    bool flag = false; 
    // check if all nine boxes are filled
    if(num_turn == ttt_dimension::total_pieces){
        flag = true;
    }
    return flag;
}


int TicTacToeGame::turn(){
    //set player 
    if(whos_turn){
        this->current_player = "O";
        cout<< "It is player O's turn"<< endl;
    }else{
        cout<< "It is player X's turn"<<endl;
        this->current_player = "X";
    }

    unsigned int hor; 
    unsigned int ver; 
    int result = prompt(hor, ver); // call prompt()
    while(result != user_input::success && result != user_input::quit){
        result = prompt(hor, ver);
    }

    //check if the user is quitting
    if(result == user_input::quit){
        return user_input::quit;
    }else{
        if(whos_turn){
            this->position[hor][ver] = 'O'; //store the game move
        }else{
            this->position[hor][ver] = 'X';
        }
        num_turn += 1; 
    }

    cout << *this <<endl; //display board
    cout <<"\n" << endl; //empty line
    //pieces played by this player
    cout << "Player "<< this->current_player <<": "<< ver <<", "<<4-hor;

    // display the previous moves and store the current move
    if(whos_turn){ //O's turn
        for(int i = 0; i < storeO.size(); i++){
            cout<< "; "<<storeO[i].second<<", " << 4 - storeO[i].first ;
        }
        pair<int, int> O (hor, ver); //current move pair
        storeO.push_back(O);
    }else{
        for(int i = 0; i < storeX.size(); i++){
            cout<< "; "<<storeX[i].second<<", " << 4 - storeX[i].first ;
        }
        pair<int, int> X (hor, ver);
        storeX.push_back(X);
    }

    cout<<""<< endl;
    // swap the users
    whos_turn = !whos_turn;
    return user_input:: success;
}


