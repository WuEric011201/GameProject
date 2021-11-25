/* Usage_Message.cpp
Author: Tong Wu
Email: eric.w@wustl.edu

Purpose: Print out the helpful message about how the program runs and returns the value of the 
wrong number of commands. 

*/

#include <iostream>
#include "ttt_Board.h"

using namespace std;

int usageMessage(char * c_string, string message1){
    // prints out message about which file to open
    cout<< "usage: "<< c_string<< message1 << endl; 
    return variables::wrong_number_of_commands; //-1
}

