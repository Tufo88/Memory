#include "memory.h"

#include <TlHelp32.h>
#include <iostream>

#define LOG(x) std::wcout << "\n\n=====================================================\nPROCESS NAME: " << x.szExeFile << "\n  Process ID = " << x.th32ProcessID << " \n"

//constructor 
Memory::Memory(const char* processName, bool searchProcessOrWindow) {
	PROCESSENTRY32 processEntry; //struct en el que se guarda toda la info del proceso
	processEntry.dwSize = sizeof(PROCESSENTRY32); //no se, es obligatorio hacerlo para que funcione correctamente

	HANDLE hProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //se guardan/(crea un snapshot de todos) los procesos ejecutandose


	if (hProcessSnapshot == INVALID_HANDLE_VALUE) std::cout << "xd \n";


	while (Process32Next(hProcessSnapshot, &processEntry)) {
		

		if (!strcmp(processEntry.szExeFile, processName)) { //guardar el puntero al proceso en mi Memory y el id del proceso
			
		LOG(processEntry); //mostrar en cmd todos los procesos
			this->processId = processEntry.th32ProcessID;
			this->process = OpenProcess(PROCESS_ALL_ACCESS, 0, this->processId);
			
		}

	}

	std::cout << processName << std::endl;
	std::cout << this->process << " " << this->processId;

	if (hProcessSnapshot) CloseHandle(hProcessSnapshot);
}

//destructor 
Memory::~Memory() {

	if (this->process) CloseHandle(this->process);
}