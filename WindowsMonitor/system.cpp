#include "system.h"

void printError(const TCHAR* msg)
{
    _tprintf(TEXT("\n\t%s failed with error"), msg);
}

void printComputerName()
{
    TCHAR  infoBuf[INFO_BUFFER_SIZE] = { '\0' };
    DWORD  bufCharCount = INFO_BUFFER_SIZE;

    // Get and display the name of the computer.
    if (!::GetComputerName(infoBuf, &bufCharCount))
        printError(TEXT("GetComputerName"));
    else
        _tprintf(TEXT("\nComputer name:      %s"), infoBuf);
}

void printUserName()
{
    TCHAR  infoBuf[INFO_BUFFER_SIZE] = { '\0' };
    DWORD  bufCharCount = INFO_BUFFER_SIZE;

    // Get and display the user name. 
    bufCharCount = INFO_BUFFER_SIZE;
    if (!::GetUserName(infoBuf, &bufCharCount))
        printError(TEXT("GetUserName"));
    else
        _tprintf(TEXT("\nUser name:          %s"), infoBuf);
}

void printSystemDiractory()
{
    TCHAR  infoBuf[INFO_BUFFER_SIZE] = { '\0' };

    // Get and display the system directory. 
    if (!::GetSystemDirectory(infoBuf, INFO_BUFFER_SIZE))
        printError(TEXT("GetSystemDirectory"));
    else
        _tprintf(TEXT("\nSystem Directory:   %s"), infoBuf);
}

void printWindowsDiractory()
{
    TCHAR  infoBuf[INFO_BUFFER_SIZE] = { '\0' };

    // Get and display the Windows directory. 
    if (!::GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE))
        printError(TEXT("GetWindowsDirectory"));
    else
        _tprintf(TEXT("\nWindows Directory:  %s"), infoBuf);
}

void printEnvar()
{
    DWORD  bufCharCount = INFO_BUFFER_SIZE;
    TCHAR  infoBuf[INFO_BUFFER_SIZE] = { '\0' };
    DWORD i = 0;

    const TCHAR* envVarStrings[] =
    {
      TEXT("OS         = %OS%"),
      TEXT("PATH       = %PATH%"),
      TEXT("HOMEPATH   = %HOMEPATH%"),
      TEXT("TEMP       = %TEMP%")
    };

    // Expand and display a few environment variables. 
    _tprintf(TEXT("\n\nSmall selection of Environment Variables:"));

    for (i = 0; i < (sizeof(envVarStrings) / sizeof(TCHAR*)); ++i)
    {
        bufCharCount = ::ExpandEnvironmentStrings(envVarStrings[i], infoBuf,
            INFO_BUFFER_SIZE);
        if (bufCharCount > INFO_BUFFER_SIZE)
            _tprintf(TEXT("\n\t(Buffer too small to expand: \"%s\")"), envVarStrings[i]);
        else if (!bufCharCount)
            printError(TEXT("ExpandEnvironmentStrings"));
        else
            _tprintf(TEXT("\n   %s"), infoBuf);
    }
    _tprintf(TEXT("\n\n"));
}
