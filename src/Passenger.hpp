#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <string>

class Passenger {
public:
    int id;
    std::string name;
    std::string email;
    std::string phone;

    // Constructors
    Passenger();
    Passenger(int id, const std::string& name, const std::string& email, 
              const std::string& phone);
    
    // Methods
    void display() const;
};

#endif