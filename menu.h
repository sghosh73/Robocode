#ifndef MENU_H
#define MENU_H

#define RAMP_STARTING 0
#define PARKING_STARTING 1

#define TUBE_SCORE 0
#define CENTER_SCORE 1

#define KICKSTAND 0
#define TOW 1

#define PARKING_END 0

/*
Data structure for Autonomous Program
*/

typedef struct Autonomous {

	int starting;
	int block1;
	int block2;
	int block3;

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
	eraseDisplay();

	while (!done) {

		int start_pos = PARKING_STARTING;
		nxtDisplayString(0, "Starting Position");

		if (start_pos == PARKING_STARTING)
			nxtDisplayString(2, "Parking zone");
		else 
			nxtDisplayString(2, "Ramp");

		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        start_pos = PARKING_STARTING; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        start_pos = RAMP_STARTING;
	        break;

	      case 3:
	      	eraseDisplay();
	      	a->starting = start_pos;
	    }

	    int block1 = CENTER_SCORE;
		nxtDisplayString(0, "Next Step");

		if (block1 == CENTER_SCORE)
			nxtDisplayString(2, "Center Goal");
		else 
			nxtDisplayString(2, "Tube Goal");

		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        block1 = CENTER_SCORE; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        block1 = TUBE_SCORE;
	        break;

	      case 3:
	      	eraseDisplay();
	      	a->block1 = block1;
	    }

	    int block2 = TOW;
		nxtDisplayString(0, "Next Step");

		if (block2 == TOW)
			nxtDisplayString(2, "Tow");
		else 
			nxtDisplayString(2, "Kickstand");

		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        block2 = TOW; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        block2 = KICKSTAND;
	        break;

	      case 3:
	      	eraseDisplay();
	      	a->block2 = block2;
	    }

	    int block3 = PARKING_END;
		nxtDisplayString(0, "Next Step");

		if (block3 == PARKING_END)
			nxtDisplayString(2, "Parking");
		else 
			nxtDisplayString(2, "Stop");

		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        block3 = PARKING_END; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        block3 = 0;
	        break;

	      case 3:
	      	eraseDisplay();
	      	a->block3 = block3;
	    }
	    done = true;
	}
}

#endif 