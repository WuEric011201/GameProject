/* GomokuGame.cpp
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: This file implements all the functions for the GomokuGame Derived class. Print() will call <<. 
The overload << operator will print the board. The constructor will populate the container for game pieces. 
done() determines if the game is won by B or W. draw() determines if the game is drawn or 
not. turn() determines whose turn it is, calls prompt() and stores all the useful data of the game. 
prompt() overloads prompt() in the base class. 
*/
#include <iostream>
#include "GomokuGame.h"

using namespace std;

GomokuGame::~GomokuGame(){
}
// Constructor
GomokuGame::GomokuGame(): GameBase(gg_dimension::g_total_width, gg_dimension::g_total_width, 
    gg_dimension::g_board_width, gg_dimension::g_piece_length)
    {
        const size_t dim =gg_dimension::g_total_width;
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
    
// Insertion operation
ostream& operator << (ostream & os, const GomokuGame & gg){
    for(size_t i = 0; i < gg.height; ++i ){ // loop through 20 times i = 0-19
        if(i == gg.height-1){ // last row 
            cout << "X ";
            for(size_t j = 1; j <= gg.board_width;++j){ // display 1 - 19
                cout<< j <<" ";
            }
            break; //end the displaying 
        }

        for(size_t j = 0; j <gg.width; ++j){ // loop through 20 times j = 0 - 19
            if(j == 0 ) {
                cout << (gg_dimension::g_board_width -i) << ""; // display 19 - 1
                continue;
            }
            if(j<10){
                if(gg.position[i][j-1] == " "){ //check empty space 
                    cout.width(piece_length+1);
                    cout<< gg.position[i][j-1];
                }else{
                    cout.width(piece_length+1);
                    cout<< gg.position[i][j-1];
                }
            }else{ //when the axis displaying needs three empty space, space is adjusted as well in the board
                if(gg.position[i][j-1] == " "){ 
                    cout.width(piece_length+2);
                    cout<< gg.position[i][j-1];
                }else{
                    cout.width(piece_length+2);
                    cout<< gg.position[i][j-1];
                }
            }
           
        }
        cout << " " << endl;
    }
    return os;
}

//print the board
void GomokuGame::print(){
    cout<<*this<<endl;
}

bool GomokuGame::draw(){
    //check if someone wins
    if(this->done()){
        return false; 
    }
    // check if all nine boxes are filled
    if(num_turn == gg_dimension::g_total_pieces){
        return true;
    }
    return false;
}

bool GomokuGame::done(){
    // check row
    for(int i = 0; i <= (gg_dimension::g_total_width-2); i++){ //i from 0 to 18
        for(int j = 0; j <= (gg_dimension::g_total_width-6); j++ ){ //j from 0 to 14
            if(this->position[i][j]== " "){
                continue;
            }
            bool flag = true;
            for(size_t k = 0; k<4; ++k){ //k from 0 - 3
                if(this->position[i][j+k]!=this->position[i][j+k+1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                this->who_wins = this->position[i][j];
                return flag;  
            }
        }
    }
    //check column
    for(size_t i = 0; i <= gg_dimension::g_total_width-2; ++i){ //i from 0 to 18
        for(size_t j = 0; j <= gg_dimension::g_total_width-6; ++j ){ //j from 0 to 14
            if(this->position[j][i]== " "){
                continue;
            }
            bool flag = true;
            for(size_t k = 0; k<4; ++k){ //k from 0 - 3
                if(this->position[j+k][i]!=this->position[j+k+1][i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                this->who_wins = this->position[j][i];
                return flag;  
            }
        }
    }
//check left up to right down
    for(size_t i = 0; i <= gg_dimension::g_total_width-6; ++i){ //i from 0 to 14
        for(int j = 0; j <= gg_dimension::g_total_width-6; ++j ){ //j from 0 to 14
            if(this->position[i][j]== " "){
                continue;
            }
            bool flag = true;
            for(int k = 0; k<4; ++k){ //k from 0 - 3
                if(this->position[i+k][j+k]!=this->position[i+k+1][j+k+1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                this->who_wins = this->position[i][j];
                return flag;  
            }
        }
    }
// cout<< "check"<< endl;
//check right up to left down
    for(size_t i = 4; i <= gg_dimension::g_total_width-2; ++i){ //i from 4 to 18
        for(size_t j = 0; j <= gg_dimension::g_total_width-6; ++j){ //j from 0 to 14
            if(this->position[i][j]== " "){
                continue;
            }
            bool flag = true;
            for(int k = 0; k<4; ++k){ //k from 0 - 3
                if(this->position[i-k][j+k]!=this->position[i-k-1][j+k+1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                this->who_wins = this->position[i][j];
                return flag;  
            }
        }
    }

    return false; 
}

//prompt method
int GomokuGame::prompt(unsigned int& hor, unsigned int& ver){
    cout<< "Type quit or a valid square on the board"<< endl;
    string input; 
    cin >> input;  //request user input
    if(input == "quit"){
        return user_input::quit; 
    }
    int pos = input.find(","); //find the index
    input[pos] = ' '; //replace ","" with " "
    istringstream iss (input);
    unsigned int hor_temp,ver_temp;
    // Check conditions for not correct user inputs
    if (!(iss >> hor_temp) || !(iss >> ver_temp)){
        cout << "Cannot extract correct dimensions. Try again."<< endl;
        return user_input::wrong_input_format; //2
    }else if (hor_temp<1 || hor_temp>gg_dimension::g_board_width ||ver_temp <1 || ver_temp>gg_dimension::g_board_width){
        cout << "The dimension is out of bounds. Try again."<< endl;
        return user_input::wrong_dim; //3
    }else if(!(position[gg_dimension::g_board_width-ver_temp][hor_temp-1] == " ")){ //test empty squre
        cout << "The input is not on a empty square. Try again."<< endl;
        return user_input::not_empty; //4
    }else{
        hor = gg_dimension::g_board_width-ver_temp; //adjust hor and ver for the 2d array
        // since the 2d array index starts counting from the top to bottom
        ver =  hor_temp-1;
    }
        return user_input::success; 
}

int GomokuGame::turn(){
    //set player 
    if(whos_turn){
        this->current_player = "B";
        cout<< "It is Black stone's turn"<< endl;
    }else{
        cout<< "It is White stone's turn"<<endl;
        this->current_player = "W";
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
            this->position[hor][ver] = 'B'; //store the game move, hor and ver are the real index for the 2d array
        }else{
            this->position[hor][ver] = 'W';
        }
        num_turn += 1; 
    }

    cout << *this <<endl; //display board
    cout <<"\n" << endl; //empty line
    //pieces played by this player
    cout << "Player "<< this->current_player <<": "<< ver+1 <<", "<<gg_dimension::g_board_width-hor;

    // display the previous moves and store the current move
    if(whos_turn){ //B's turn; storeO stores B 
        for(int i = 0; i < storeO.size(); i++){
            // in order to print the index, we need to conver the 2d array index back to the user input index
            cout<< "; "<<storeO[i].second+1<<", " << gg_dimension::g_board_width - storeO[i].first ; 
        }
        pair<int, int> B (hor, ver); //current move pair
        storeO.push_back(B);
    }else{ //storeX stores W
        for(int i = 0; i < storeX.size(); i++){
            cout<< "; "<<storeX[i].second+1<<", " << gg_dimension::g_board_width - storeX[i].first ;
        }
        pair<int, int> W (hor, ver);
        storeX.push_back(W);
    }

    cout<<""<< endl;
    // swap the users
    whos_turn = !whos_turn;
    return user_input:: success;
}
