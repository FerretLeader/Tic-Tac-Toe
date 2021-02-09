/*******************************************************
/ Mame: myGrid.h
/ Creator: Michael Lee Brummitt
/ Purpose: This file contains a myGrid class which will
/ allow you to create a grid with a size that you can
/ define.
/ Version: 1.0
*******************************************************/

#include <iostream>

/*******************************************************
/ Mame: myGrid
/ Creator: Michael Lee Brummitt
/ Purpose: Allows the user to create a grid when given
/ a width and a height.
*******************************************************/
class myGrid{
	private:
		int width;
		int height;
		char ** grid;
	public:
		/*******************************************************
		/ Mame: myGrid(int newWidth, int newHeight)
		/ Creator: Michael Lee Brummitt
		/ Purpose: Creates a new grid using a width newWidth and
		/ a height newHeight. both newWidth and newHeight should
		/ be of type int.
		*******************************************************/
		myGrid(int newWidth, int newHeight){
			width = newWidth;
			height = newHeight;
			
			grid = new char*[width];
			for(int i = 0; i < height; i++){
				grid[i] = new char[height];
			}	
		}
		
		/*******************************************************
		/ Mame: getWidth()
		/ Creator: Michael Lee Brummitt
		/ Purpose: Accessor to return the width of a myGrid
		*******************************************************/
		int getWidth(){
			return width;
		}
		
		/*******************************************************
		/ Mame: getHeight()
		/ Creator: Michael Lee Brummitt
		/ Purpose: Accessor to return the height of a myGrid
		*******************************************************/
		int getHeight(){
			return height;
		}
		
		/*******************************************************
		/ Mame: getGridElement(int x, int y)
		/ Creator: Michael Lee Brummitt
		/ Purpose: Accessor to return an element of the grid
		/ given a width position x and a height position y
		*******************************************************/
		char getGridElement(int x, int y){
			char returnMe;
			
			if(x < width && y < height){
				returnMe = grid[x][y];
			}else{
				cout << "ERROR: Invalid element!\n";
			}
			
			return returnMe;
		}
		
		/*******************************************************
		/ Mame: setGridElement(int x, int y)
		/ Creator: Michael Lee Brummitt
		/ Purpose: Allows the user to set an element in the grid
		/ to a character value. Returns a boolean value based on
		/ success.
		*******************************************************/
		bool setGridElement(int x, int y, char value){
			bool returnMe;
			
			if(x < width && y < height){
				grid[x][y] = value;
				returnMe = true;
			}else{
				cout << "ERROR: Invalid element!\n";
				returnMe = false;
			}
			
			return returnMe;
		}
		
		/*******************************************************
		/ Mame: ~myGrid()
		/ Creator: Michael Lee Brummitt
		/ Purpose: Destructor designed to clean up a myGrid 
		/ before the object is removed.
		/ NOTE: This was a huge pain to fix, and in the end,
		/ I'm not entirely sure what fixed it. If you get 
		/ strange return values when removing a myGrid, check
		/ here.
		*******************************************************/
		~myGrid(){
			for(int i = 0; i < height; i++){
				delete [] grid[i];
			}
			delete [] grid;
		}
};
