#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <vector>
#include "Flight.hpp"
#include "Passenger.hpp"
#include "Booking.hpp"

class ReservationSystem {
private:
    std::vector<Flight> flights;
    std::vector<Passenger> passengers;
    std::vector<Booking> bookings;
    int nextBookingId;

public:
    // Constructor
    ReservationSystem();
    
    // Flight management
    void addFlight(const Flight& flight);
    void displayAllFlights() const;
    Flight* findFlight(const std::string& flightNumber);
    
    // Passenger management
    void addPassenger(const Passenger& passenger);
    Passenger* findPassenger(int id);
    
    // Booking operations
    bool bookFlight(int passengerId, const std::string& flightNumber);
    bool cancelBooking(int bookingId);
    void displayAllBookings() const;
    void displayPassengerBookings(int passengerId) const;
};

#endif
