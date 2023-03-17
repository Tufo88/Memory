#ifndef MEMORY__H_
#define MEMORY__H_

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


class Memory {

private:
	HANDLE process = nullptr; // aka void* process -> used to get the pointer of the process (the handle to a process)
	DWORD processId = 0; // aka unsigned long processId

public:
	Memory(const char* processName, bool searchProcessOrWindow); //constructor
	~Memory(); //destructor 

	DWORD getProcessId() { return this->processId; }
	HANDLE getProcessHandle() { return this->process; }


	template <typename T>
	T Read(uintptr_t address) {
		T value;
		ReadProcessMemory(this->process, (LPCVOID)address, &value, sizeof(T), nullptr);
		return value;
	}

	template <typename T>
	bool Write(uintptr_t address, T value) {
		return WriteProcessMemory(this->process, (LPCVOID)address, &value, sizeof(T), nullptr);
	}


};

#endif // !_MEMORY_H

