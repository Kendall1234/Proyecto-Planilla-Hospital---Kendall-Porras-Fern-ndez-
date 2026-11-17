#include<iostream>
#include "InterfazMenu.h"
using namespace std;

int main (int argc, char *argv[]) {
	InterfazMenu* menu = new InterfazMenu();
	menu->iniciar();
	delete menu;
	
	return 0;
}
