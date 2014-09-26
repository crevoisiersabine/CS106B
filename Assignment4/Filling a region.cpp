// This program simulates the operation of the paint-bucket tool.

#include <vector>
#include <iostream>
#include <string>
using namespace std;

//Struct for a point on the grid
struct pointT {
	int row, col;
};

//Enumeration type for the grid
enum pixelStateT { White, Black };

//Function declaration
void FillRegion(pointT pt, vector<vector<pixelStateT> > &screen);
void FillRegion_colour_specific(pointT pt, vector<vector<pixelStateT> > &screen, pixelStateT colour);
void Print_the_grid(vector<vector<pixelStateT> > &screen);
void Create_the_grid(vector<vector<pixelStateT> > &screen);

int main(){

	vector<vector<pixelStateT> > screen(10);

	Create_the_grid(screen);
	Print_the_grid(screen);

	//Split the screen to see difference between the two grids
	cout << "-------------------------------------------" << endl;

	//Define a point and coordinates where the user would click the graphic as not using graphics library for this assignment; if using graphics, would get the coordinates of where user clicked
	pointT chosen_point;
	chosen_point.row = 1;
	chosen_point.col = 1;

	FillRegion(chosen_point, screen);
	Print_the_grid(screen);

	return 0;
}

void FillRegion_colour_specific(pointT pt, vector<vector<pixelStateT> > &screen, pixelStateT colour){
  if(screen[pt.row][pt.col] != colour){
  	//Update the colour of that pixel
  	screen[pt.row][pt.col] = colour;
  	//Check neighbouring pixels, recursively until all are the desired colour
  	for(int i = -1; i < 2; i++){
  		for(int j = -1; j < 2; j++){
  			//Check pixel index is within the bounds of the grid
  			if(0 <= (pt.row + i) && (pt.row + i) < 10 && 0 <= (pt.row + j) && (pt.row + j) < 10){
  				pointT new_point;
  				new_point.row = pt.row + i;
				new_point.col = pt.col + j;
  				if(screen[pt.row + i][pt.col + j] != colour) {
	  				FillRegion_colour_specific(new_point, screen, colour);
	  			}
	  		}
  		}
  	}
  }
}

void FillRegion(pointT pt, vector<vector<pixelStateT> > &screen){
	if(screen[pt.row][pt.col] != Black){ FillRegion_colour_specific(pt, screen, Black); }
	else { FillRegion_colour_specific(pt, screen, White); }
}

void Create_the_grid(vector<vector<pixelStateT> > &screen){
	//Create the grid using enumerated types
	for (int i = 0; i < screen.size(); i ++){
		for (int j = 0; j < screen.size(); j++){
			//line below me to draw a pattern in the grid
			if ((i == j && i != 5) || (j == 2*i && j != 4) || (i == screen.size() / 2 && j != 4 && j != 5) || (j == 2 * (screen.size() - i) && j != 4 && j != 5) || j == 3 || (j == 5 && i != 4 && i != 5)) {
				screen[i].push_back(Black);
			}
			else {
				screen[i].push_back(White);
			}
		}
	}
}

void Print_the_grid(vector<vector<pixelStateT> > &screen){
	for (int i = 0; i < screen.size(); i ++){
		for (int j = 0; j < screen[i].size(); j++){
			cout << screen[i][j] << " ";
		}
		cout << endl;
	}
}