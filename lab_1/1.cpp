#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    // пункт
    // notepad.exe textfile.txt
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    char cmd_line[200] = "notepad.exe textfile.txt";

    // create process
    if (CreateProcess(NULL,
                      cmd_line,
                      NULL,
                      NULL,
                      false,
                      0,
                      NULL,
                      NULL,
                      &si,
                      &pi)) {
        // описатель процесса, его идентификатор, идентификатор первичного потока
        cout << "Hadnler of process:" << pi.hProcess << endl;
        cout << "Id of process:" << pi.dwProcessId << endl;
        cout << "Id of thread:" << pi.dwThreadId << endl;
    } else {
        cout << "Program is not found!" << endl;
    }

    return 0;
}
