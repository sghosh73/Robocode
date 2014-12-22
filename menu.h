#ifndef MENU_H
#define MENU_H

/*
Data structure for Autonomous Program
*/

typedef struct Autonomous {

} Autonomous;


int getButton() 
{
	while (nNxtButtonPressed != -1) {} // Wait until nothing is pressed
	while (nNxtButtonPressed == -1) {} // Wait until the user presses something

	int button = nNxtButtonPressed; // Remember which button was pressed
	while (nNxtButtonPressed != -1) {} // Wait for them to release it again

	return button;
}


void displayOptionsMenu(Autonomous a)
{
	bool done = false;

	while (!done) {
		
	}
}

#endif 