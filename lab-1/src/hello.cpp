#include <name.hpp>
#include <iostream>

int main() {
    std::string name = getUserName();
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}