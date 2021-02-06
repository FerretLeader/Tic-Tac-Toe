/*******************************************************
/ Mame: myGrid.h
/ Creator: Michael Lee Brummitt
/ Purpose: This file contains a myGrid class which will
/ allow you to create a grid with a size that you can
/ define.
/ Version: 0.2
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
		int ** grid;
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
			
			grid = new int*[width];
			for(int i = 0; i < height; i++){
				grid[i] = new int[height];
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
		int getGridElement(int x, int y){
			int returnMe;
			
			if(x < width && y < height){
				returnMe = grid[x][y];
			}else{
				cout << "ERROR: Invalid element!";
			}
			
			return returnMe;
		}
		
		/*******************************************************
		/ Mame: setGridElement(int x, int y)
		/ Creator: Michael Lee Brummitt
		/ Purpose: Allows the user to set an element in the grid
		/ to an integer value. Returns a boolean value based on
		/ success.
		*******************************************************/
		bool setGridElement(int x, int y, int value){
			int returnMe;
			
			if(x < width && y < height){
				grid[x][y] = value;
				returnMe = true;
			}else{
				cout << "ERROR: Invalid element!";
				returnMe = false;
			}
			
			return returnMe;
		}
		
		/*******************************************************
		/ Mame: ~myGrid()
		/ Creator: Michael Lee Brummitt
		/ Purpose: Destructor designed to clean up a myGrid 
		/ before the object is removed.
		*******************************************************/
		~myGrid(){
			
		}
};
