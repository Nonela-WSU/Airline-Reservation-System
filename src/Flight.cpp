#include "Flight.hpp"
#include <iostream>

// Default constructor
Flight::Flight() : totalSeats(0), availableSeats(0) {}

// Parameterized constructor
Flight::Flight(const std::string& fn, const std::string& from, 
               const std::string& to, int seats) 
    : flightNumber(fn), origin(from), destination(to), 
      totalSeats(seats), availableSeats(seats) {}

// Book a seat
bool Flight::bookSeat() {
    if (availableSeats > 0) {
        availableSeats--;
        return true;
    }
    return false;
}

// Cancel a seat
void Flight::cancelSeat() {
    if (availableSeats < totalSeats) {
        availableSeats++;
    }
}

// Display flight details
void Flight::display() const {
    std::cout << flightNumber << " | " << origin << " -> " << destination 
              << " | Seats: " << availableSeats << "/" << totalSeats << std::endl;
}
