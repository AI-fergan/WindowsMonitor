#include "processor.h"

DWORD countLogicalProcessors(){
    HKEY hKey;
    LPCWSTR keyPath = L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor";
    LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_READ, &hKey);
    char choice;
    DWORD index = 0;

    if (result == ERROR_SUCCESS) {

        WCHAR subkeyName[1024]; // Buffer to store subkey name
        DWORD subkeyNameSize = sizeof(subkeyName) / sizeof(subkeyName[0]);

        while (true) {
            result = RegEnumKeyEx(hKey, index, subkeyName, &subkeyNameSize, NULL, NULL, NULL, NULL);
            if (result == ERROR_SUCCESS) {                
                index++;
                subkeyNameSize = sizeof(subkeyName) / sizeof(subkeyName[0]);
            }
            else if (result == ERROR_NO_MORE_ITEMS) {
                break; // No more subkeys
            }
            else {
                std::wcerr << L"Failed to enumerate subkeys. Error code: " << result << std::endl;
                break;
            }
        }

        RegCloseKey(hKey);
    }
    else {
        std::wcerr << L"Failed to open key. Error code: " << result << std::endl;
    }

    return index;
}

void printLogicalCores() {
    cout << "Logical cores: " << countLogicalProcessors() << endl;
}

void printProcessorIdentifier() {
    HKEY hKey;
    LPCWSTR keyPath = L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";
    LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_READ, &hKey);
    LPCWSTR keyName = L"Identifier";
    if (result == ERROR_SUCCESS) {
        DWORD bufferSize = 0;

        result = RegQueryValueEx(hKey, keyName, NULL, NULL, NULL, &bufferSize);
        if (result == ERROR_SUCCESS) {
            std::wstring identifier(bufferSize / sizeof(wchar_t), L'\0');
            result = RegQueryValueEx(hKey, keyName, NULL, NULL, reinterpret_cast<LPBYTE>(&identifier[0]), &bufferSize);
            if (result == ERROR_SUCCESS) {
                std::wcout << "Identifier: " << identifier << std::endl;
            }
            else {
                std::cerr << "Failed to query value. Error code: " << result << std::endl;
            }
        }
        else {
            std::cerr << "Failed to query value size. Error code: " << result << std::endl;
        }
        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Failed to open registry key. Error code: " << result << std::endl;
    }
}

void printProcessorName() {
    HKEY hKey;
    LPCWSTR keyPath = L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";
    LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_READ, &hKey);
    LPCWSTR keyName = L"ProcessorNameString";
    if (result == ERROR_SUCCESS) {
        DWORD bufferSize = 0;

        result = RegQueryValueEx(hKey, keyName, NULL, NULL, NULL, &bufferSize);
        if (result == ERROR_SUCCESS) {
            std::wstring identifier(bufferSize / sizeof(wchar_t), L'\0');
            result = RegQueryValueEx(hKey, keyName, NULL, NULL, reinterpret_cast<LPBYTE>(&identifier[0]), &bufferSize);
            if (result == ERROR_SUCCESS) {
                std::wcout << "Processor name: " << identifier << std::endl;
            }
            else {
                std::cerr << "Failed to query value. Error code: " << result << std::endl;
            }
        }
        else {
            std::cerr << "Failed to query value size. Error code: " << result << std::endl;
        }
        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Failed to open registry key. Error code: " << result << std::endl;
    }
}
