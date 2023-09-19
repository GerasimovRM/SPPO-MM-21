#include <iostream>
#include <Windows.h>

int main() {


    OSVERSIONINFO osvi;
    SYSTEM_INFO si;
    //ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    //osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);
    GetSystemInfo(&si);

    cout << "a: " << si.wProcessorArchitecture << endl;
    cout << "b: " << si.dwProcessorType << endl;
    cout << "c: " << si.dwNumberOfProcessors << endl;
    cout << "d: " << si.lpMinimumApplicationAddress << "\t" << si.lpMaximumApplicationAddress << endl;
    cout << "e: " << osvi.dwMajorVersion << "\t" << osvi.dwMinorVersion << endl;
    cout << "f: " << osvi.dwBuildNumber << endl;
}