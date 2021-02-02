/*******************************************************
/ Mame: main.cpp
/ Creator: Michael Lee Brummitt
/ Purpose: Main file for the TicTacToe program. This is
/ the file that you should compile
/ Version: 0.2
*******************************************************/

using namespace std;

#include "myGrid.h"
#include <iostream>

bool mainMenu(myGrid board);
bool gridTestMenu(myGrid board);


/*******************************************************
/ Mame: main()
/ Creator: Michael Lee Brummitt
/ Purpose: Main function for the program.
*******************************************************/
int main(){
	myGrid board = myGrid(3, 3);
	
	// loop until it is time to exit
	while (mainMenu(board)){
		// Do nothing
	}
	
	return 0;
}

/*******************************************************
/ Mame: mainMenu()
/ Creator: Michael Lee Brummitt
/ Purpose: Prints the main menu to the console and gets
/ input from the user.
*******************************************************/
bool mainMenu(myGrid board){
	bool keepLooping = true;
	char input;
	
	cout << "Please choose an option:\n\n";
		
	cout << "a. Test the grid\n";
	cout << "e. Exit\n";
	cout << "\n";
	
	cin >> input;
	
	cout << "\n";
	
	switch(input){
		case 'a':
			while(gridTestMenu(board)){
				// Do nothing
			}
			break;
		case 'e':
			keepLooping = false;
			break;
		default:
			cout << "Invalid input.\n\n";
			break;
	}
	
	return keepLooping;
}

/*******************************************************
/ Mame: gridTestMenu()
/ Creator: Michael Lee Brummitt
/ Purpose: Prints the grid test menu to the console and
/ recieves user input
*******************************************************/
bool gridTestMenu(myGrid board){
	bool keepLooping = true;
	char input;
	
	cout << "Please choose an option:\n\n";
	
	
}

