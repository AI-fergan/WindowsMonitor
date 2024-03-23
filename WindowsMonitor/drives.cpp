#include "drives.h"

void printDrivesDetails() { 
    

    WCHAR buffer[1024]; // Buffer to store drive strings
    DWORD result = GetLogicalDriveStringsW(1024, buffer);

    if (result > 0 && result <= (DWORD)1024) {
        // The buffer contains one or more null-terminated drive strings
        wcout << L"Drive: " << buffer << endl;
    }
    else if (result > (DWORD)1024) {
        // The buffer is not large enough to hold all drive strings
        wcerr << L"Buffer too small." << endl;
    }
    else {
        // An error occurred
        DWORD lastError = GetLastError();
        wcerr << L"Failed to get drive strings. Error code: " << lastError << endl;
    }

    LPCSTR lpRootPathName = "C:\\";
    DWORD sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters;

    if (GetDiskFreeSpaceA(lpRootPathName, &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters)) {

        cout << "Sectors per cluster: " << sectorsPerCluster << endl;
        cout << "Bytes per sector: " << bytesPerSector << endl;
        cout << "Number of free clusters: " << numberOfFreeClusters << endl;
        cout << "Total number of clusters: " << totalNumberOfClusters << endl;

    }
    else {
        DWORD lastError = GetLastError();
        wcerr << "Failed to get disk space information. Error code: " << lastError << endl;
    }

}
