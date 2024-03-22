#include "design.h"

void openScreen() {
	cout << " --------------------------------" << endl;
	cout << "|Tool:      "    << TOOL_NAME << "      |" << endl;
	cout << "|Creator:   " << CREATOR   << "         |" << endl;
	cout << "|Version:   " << VERSION   << "                 |" << endl;
	cout << " --------------------------------" << endl;
}

int options() {
	int option; 
	cout << "(Note: please write the number of the option you choose)" << endl;
	cout << "Options:" << endl;
	cout << " ( 0 )  System Information" << endl;
	cout << " ( 1 )  Startup Information" << endl;
	cout << " ( 2 )  Processes Data" << endl;
	cout << " ( 3 )  Services Data" << endl;
	cout << " ( 4 )  Disks Details" << endl;
	cout << " ( 5 )  CPU Monitoring" << endl;
	cout << " ( 6 )  GPU Monitoring" << endl;
	cout << " ( 7 )  Memory Data" << endl;
	cout << " ( 8 )  Ethernet information" << endl;
	cout << " ( 9 )  Wifi Information" << endl;

	cout << ">> ";
	cin >> option;

	return option;	
}

