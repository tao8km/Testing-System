#include "MainApp.h"

int main()
{
	MainApp app;
	if (app.auth()) { // authenticate
		app.run();
	}
}