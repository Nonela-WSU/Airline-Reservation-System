#include "Booking.hpp"
#include <iostream>

// Default constructor
Booking::Booking() : bookingId(0), passenger(), flight(), seatNumber(0), status("Pending") {}

// Parameterized constructor
Booking::Booking(int id, const Passenger& p, const Flight& f, int seat) 
    : bookingId(id), passenger(p), flight(f), seatNumber(seat), status("Confirmed") {}

// Display booking details
void Booking::display() const {
    std::cout << "Booking #" << bookingId << " | " << passenger.name 
              << " | Flight: " << flight.flightNumber 
              << " | Seat: " << seatNumber 
              << " | " << status << std::endl;
}