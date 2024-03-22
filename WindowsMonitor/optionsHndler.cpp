#include "optionsHndler.h"

void HandleOptions(int option) {
	system("cls");
	switch (option) {
	case EXIT:
		cout << "Bye!" << endl;
		break;

	case System_Info:
		printComputerName();
		printUserName();
		printSystemDiractory();
		printWindowsDiractory();
		printEnvar();			
		break;

	case Startup_Info:
		printStartupData();
		break;

	case Processes_Data:
		PrintAllProcessesNameAndID();		
		break;

	case Services_Data:		
		break;

	case Disks_Details:
		break;

	case CPU_Monitor:
		break;

	case GPU_Monitor:
		break;

	case Mem_Data:
		break;

	case Ethernet_info:
		break;

	case Wifi_Info:
		break;	
	}

	_getch();
}
