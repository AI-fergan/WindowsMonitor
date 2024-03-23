#include "memory.h"

void printDsikMemoryInfo() {
    LPCSTR lpRootPathName = "C:\\";
    DWORD sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters;

    if (GetDiskFreeSpaceA(lpRootPathName, &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters)) {
        // Convert total disk space to gigabytes
        ULONGLONG totalDiskSpaceBytes = (ULONGLONG)totalNumberOfClusters * sectorsPerCluster * bytesPerSector;
        double totalDiskSpaceGB = static_cast<double>(totalDiskSpaceBytes) / GIGABYTE;

        // Convert total free disk space to gigabytes
        ULONGLONG totalFreeDiskSpaceBytes = (ULONGLONG)numberOfFreeClusters * sectorsPerCluster * bytesPerSector;
        double totalFreeDiskSpaceGB = static_cast<double>(totalFreeDiskSpaceBytes) / GIGABYTE;

        cout << "Total disk space: " << totalDiskSpaceGB << " GB" << endl;
        cout << "Total free disk space: " << totalFreeDiskSpaceGB << " GB" << endl;
    }
    else {
        DWORD lastError = GetLastError();
        wcerr << "Failed to get disk space information. Error code: " << lastError << endl;
    }
}

void printRamMemoryInfo()
{
}
