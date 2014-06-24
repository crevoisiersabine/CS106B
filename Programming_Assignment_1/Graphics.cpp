//This program explores an interesting phenomenon known as the "Chaos Game."

#include <iostream>
#include <vector>
#include "graphics.h"
#include "gevents.h"
#include "gobjects.h"
#include "ginteractors.h"
#include "random.h"
using namespace std;

// Start a random sequence
void Randomize();

// Initialise coordinate vector definition
typedef vector<double> Coordinates;

//Initialise a definition for a vector of GOval
typedef vector<GOval *> Circles;

//Function prototypes
void Draw_Polygon(GWindow gw, Coordinates &X, Coordinates &Y, int vertices);
void Draw_Circles(int newVertex, GWindow gw, Coordinates &X, Coordinates &Y, Circles my_circle);

/* Main function body */
int main() {

	//Initialise the graphics window
	void initGraphics();
	//Add a graphics window
	GWindow gw;

  //Choose the number of vertices for the polygon
  int vertices = 3;
	//Prompt the user to click three points on the graphics window
	cout << "Please click " << vertices <<  " points within the graphics window!" << endl;
  
  //Create two vectors; one that holds x coordinates, one that holds y coordinates based on user clicks
  Coordinates X_coord;
  Coordinates Y_coord;
  
  //Create a vector for each circle to be drawn on the canvas
  Circles my_circle;
  
  //Draw the polygon to the canvas
  Draw_Polygon(gw, X_coord, Y_coord, vertices);

  //Find a random vertex - go up to size vector X - 1 (size of X and Y vectors are identical)
  int vertexChosen = randomInteger(0, X_coord.size() - 1);

  //Draw a small filled circle around current vertex and add to the canvas
  GOval *circle = new GOval(X_coord[vertexChosen] - 5/2, Y_coord[vertexChosen] - 5/2, 5, 5);
  circle -> setFilled(true);
  my_circle.push_back(circle);
  gw.add(circle);

  //Find another random vertex different from the previous one
  int newVertex = vertexChosen;
  while(true) {
  newVertex = randomInteger(0, X_coord.size() - 1);
  if (newVertex != vertexChosen) {break; }
  }

  //Draw the patterns
  Draw_Circles(newVertex, gw, X_coord, Y_coord, my_circle);

	return 0;
}

void Draw_Polygon(GWindow gw, Coordinates &X, Coordinates &Y, int vertices){
  int counter = 0;
  //Initialise a new polygon
  GPolygon *tri = new GPolygon();
  while (true) {
    GMouseEvent e = waitForEvent(MOUSE_EVENT);
    if (e.getEventType() == MOUSE_PRESSED) {
      //Get x and y coordinates from mouse click and push to correct vector
      X.push_back(e.getX());
      Y.push_back(e.getY());
      //Increment the counter so we know when to stop listening for user clicks - determined by vertex number
      counter++;
      cout << "Hey I counted !! " << counter << endl;
      if(counter == vertices) {break; }
     }
  }

  for(int j = 0; j < X.size(); j++){
    //Add vertices to the polygon
    tri -> addVertex(X[j], Y[j]);
    cout << X[j] << " " << Y[j] << endl;
  }

  //Add tri to the canvas
  gw.add(tri);
}

void Draw_Circles(int newVertex, GWindow gw, Coordinates &X, Coordinates &Y, Circles my_circle){
  int count = 0;
  while(true){
    //Add a new GOval to the array that has its coordinates moved from the current point half the distance towards that new vertex
    my_circle.push_back(new GOval(my_circle[count]->getX() + (X[newVertex] - my_circle[count]->getX())/2 - 5/2, my_circle[count]->getY() + (Y[newVertex] - my_circle[count]->getY())/2 - 5/2, 5, 5));
    my_circle[count+1] -> setFilled(true);
    //Add the filled circles to the canvas
    gw.add(my_circle[count+1]);
    count++;
    newVertex = randomInteger(0, X.size() - 1);

    GMouseEvent e = getNextEvent();
    if (e.getEventType() == MOUSE_PRESSED) break;
  }
}


