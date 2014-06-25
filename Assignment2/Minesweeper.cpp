#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Vector definitions
typedef vector<vector<bool> > inputGrid;
typedef vector<vector<int> > outputGrid;

//Function prototype
outputGrid MakeGridOfCounts(inputGrid & bombLocations);

inputGrid createInputGrid(){
	//Set the size of input grid
	int rowSize = 6;
	int colSize = 6;
	inputGrid bombLocations(rowSize, vector<bool>(colSize));
	// Example bool grid as per assignment
	for(int i = 0; i < rowSize; i++){
		for(int j = 0; j < colSize; j++){
			bombLocations[i][j] = false;
		}
	}

	bombLocations[0][0] = bombLocations[0][5] \
	= bombLocations[1][5] = bombLocations[2][0] = bombLocations[2][1] \
	= bombLocations[2][3] = bombLocations[2][5] = bombLocations[3][0] \
	= bombLocations[4][2] = true;

	return bombLocations;
}

/* Main function body */
int main() {

	//Build the input grid as per example
	inputGrid bombLocations = createInputGrid();

	outputGrid gridOfCounts = MakeGridOfCounts(bombLocations);

	//Print the grids
	cout << "This is the input grid: " << endl;
	for(int i = 0; i < bombLocations.size(); i++){
		for(int j = 0; j < bombLocations[0].size(); j++){
			cout << bombLocations[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "This is the output grid: " << endl;
	for(int i = 0; i < gridOfCounts.size(); i++){
		for(int j = 0; j < gridOfCounts[0].size(); j++){
			cout << gridOfCounts[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

outputGrid MakeGridOfCounts(inputGrid & bombLocations){

	//Find how manny rows and columns the bool grid has
	int rows = bombLocations.size();
	int cols = bombLocations[0].size();
	//Initialise an integer grid to be the same size as the bool grid
	outputGrid gridOfCounts(rows, vector<int>(cols));
	//Populate the grid so each position is zero
	for(int i = 0; i < rows; i++){
		for(int j = 0 ; j < cols; j++){
			gridOfCounts[i][j] = 0;
		}
	}

	// Populate the grid based on the bool grid
	for(int i = 0; i < rows; i++){
		for(int j = 0 ; j < cols; j++){
			/*The 9 following if statements check for presence of bombs in the neighbouring locations to the point on grid
			and count one more bomb each time true is returned*/
			if(bombLocations[i][j] == true){
				gridOfCounts[i][j]++;
			}
			if((i != 0) && bombLocations[i - 1][j] == true){
				gridOfCounts[i][j]++;
			}
			if((j != 0) && bombLocations[i][j - 1] == true){
				gridOfCounts[i][j]++;
			}
			if((i != 0 && j != 0) && bombLocations[i - 1][j - 1] == true){
				gridOfCounts[i][j]++;
			}
			if((i != 5 && j != 5) && bombLocations[i + 1][j + 1] == true){
				gridOfCounts[i][j]++;
			}
			if((i != 5) && bombLocations[i + 1][j] == true){
				gridOfCounts[i][j]++;
			}
			if((j != 5) && bombLocations[i][j + 1] == true){
				gridOfCounts[i][j]++;
			}
			if((i != 0 && j != 5) && bombLocations[i - 1][j + 1] == true){
				gridOfCounts[i][j]++;
			}
			if((i != 5 && j != 0) && bombLocations[i + 1][j - 1] == true){
				gridOfCounts[i][j]++;
			}
		}
	}
	return gridOfCounts;
}