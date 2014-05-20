#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface()
{
	testVar=0;

}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);

	switch(key)
	{
		case 'a':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->toggleSomething();
			break;
		}
	}
}

void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *mainPanel= addPanel("Controls", 0);
	GLUI_Panel *lightPanel = addPanelToPanel(mainPanel, "Lights", 1);
	GLUI_Panel *clockPanel = addPanelToPanel(mainPanel, "Clock", 1);
	addCheckboxToPanel(lightPanel, "Light 0:", &(((LightingScene*) scene)->_light0), 1);
	addCheckboxToPanel(lightPanel, "Light 1:", &(((LightingScene*) scene)->_light1), 2);
	addCheckboxToPanel(lightPanel, "Light 2:", &(((LightingScene*) scene)->_light2), 3);
	addCheckboxToPanel(lightPanel, "Light 3:", &(((LightingScene*) scene)->_light3), 4);
	addColumn();
	addButtonToPanel(clockPanel , "Pause/Resume", 5);
	addButtonToPanel(clockPanel , "Restart", 6); 
	


	
	// You could also pass a reference to a variable from the scene class, if public

}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			printf("Modifying Light 0.\n");
			break;
		};

		case 2:
		{
			printf("Modifying Light 1.\n");
			break;
		};
		case 3:
		{
			printf("Modifying Light 2.\n");
			break;
		};
		case 4:
		{
			printf("Modifying Light 3.\n");
			break;
		};
		case 5:
		{
			((LightingScene*) scene)->clock->setActive(!((LightingScene*) scene)->clock->getActive());
			printf("Clock Paused/Resumed");
			break;
		};
		case 6:
		{
			((LightingScene*) scene)->clock->resetClock();
			break;
			printf("Clock Reseted");
		};

	};
}

