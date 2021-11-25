/* helper.h
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: Declaration for all the helper enums and functions
*/
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>

//enumeration for the different variables that are relevant to my program
enum variables {Lab4= 0, exact_arg = 2, wrong_number_of_commands = -1, bad_alloc_enum = 30, other_error = 40};
//enumeration for the dimension for tictactoe
enum ttt_dimension {total_width = 5, board_width = 3, total_pieces = 9, piece_length = 1};

//enumeration for the dimension for gomoku
enum gg_dimension {g_total_width = 20, g_board_width = 19, g_total_pieces = 361, g_piece_length = 1};
//enumeration for the return values of different user inputs
enum user_input {quit = 1, success = 0, wrong_input_format = 2, wrong_dim= 3, not_empty = 4 };
//enumeration for the final outcomes
enum game_result {wins = 0, draw = 10, quit_ = 20};

//Prints out direction to run the program if the wrong number of command line arguments
int usageMessage(char * c_string, std::string message1);

// the information to convey to the user what the command line arguments should look like
extern const std::string message;