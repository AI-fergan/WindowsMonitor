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
		printAllServices();
		break;

	case Disks_Details:
		printDrivesDetails();
		break;

	case CPU_Monitor:
		printProcessorName();
		printProcessorIdentifier();
		printLogicalCores();
		break;

	case GPU_Monitor:
		printGraphicsDetails();
		break;

	case Mem_Data:
		printDiskMemoryInfo();
		printRamMemoryInfo();
		break;

	case Ethernet_info:
		break;

	case Wifi_Info:
		break;	
	}

	_getch();
}
