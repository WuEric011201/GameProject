Authors: Tong Wu
Emails: eric.w@wustl.edu
CSE 332S - Lab 4

Nico completed the first part and debugged for that part. 
Tong implemented the GomokuGame class and finished all the debug. 

A. This program can only function if two command line arguments were passed, in which the second 
      argument is "TicTacToe" or "Gomoku". The program then:
      1. checks the command line arguments
      2. creates an instance of the TicTacToeGame or GomokuGame class based on the input argument
      3. calls the play function and returns its return value or catch any error returns

B. Possible program return values:
      Enums for theses can be found in helper.h
            0 - success (someone wins)
            10 - the game is drawn
            20 - the game is quit
            30 - There is bad allocation
            40 - There is any other un-identified eror cause the program to crash
            255 - the wrong number and wrong content of commands are passed in

C. Enumerations for program parameters and the general outcome of the program can be found in helper.h 
      All the declarations of the TicTacToeGame class can be found in ttt_Board.h. 
      All the declarations of the GomokuGame class can be found in GomokuGame.h. 
      ttt_Board.cpp will implement all functions in the TicTacToeGame class. 
      GomokuGame.cpp will implement all functions in the GomokuGame class. 

D. Errors encountered through debugging:
error 1: Linker error
Solution: GameBase* set_game(int c, char* arr[]) should be GameBase* GameBase::set_game(int c, char* arr[]){
      in order to scope into the GameBase class. 

error 2: ./Lab4 tictactoe
4        
3            
2            
zsh: segmentation fault  ./Lab4 tictactoe
I need to dinnamically allocate the container since its size is changing. 
error 3: 
4   
3   
2  O  
1   
0   
  0 1 2 3 4 

The cout.width will be modified define content go after it to display the right space. 

error: Lab4(65723,0x10a89ae00) malloc: *** error for object 0x7fcd9fd05bf8: pointer being freed was not allocated
Lab4(65723,0x10a89ae00) malloc: *** set a breakpoint in malloc_error_break to debug
zsh: abort      ./Lab4 TicTacToe

In the destructor, I had:    
for(size_t i = 0; i < ttt_dimension::total_width ; ++i){
      delete position[i];
}
delete position;
I thought that the 2d array I allocated the heap needed to be cleaned up, but actually the shared_ptr will take 
care of cleaning all the member variables allocated in the heap. 

E. Trials
      Trial 1-3: Command./Lab4 TicTacToe
Through each trial, I tested to win from forming diagonal, horizontal and verticle three pieces in a row. And in 
each case, the program terminated correctly and showed correctly who won the game. 
      errorlevel test: echo $?
      output: 0 
This case is expected since all the functions went as I programged and error level is 0. 

      Trial 4-7: Commands: ./Lab4 Gomoku
In these four trials, I tested four winning cases of Gomoku and the game terminated correctlly and showed B or W 
won the game.
      errorlevel test: echo $?
      output: 0 
This case is expected since all the functions went as I programged and error level is 0. 

      Trial 8-9: Commands: ./Lab4 ; ./Lab4 TicTacToe
In these two trials, I tested ill-formed input cases and the program correctly prompt me again when 
ill-formed pieces are received until quit or right formed pieces are formed. 
Type quit or a valid square on the board
2,2
The input is not on a empty square. Try again.
Type quit or a valid square on the board
0,0
The dimension is out of bounds. Try again.
Type quit or a valid square on the board
qw??
Cannot extract correct dimensions. Try again.
Type quit or a valid square on the board
quit
1 turns were made and the game is quit. 
      errorlevel test: echo $?
      output: 20
This case is expected since the outcomes and error messages are displayed as programed. 


      Trial 10:  ./Lab4 TicTacToe  
In this case, I tried to draw the game. The final output is as followed before the program 
terminated: 
4            
3    X O O   
2    O X X   
1    O X O   
0            
   0 1 2 3 4


Player O: 1, 2; 1, 1; 3, 3; 2, 3; 3, 1
9 turns were made and the game is draw. 
      errorlevel test: echo $?
      output: 10
This case is expected since the game pieces are displayed at the right spot and the final 
outcome and error messages are expected. 

      Trial 11: Commands: ./Lab4 TicTacT...
In this case, I tested wrong input arguments. 
usage: ./Lab3can only take in two command line arguments: one being the program name, one being 'TicTacToe' 
      ./Lab4 TicTacT asd  ads
usage: ./Lab3can only take in two command line arguments: one being the program name, one being 'TicTacToe' 
      echo $?          
255
      
I tried to pass in wrong numbers and wrong content of command lines and the results and 
error messages are expected.


. Extra Credit: 
      TODO