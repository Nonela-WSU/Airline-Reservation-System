#include "Passenger.hpp"
#include <iostream>

// Default constructor
Passenger::Passenger() : id(0), name(""), email(""), phone("") {}

// Parameterized constructor
Passenger::Passenger(int i, const std::string& n, const std::string& e, 
                     const std::string& p) 
    : id(i), name(n), email(e), phone(p) {}

// Display passenger details
void Passenger::display() const {
    std::cout << "ID: " << id << " | " << name << " | " << email << " | " << phone << std::endl;
}
