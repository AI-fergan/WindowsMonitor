#include "startup.h"

void printStartupData() {
    HKEY hKey;
    LPCWSTR keyPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    vector< WCHAR> values;
    LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, keyPath, 0, KEY_READ, &hKey);

    if (result == ERROR_SUCCESS) {
        DWORD index = 0;
        WCHAR valueName[1024]; // Buffer to store value name
        DWORD valueNameSize = sizeof(valueName) / sizeof(valueName[0]);
        BYTE data[1024]; // Buffer to store value data
        DWORD dataSize = sizeof(data);
        DWORD valueType;

        while (true) {
            result = RegEnumValue(hKey, index, valueName, &valueNameSize, NULL, &valueType, data, &dataSize);
            if (result == ERROR_SUCCESS) {
                wcout << "Name: " << valueName << endl << "Status: Enabled" << endl << endl;
                // Print or process the data here, depending on the value type
                index++;
                valueNameSize = sizeof(valueName) / sizeof(valueName[0]);
                dataSize = sizeof(data);
            }
            else if (result == ERROR_NO_MORE_ITEMS) {
                break; // No more values
            }
            else {
                wcerr << L"Failed to enumerate values. Error code: " << result << endl;
                break;
            }
        }

        RegCloseKey(hKey);
    }
    else {
        wcerr << L"Failed to open key. Error code: " << result << endl;
    }

    keyPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run\\AutorunsDisabled";

    result = RegOpenKeyEx(HKEY_CURRENT_USER, keyPath, 0, KEY_READ, &hKey);

    if (result == ERROR_SUCCESS) {
        DWORD index = 0;
        WCHAR valueName[1024]; // Buffer to store value name
        DWORD valueNameSize = sizeof(valueName) / sizeof(valueName[0]);
        BYTE data[1024]; // Buffer to store value data
        DWORD dataSize = sizeof(data);
        DWORD valueType;

        while (true) {
            result = RegEnumValue(hKey, index, valueName, &valueNameSize, NULL, &valueType, data, &dataSize);
            if (result == ERROR_SUCCESS) {
                wcout << "Name: " << valueName << endl << "Status: Disabled" << endl << endl;
                // Print or process the data here, depending on the value type
                index++;
                valueNameSize = sizeof(valueName) / sizeof(valueName[0]);
                dataSize = sizeof(data);
            }
            else if (result == ERROR_NO_MORE_ITEMS) {
                break; // No more values
            }
            else {
                wcerr << L"Failed to enumerate values. Error code: " << result << endl;
                break;
            }
        }

        RegCloseKey(hKey);
    }
    else {
        wcerr << L"Failed to open key. Error code: " << result << endl;
    }
}
