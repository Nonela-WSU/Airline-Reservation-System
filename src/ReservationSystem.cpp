#include "ReservationSystem.hpp"
#include <iostream>

// Constructor
ReservationSystem::ReservationSystem() : nextBookingId(1) {}

// Add a flight
void ReservationSystem::addFlight(const Flight& flight) {
    flights.push_back(flight);
}

// Display all flights
void ReservationSystem::displayAllFlights() const {
    std::cout << "\n=== Available Flights ===\n";
    if (flights.empty()) {
        std::cout << "No flights available.\n";
        return;
    }
    for (const auto& flight : flights) {
        flight.display();
    }
}

// Find a flight by number
Flight* ReservationSystem::findFlight(const std::string& flightNumber) {
    for (auto& flight : flights) {
        if (flight.flightNumber == flightNumber) {
            return &flight;
        }
    }
    return nullptr;
}

// Add a passenger
void ReservationSystem::addPassenger(const Passenger& passenger) {
    passengers.push_back(passenger);
}

// Find a passenger by ID
Passenger* ReservationSystem::findPassenger(int id) {
    for (auto& passenger : passengers) {
        if (passenger.id == id) {
            return &passenger;
        }
    }
    return nullptr;
}

// Book a flight
bool ReservationSystem::bookFlight(int passengerId, const std::string& flightNumber) {
    // Find passenger
    Passenger* passenger = findPassenger(passengerId);
    if (!passenger) {
        std::cout << "❌ Error: Passenger not found!\n";
        return false;
    }
    
    // Find flight
    Flight* flight = findFlight(flightNumber);
    if (!flight) {
        std::cout << "❌ Error: Flight not found!\n";
        return false;
    }
    
    // Check availability
    if (!flight->bookSeat()) {
        std::cout << "❌ Error: No seats available on this flight!\n";
        return false;
    }
    
    // Create booking
    int seatNumber = flight->totalSeats - flight->availableSeats;
    Booking booking(nextBookingId++, *passenger, *flight, seatNumber);
    bookings.push_back(booking);
    
    std::cout << "\n✅ Booking confirmed! Booking ID: " << booking.bookingId << std::endl;
    return true;
}

// Cancel a booking
bool ReservationSystem::cancelBooking(int bookingId) {
    for (auto& booking : bookings) {
        if (booking.bookingId == bookingId && booking.status == "Confirmed") {
            booking.status = "Cancelled";
            // Free the seat
            Flight* flight = findFlight(booking.flight.flightNumber);
            if (flight) {
                flight->cancelSeat();
            }
            std::cout << "\n✅ Booking cancelled successfully!\n";
            return true;
        }
    }
    std::cout << "❌ Error: Booking not found or already cancelled!\n";
    return false;
}

// Display all bookings
void ReservationSystem::displayAllBookings() const {
    std::cout << "\n=== All Bookings ===\n";
    if (bookings.empty()) {
        std::cout << "No bookings found.\n";
        return;
    }
    for (const auto& booking : bookings) {
        booking.display();
    }
}

// Display bookings for a specific passenger
void ReservationSystem::displayPassengerBookings(int passengerId) const {
    std::cout << "\n=== Bookings for Passenger " << passengerId << " ===\n";
    bool found = false;
    for (const auto& booking : bookings) {
        if (booking.passenger.id == passengerId) {
            booking.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No bookings found for this passenger.\n";
    }
}
