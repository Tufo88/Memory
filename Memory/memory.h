#ifndef MEMORY__H_
#define MEMORY__H_

#include <Windows.h>

struct MemoryRead {
	template <typename S>
	S value;
	bool success;
};

class Memory{

private: 
	HANDLE process = nullptr; // aka void* process -> used to get the pointer of the process (the handle to process)
	DWORD processId = 0; // aka unsigned long processId
public:
	Memory(); //constructor
	~Memory(); //destructor 

	DWORD getProcessId() { return processId; }
	HANDLE getProcessHandle() { return process;  }


	template <typename T>
	MemoryRead readMemory(uintptr_t address) {
		T value;
		ReadProcessMemory(this->process, (LPCVOID)address, &value, sizeof(T), nullptr);
		return value;
	}


};

#endif // !_MEMORY_H


