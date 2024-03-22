#pragma once
#include "pch.h"
#include "processes.h"

enum options {
	System_Info,
	Startup_Info,
	Processes_Data,
	Services_Data,
	Disks_Details,
	CPU_Monitor,
	GPU_Monitor,
	Mem_Data,
	Ethernet_info,
	Wifi_Info
};

void HandleOptions(int option);