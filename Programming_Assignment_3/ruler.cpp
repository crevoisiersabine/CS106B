//This programs draws a ruler recursively 

#include <iostream>
#include <vector>
#include "graphics.h"
// #include "gevents.h"
#include "gobjects.h"
// #include "ginteractors.h"
// #include "random.h"
using namespace std;

void Wrapper_Draw_Ruler(double x, double y, double w, double h, GWindow &gw);

void DrawRuler(double x, double y, double w, double h){
	//Initialise the graphics window
	void initGraphics();

	//Add a graphics window
	GWindow gw;
	
	//Initialise a new line
	GLine *line = new GLine(x, y + h, x + w, y + h);
	//Add the line to the window
	gw.add(line);

	//Draw ruler
	Wrapper_Draw_Ruler(x, y, w, h, gw);
}

/* Main function body */
int main() {
	DrawRuler(10, 10, 100, 50);
	return 0;
}

void Wrapper_Draw_Ruler(double x, double y, double w, double h, GWindow &gw){

	if(h > 10){
		//Initialise a new line
		GLine *line = new GLine((2 * x + w) / 2, y, (2 * x + w) / 2, y + h);
		//Add the line to the window
		gw.add(line);
		//Recursively add more lines to the ruler
		Wrapper_Draw_Ruler(x, (h / 2) + y, w/2, h / 2, gw);
		Wrapper_Draw_Ruler((w / 2) + x, (h / 2) + y, w/2, h / 2, gw);
	}
}


