#include "services.h"

void printAllServices() {
    HKEY hKey;
    LPCWSTR keyPath = L"SYSTEM\\CurrentControlSet\\Services";
    LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_READ, &hKey);
    char choice;

    if (result == ERROR_SUCCESS) {
        DWORD index = 0;
        WCHAR subkeyName[1024]; // Buffer to store subkey name
        DWORD subkeyNameSize = sizeof(subkeyName) / sizeof(subkeyName[0]);

        while (true) {
            result = RegEnumKeyEx(hKey, index, subkeyName, &subkeyNameSize, NULL, NULL, NULL, NULL);
            if (result == ERROR_SUCCESS) {
                if ((index + 1) % 10 == 0) {
                    do {
                        cout << "(press enter for continue or q for exit)";
                        choice = _getch();
                        if (choice == 'q') {
                            return;
                        }
                    } while (choice == '\n');
                    cout << endl;
                }
                _tprintf(TEXT("%s\n"), subkeyName);
                index++;
                subkeyNameSize = sizeof(subkeyName) / sizeof(subkeyName[0]);
            }
            else if (result == ERROR_NO_MORE_ITEMS) {
                break; // No more subkeys
            }
            else {
                wcerr << L"Failed to enumerate subkeys. Error code: " << result << endl;
                break;
            }
        }

        RegCloseKey(hKey);
    }
    else {
        wcerr << L"Failed to open key. Error code: " << result << endl;
    }
}
