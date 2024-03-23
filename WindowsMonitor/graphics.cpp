#include "graphics.h"

void printGraphicsDetails() {
    IDXGIFactory* pFactory = nullptr;
    if (SUCCEEDED(CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&pFactory)))) {
        IDXGIAdapter* pAdapter = nullptr;
        for (UINT i = 0; pFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++i) {
            DXGI_ADAPTER_DESC desc = {};
            if (SUCCEEDED(pAdapter->GetDesc(&desc))) {                
                wcout << desc.Description << endl;                
                wcout << L"Vendor ID: " << desc.VendorId << endl;
                wcout << L"Device ID: " << desc.DeviceId << endl;
                wcout << L"SubSys ID: " << desc.SubSysId << endl;
                wcout << L"Revision: " << desc.Revision << endl;
                wcout << L"Dedicated Video Memory: " << desc.DedicatedVideoMemory << endl;
                wcout << L"Dedicated System Memory: " << desc.DedicatedSystemMemory << endl;
                wcout << L"Shared System Memory: " << desc.SharedSystemMemory << endl << endl;
            }
            else {
                wcerr << "Failed to get adapter description." << endl;
            }
            pAdapter->Release();
        }
        pFactory->Release();
    }
    else {
        wcerr << "Failed to create DXGI factory." << endl;
    }
}
