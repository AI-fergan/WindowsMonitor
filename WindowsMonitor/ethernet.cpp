#include "ethernet.h"

void printEthernetInfo() {
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    // Get the required buffer size
    if (GetAdaptersInfo(NULL, &dwSize) == ERROR_BUFFER_OVERFLOW) {
        IP_ADAPTER_INFO* pAdapterInfo = (IP_ADAPTER_INFO*)malloc(dwSize);
        if (pAdapterInfo != nullptr) {
            if (GetAdaptersInfo(pAdapterInfo, &dwSize) == NO_ERROR) {
                IP_ADAPTER_INFO* pAdapter = pAdapterInfo;
                while (pAdapter) {
                    std::cout << "Adapter Description: " << pAdapter->Description << std::endl;
                    std::cout << "Adapter IP Address: " << pAdapter->IpAddressList.IpAddress.String << std::endl;
                    std::cout << "Adapter Subnet Mask: " << pAdapter->IpAddressList.IpMask.String << std::endl;
                    std::cout << std::endl;
                    pAdapter = pAdapter->Next;
                }
            }
            else {
                std::cerr << "GetAdaptersInfo failed." << std::endl;
            }
            free(pAdapterInfo);
        }
        else {
            std::cerr << "Memory allocation failed." << std::endl;
        }
    }
    else {
        std::cerr << "GetAdaptersInfo failed to get buffer size." << std::endl;
    }

}
