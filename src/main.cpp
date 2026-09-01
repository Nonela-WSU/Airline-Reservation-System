#include "ReservationSystem.hpp"
#include <iostream>
#include <limits>

using namespace std;

// Function prototypes
void displayMenu();
void clearInput();

int main() {
    ReservationSystem system;
    
    // Initialize with sample data
    system.addFlight(Flight("AI101", "New York", "London", 5));
    system.addFlight(Flight("BA202", "London", "Paris", 3));
    system.addFlight(Flight("EK303", "Dubai", "Tokyo", 4));
    system.addPassenger(Passenger(1, "John Doe", "john@email.com", "1234567890"));
    system.addPassenger(Passenger(2, "Jane Smith", "jane@email.com", "0987654321"));
    
    int choice;
    do {
        displayMenu();
        cin >> choice;
        
        // Handle invalid input
        if (cin.fail()) {
            clearInput();
            cout << "❌ Invalid input! Please enter a number.\n";
            continue;
        }
        
        switch(choice) {
            case 1:
                system.displayAllFlights();
                break;
                
            case 2: {
                int id;
                string flightNum;
                cout << "Enter passenger ID: ";
                cin >> id;
                if (cin.fail()) {
                    clearInput();
                    cout << "❌ Invalid ID!\n";
                    break;
                }
                cout << "Enter flight number: ";
                cin >> flightNum;
                system.bookFlight(id, flightNum);
                break;
            }
            
            case 3: {
                int bookingId;
                cout << "Enter booking ID: ";
                cin >> bookingId;
                if (cin.fail()) {
                    clearInput();
                    cout << "❌ Invalid ID!\n";
                    break;
                }
                system.cancelBooking(bookingId);
                break;
            }
            
            case 4:
                system.displayAllBookings();
                break;
                
            case 5: {
                int id;
                cout << "Enter passenger ID: ";
                cin >> id;
                if (cin.fail()) {
                    clearInput();
                    cout << "❌ Invalid ID!\n";
                    break;
                }
                system.displayPassengerBookings(id);
                break;
            }
            
            case 6:
                cout << "\n👋 Thank you for using the Airline Reservation System!\n";
                break;
                
            default:
                cout << "❌ Invalid choice! Please enter 1-6.\n";
        }
    } while(choice != 6);
    
    return 0;
}

// Display the main menu
void displayMenu() {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║   ✈️  AIRLINE RESERVATION SYSTEM   ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║  1. View All Flights                ║\n";
    cout << "║  2. Book a Flight                  ║\n";
    cout << "║  3. Cancel Booking                 ║\n";
    cout << "║  4. View All Bookings              ║\n";
    cout << "║  5. View My Bookings               ║\n";
    cout << "║  6. Exit                          ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << "Enter choice: ";
}

// Clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
