#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <vector>
#include <string>
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
    ReservationSystem();
    
    void addFlight(const Flight& flight);
    void displayAllFlights() const;
    Flight* findFlight(const std::string& flightNumber);
    
    void addPassenger(const Passenger& passenger);
    Passenger* findPassenger(int id);
    
    bool bookFlight(int passengerId, const std::string& flightNumber);
    bool cancelBooking(int bookingId);
    void displayAllBookings() const;              // ✅ MUST HAVE THIS
    void displayPassengerBookings(int passengerId) const;  // ✅ MUST HAVE THIS
    
    bool passengerExists(int id) const;
    bool flightExists(const std::string& flightNumber) const;
};

#endif