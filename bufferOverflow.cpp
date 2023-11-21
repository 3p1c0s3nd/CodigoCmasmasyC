#include <iostream>
#include <cstring>

int main() {
    char buffer[10];
    std::strcpy(buffer, "EstoEsMuchoMasLargoQueElBuffer");
    std::cout << "Buffer content: " << buffer << std::endl;
    return 0;
}
