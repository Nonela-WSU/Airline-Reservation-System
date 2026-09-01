#ifndef BOOKING_HPP
#define BOOKING_HPP

#include "Flight.hpp"
#include "Passenger.hpp"
#include <string>

class Booking {
public:
    int bookingId;
    Passenger passenger;
    Flight flight;
    int seatNumber;
    std::string status;

    // Constructors
    Booking();
    Booking(int bookingId, const Passenger& passenger, const Flight& flight, int seatNumber);
    
    // Methods
    void display() const;
};

#endif
