#include "wifi.h"

void printAvailableNetworks() {
    HANDLE hClient = NULL;
    DWORD dwMaxClient = 2;
    DWORD dwCurVersion = 0;
    DWORD dwResult = 0;
    PWLAN_INTERFACE_INFO_LIST pInterfaceList = NULL;
    PWLAN_AVAILABLE_NETWORK_LIST pAvailableNetworkList = NULL;
    cout << "Available Networks:" << endl;
    cout << "-------------------" << endl;
    // Open a handle to the WLAN client
    dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
    if (dwResult == ERROR_SUCCESS) {
        // Enumerate the wireless LAN interfaces
        dwResult = WlanEnumInterfaces(hClient, NULL, &pInterfaceList);
        if (dwResult == ERROR_SUCCESS) {
            for (DWORD i = 0; i < pInterfaceList->dwNumberOfItems; i++) {
                const WLAN_INTERFACE_INFO& interfaceInfo = pInterfaceList->InterfaceInfo[i];
                GUID interfaceGuid = interfaceInfo.InterfaceGuid;
                dwResult = WlanGetAvailableNetworkList(hClient, &interfaceGuid, 0, NULL, &pAvailableNetworkList);
                if (dwResult == ERROR_SUCCESS) {
                    for (DWORD j = 0; j < pAvailableNetworkList->dwNumberOfItems; j++) {
                        const WLAN_AVAILABLE_NETWORK& network = pAvailableNetworkList->Network[j];
                        string ssid(reinterpret_cast<const char*>(network.dot11Ssid.ucSSID), network.dot11Ssid.uSSIDLength);
                        if (ssid != "") {
                            cout << "SSID: " << ssid << endl;
                        }
                        else {
                            cout << "SSID: Hidden Network" << endl;
                        }
                    }
                    WlanFreeMemory(pAvailableNetworkList);
                }
                else {
                    cerr << "WlanGetAvailableNetworkList failed with error: " << dwResult << endl;
                }
            }
            WlanFreeMemory(pInterfaceList);
        }
        else {
            cerr << "WlanEnumInterfaces failed with error: " << dwResult << endl;
        }

        WlanCloseHandle(hClient, NULL);
    }
    else {
        cerr << "WlanOpenHandle failed with error: " << dwResult << endl;
    }

}
