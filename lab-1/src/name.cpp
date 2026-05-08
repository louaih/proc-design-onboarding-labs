// Write a function that asks the user their name and returns it as a std::string
#include <iostream>
#include <string>

std::string getUserName() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);
    return name;
}
