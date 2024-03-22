#include "processes.h"

void PrintProcessNameAndID(DWORD processID)
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown process name>");

    // Get a handle to the process.
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
        PROCESS_VM_READ,
        FALSE, processID);

    // Get the process name.
    if (NULL != hProcess) {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
            GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
        }
    }

    // Print the process name and identifier.
    _tprintf(TEXT("{Process_name: %s}"), szProcessName);
    DWORD exitCode = 0;
    GetExitCodeProcess(hProcess, &exitCode);
    cout << "\t{status:";
    if (exitCode == STILL_ACTIVE)
    {        
        cout << "run}";
    }
    else {
        cout << "suspended}";
    }

    _tprintf(TEXT("\t{PID: %u}\n"), processID);

    // Release the handle to the process.

    CloseHandle(hProcess);
}

void PrintAllProcessesNameAndID() {
    // Get the list of process identifiers.

    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;
    char choice = ' ';
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) { return; }

    // Calculate how many process identifiers were returned.
    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.
    for (i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {
            PrintProcessNameAndID(aProcesses[i]);
        }
        if ((i + 1) % 10 == 0) {
            do {
                cout << "(press enter for continue or q for exit)";
                choice = _getch();
                if (choice == 'q') {
                    return;
                }                
            } while (choice == '\n');
            cout << endl;
        }
        
    }
}