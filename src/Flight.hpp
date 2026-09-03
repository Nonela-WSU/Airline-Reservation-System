#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>

class Flight {
public:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    int totalSeats;
    int availableSeats;

    // Constructors
    Flight();
    Flight(const std::string& flightNumber, const std::string& origin, 
           const std::string& destination, int totalSeats);
    
    // Methods
    bool bookSeat();
    void cancelSeat();
    void display() const;
};

#endif