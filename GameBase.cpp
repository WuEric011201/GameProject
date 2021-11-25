/* GameBase.cpp
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: This file implements all the functions for the game base class. Specifically, set_game() dinamically 
allocate the derived game class. the constructor will set the parameter of the basics of the game. play() 
will prints the game board and repeatedly calls turn() done() and draw(). It will also print the board if 
a move is made. prompt()  checks user inputs and stores it. 
*/

#include "GameBase.h"
#include "ttt_Board.h"
#include "GomokuGame.h"

using namespace std;

GameBase::~GameBase(){}

GameBase* GameBase::set_game(int c, char* arr[]){
    
    if(c == variables::exact_arg){
        if(strcmp( arr[1], "TicTacToe") == 0 ){
            TicTacToeGame* ttt_pointer;
            ttt_pointer = new TicTacToeGame();
            return ttt_pointer;  //return the address of the obj
        }else if(strcmp( arr[1], "Gomoku") == 0 ){
            GomokuGame* gg_pointer;
            gg_pointer = new GomokuGame();
            return gg_pointer;  
        }
    }
    return NULL; //no obj created, return a singular pointer
}

// Constructor of base class
GameBase::GameBase(int width_, int height_, int board_width_, int piece_length_): whos_turn(true), num_turn(0), width(width_),
    height(height_), board_width(board_width_), piece_length(piece_length_)
    { }

//play method
int GameBase::play(){
    int result ;
    bool flag = true;
    // print the board
    this->print();

    while(flag){ 
        int a = this->turn();
        
        // Check if the game is won, drawn or quit
        if(this->done()){
            cout<< this->who_wins<< " wins the game" <<endl;
            result = game_result::wins; //0
            flag = false;
        }else if(this->draw()){
            cout<< this->num_turn<< " turns were made and the game is draw. "<< endl;
            result =  game_result::draw; //10
            flag = false;
        }else if(a == user_input::quit){
            cout<< this->num_turn<< " turns were made and the game is quit. "<< endl;
            result =  game_result::quit_; //20
            flag = false;
        }
    }
    return result; 
}

//prompt method
int GameBase::prompt(unsigned int& hor, unsigned int& ver){
    cout<< "Type quit or a valid square on the board"<< endl;
    string input; 
    cin >> input;  //request user input
    if(input == "quit"){
        return user_input::quit; 
    }

    input.replace(1, 1, " "); //replace ","" with " "
    istringstream iss (input);
    unsigned int hor_temp,ver_temp;
    // Check conditions for not correct user inputs
    if (!(iss >> hor_temp) || !(iss >> ver_temp)){
        cout << "Cannot extract correct dimensions. Try again."<< endl;
        return user_input::wrong_input_format; //2
    }else if (hor_temp<1 || hor_temp>ttt_dimension::board_width ||ver_temp <1|| ver_temp>ttt_dimension::board_width){
        cout << "The dimension is out of bounds. Try again."<< endl;
        return user_input::wrong_dim; //3
    }else if(!(position[4-ver_temp][(hor_temp)] == " ")){
        cout << "The input is not on a empty square. Try again."<< endl;
        return user_input::not_empty; //4
    }else{
        hor = 4 - ver_temp ; //adjust hor and ver for the 2d array
        // since the 2d array index starts counting from the top to bottom
        ver =  hor_temp;
    }
    return user_input::success; 
}