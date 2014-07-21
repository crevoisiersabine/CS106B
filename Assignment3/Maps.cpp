// This program will store entries in an address book

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <typeinfo>
using namespace std;

struct pointT {
	int x, y;
};

struct cityT {
	string name;
	pointT coordinates;
};

typedef map<string, cityT> geography;
typedef vector<cityT> cities;

void Create_vector(cities &list_Of_Cities){
	
	cityT Paris = {"Paris", {15, 12}};
	cityT Glasgow = {"Glasgow", {20, 10}};
	cityT ChiangMai = {"Chiang Mai", {100, 25}};

	list_Of_Cities.push_back(Paris);
	list_Of_Cities.push_back(Glasgow);
	list_Of_Cities.push_back(ChiangMai);
}

void Make_Map(cities &list_Of_Cities, geography &Maps){
	for(cities::iterator itr=list_Of_Cities.begin(); itr!=list_Of_Cities.end();++itr){
		// cout << endl;
		// cout << "The city is " << itr->name << " and its coordinates are given by: \n" << "x is: " << itr->coordinates.x << " and y is: " << itr->coordinates.y << endl;
		// cout << endl;
		// cout << typeid(*itr).name() << endl;
		Maps[to_string(itr->coordinates.x) + "-" + to_string(itr->coordinates.y)] = *itr;
	}
}

void Print_Map(geography &Maps){

	for(geography::iterator itr=Maps.begin(); itr!=Maps.end();++itr){
		cout << "key is " << itr->first << " and value is: \nCity: " << itr->second.name << " of Coordinates: " << itr->second.coordinates.x << ", " << itr->second.coordinates.y << endl;
	}
}


int main(){

	geography Maps;
	cities list_Of_Cities;
	Create_vector(list_Of_Cities);
	Make_Map(list_Of_Cities, Maps);
	Print_Map(Maps);

	return 0;

}