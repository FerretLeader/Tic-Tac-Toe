/*******************************************************
/ Mame: main.cpp
/ Creator: Michael Lee Brummitt
/ Purpose: Main file for the TicTacToe program. This is
/ the file that you should compile
/ Version: 0.5
*******************************************************/

using namespace std;

#include "myGrid.h"
#include"math.h"
#include <iostream>

void mainMenu(myGrid *board);
void gridTestMenu(myGrid *board);
void twoPlayerGame(myGrid *board);
char testForWinner(myGrid *board);
bool testIsFull(myGrid *board);


/*******************************************************
/ Mame: main()
/ Creator: Michael Lee Brummitt
/ Purpose: Main function for the program.
*******************************************************/
int main(){
	myGrid *board = new myGrid(3, 3);
	
	//call the main menu function
	mainMenu(board);

	delete board;

	return 0;
}

/*******************************************************
/ Mame: mainMenu()
/ Creator: Michael Lee Brummitt
/ Purpose: Prints the main menu to the console and gets
/ input from the user.
*******************************************************/
void mainMenu(myGrid *board){
	bool keepLooping = true;
	char input;
	
	while(keepLooping){
		cout << "Please choose an option:\n\n";
			
		cout << "a. Test the grid\n";
		cout << "b. Start a game of Tic Tac Toe (2 players)\n";
		cout << "e. Exit\n";
		cout << "\n";
		
		cin >> input;
		
		cout << "\n";
		
		switch(input){
			case 'a':
				gridTestMenu(board);
				break;
			case 'b':
				twoPlayerGame(board);
				break;
			case 'e':
				keepLooping = false;
				break;
			default:
				cout << "Invalid input.\n\n";
				break;
		}
	}
}

/*******************************************************
/ Mame: gridTestMenu()
/ Creator: Michael Lee Brummitt
/ Purpose: Prints the grid test menu to the console and
/ recieves user input
*******************************************************/
void gridTestMenu(myGrid *board){
	bool keepLooping = true;
	char input;
	
	while(keepLooping){
		cout << "Please choose an option:\n\n";
		
		cout << "a. Fill grid with default test variables\n";
		cout << "b. Print the test variables\n";
		cout << "e. Exit to main menu\n";
		cout << "\n";
		
		cin >> input;
		
		cout << "\n";
		switch(input){
			case 'a':
				for(int i = 0; i < board->getHeight(); i++){
					for(int j = 0; j < board->getWidth(); j++){
						board->setGridElement(j, i, '0'+ (j+(i*board->getWidth())) );
					}
				}
				break;
			case 'b':
				for(int i = 0; i < board->getHeight(); i++){
					for(int j = 0; j < board->getWidth(); j++){
						cout << board->getGridElement(j, i);
						cout << " ";
					}
					cout << "\n";
				}
				break;
			case 'e':
				keepLooping = false;
				
				break;
		}
	}
}

/*******************************************************
/ Mame: gridTestMenu()
/ Creator: Michael Lee Brummitt
/ Purpose: Starts a game for two players
*******************************************************/
void twoPlayerGame(myGrid *board){
	bool player = 1;
	int x;
	int y;
	
	// set every character to an integer
	for(int i = 0; i < board->getHeight(); i++){
		for(int j = 0; j < board->getWidth(); j++){
			board->setGridElement(j, i, '0'+ (j+(i*board->getWidth())) );
		}
	}
	
	//while there is no winner and the board is not full
	while(testForWinner(board) == '\0' && testIsFull(board) == false){
		//print the board
		for(int i = 0; i < board->getHeight(); i++){
			for(int j = 0; j < board->getWidth(); j++){
				cout << board->getGridElement(j, i);
				cout << " ";
			}
			cout << "\n";
		}
		
		//print the current player
		switch(player){
			case 1:
				cout << "Player x\n";
				break;
			default:
				cout << "player o\n";
				break;
		}
		
		//get the input
		cout << "\n";
		cout << "Choose a valid x coordinent (" << 0 << " to " << board->getWidth()-1 << "): ";
		cin >> x;
		cout << "\n";
		cout << "Choose a valid y coordinent (" << 0 << " to " << board->getHeight()-1 << "): ";
		cin >> y;
		
		if(board->getGridElement(x, y) != 'x' && board->getGridElement(x, y) != 'o'){
			//print the current player
			switch(player){
				case 1:
					board->setGridElement(x, y, 'x');
					break;
				default:
					board->setGridElement(x, y, 'o');
					break;
			}
			
			//switch the player
			player = !player;
		}else{
			cout << "ERROR: Invalid input!\n";
		}
	}
}

/*******************************************************
/ Mame: gridTestMenu()
/ Creator: Michael Lee Brummitt
/ Purpose: Checks to see if a player has won the game
/ yet
*******************************************************/
char testForWinner(myGrid *board){
	char winner = '\0';
	char winning;
	int i = 0;
	int j = 0;
	
	//check vertically
	while(i < board->getWidth()){
		winning = board->getGridElement(j, i);
		while(winning != '\0' && j < board->getHeight()){
			if(winning != board->getGridElement(i,j)){
				winning = '\0';
			}
			j++;
		}
		i++;
	}
	
	return winner;
}

/*******************************************************
/ Mame: gridTestMenu()
/ Creator: Michael Lee Brummitt
/ Purpose: checks to see if the board is full yet
*******************************************************/
bool testIsFull(myGrid *board){
	bool isFull = true;
	int i = 0;
	int j = 0;
	
	//check if there is any empry space
	while(i < board -> getHeight()){
		while(j < board -> getWidth()){
			if(board->getGridElement(j,i) != 'x' && board->getGridElement(j,i) != 'y'){
				isFull = false;
			}
			j++;
		}
		j = 0;
		i++;
	}
	
	return isFull;
}
