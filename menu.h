#ifndef MENU_H
#define MENU_H

/*
Constants for autonomous
*/

#define RAMP_STARTING 0
#define PARKING_STARTING 1

#define TUBE_SCORE 0
#define CENTER_SCORE 1

#define KICKSTAND 0
#define TOW 1

#define PARKING_END 1



int getButton()
{
	while (nNxtButtonPressed != -1) {} // Wait until nothing is pressed
	while (nNxtButtonPressed == -1) {} // Wait until the user presses something

	int button = nNxtButtonPressed; // Remember which button was pressed
	while (nNxtButtonPressed != -1) {} // Wait for them to release it again

	return button;
}


void displayOptionsMenu(int &instructions)
{
	bool done = false;
	eraseDisplay();

	//select starting positions
	while (!done) {
		int start_pos = PARKING_STARTING;
		nxtDisplayTextLine(0, "Starting position");
		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        start_pos = PARKING_STARTING; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        start_pos = RAMP_STARTING;
	        break;

	      case 3:
	      	eraseDisplay();
	      	instructions[0] = start_pos;
	      	done = true;
	    }

		if (start_pos == PARKING_STARTING) {
			nxtDisplayTextLine(2, "Parking zone");
		}
		else if (start_pos == RAMP_STARTING){
			nxtDisplayTextLine(2, "Ramp");
		}
	}

		done = false;
    eraseDisplay();

    //select next step
	 while (!done) {
	   int block1 = CENTER_SCORE;
			nxtDisplayTextLine(0, "Next Step");
		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        block1 = CENTER_SCORE; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        block1 = TUBE_SCORE;
	        break;

	      case 3:
	      	eraseDisplay();
	      	done = true;
	      	instructions[1] = block1;
	    }

		if (block1 == CENTER_SCORE)
			nxtDisplayTextLine(2, "Center Goal");
		else if (block1 == TUBE_SCORE)
			nxtDisplayTextLine(2, "Tube Goal");
	}
			done = false;
			eraseDisplay();

	   //select next step
	   while (!done) {
	     int block2 = 0;
		nxtDisplayTextLine(0, "Next Step 2");
		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        block2 = TOW; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        block2 = KICKSTAND;
	        break;

	      case 3:
	      	eraseDisplay();
	      	done = true;
	      	instructions[2] = block2;
	    }
	    if (block2 == TOW){
			nxtDisplayTextLine(2, "Tow");
			}
		else if (block2 == KICKSTAND) {
			nxtDisplayTextLine(2, "Kickstand");
		}
}
			done = false;
	    eraseDisplay();

	 //select next step
	 while (!done) {
	    int block3 = PARKING_END;
		nxtDisplayTextLine(0, "Final Step");

		switch (getButton()) {  // Get a button
	      case 1: // Right arrow button
	        block3 = PARKING_END; // Increase by a second
	        break;

	      case 2: // Left arrow button
	        block3 = 0;
	        break;

	      case 3:
	      	eraseDisplay();
	      	done = true;
	      	instructions[3] = block3;
	    }
	    	if (block3 == PARKING_END)
			nxtDisplayTextLine(2, "Parking");
		else if (block3 == 0)
			nxtDisplayTextLine(2, "Stop");

	}
	    done = true;
}

#endif
