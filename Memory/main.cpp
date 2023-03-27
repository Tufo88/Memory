
#include "memory.h"
#include <iostream>


inline uintptr_t handleFromString(const char* c, int base = 16)
{
    // See if this function catches all possibilities.
    // If it doesn't, the function would have to be amended
    // whenever you add a combination of architecture and
    // compiler that is not yet addressed.
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
        || sizeof(uintptr_t) == sizeof(unsigned long long),
        "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}

int main() {

    Memory memory("Project4.exe", false);
    uintptr_t addr;
    std::string strtmp;
    std::cin >> strtmp;
    const char* tmp = strtmp.c_str();
    addr = handleFromString(tmp);
    std::cout << memory.Read<int>(addr);
    memory.Write<int>(addr, 10);

}
	