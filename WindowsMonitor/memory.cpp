#include "memory.h"

void printDiskMemoryInfo() {
    LPCSTR lpRootPathName = "C:\\";
    DWORD sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters;

    if (GetDiskFreeSpaceA(lpRootPathName, &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters)) {
        // Convert total disk space to gigabytes
        ULONGLONG totalDiskSpaceBytes = (ULONGLONG)totalNumberOfClusters * sectorsPerCluster * bytesPerSector;
        double totalDiskSpaceGB = static_cast<double>(totalDiskSpaceBytes) / GIGABYTE;

        // Convert total free disk space to gigabytes
        ULONGLONG totalFreeDiskSpaceBytes = (ULONGLONG)numberOfFreeClusters * sectorsPerCluster * bytesPerSector;
        double totalFreeDiskSpaceGB = static_cast<double>(totalFreeDiskSpaceBytes) / GIGABYTE;
        cout << "Rom memory" << endl;
        cout << "----------" << endl;
        cout << "Total disk space: " << totalDiskSpaceGB << " GB" << endl;
        cout << "Total free disk space: " << totalFreeDiskSpaceGB << " GB" << endl << endl;
    }
    else {
        DWORD lastError = GetLastError();
        wcerr << "Failed to get disk space information. Error code: " << lastError << endl;
    }
}

void printRamMemoryInfo() {
    ULONGLONG totalMemoryInKilobytes = 0;

    if (GetPhysicallyInstalledSystemMemory(&totalMemoryInKilobytes)) {
        cout << "Ram memory" << endl;
        cout << "----------" << endl;
        std::cout << "Total Physically Installed System Memory: " << (totalMemoryInKilobytes * 1024) / GIGABYTE << std::endl << endl;
    }
    else {
        DWORD lastError = GetLastError();
        std::cerr << "Failed to get physically installed system memory. Error code: " << lastError << std::endl;
    }
}
