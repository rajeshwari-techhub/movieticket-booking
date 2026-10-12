
#include <iostream>
#include <string>
using namespace std;

extern string selectedMovie;
extern int selectedPrice;

void bookTicket() {
    if (selectedMovie == "") {
        cout << "\nPlease recommend and select a movie first!\n";
        return;
    }

    string seat;

    cout << "\nSelected Movie: " << selectedMovie << endl;
    cout << "Ticket Price: Rs. " << selectedPrice << endl;

    cout << "\nAvailable Seats: ";
    for (int i = 1; i <= 10; i++) {
        cout << "A" << i;
        if (i < 10) {
            cout << ", ";
        }
    }

    cout << "\nEnter your seat number: ";
    cin >> seat;

    bool available = false;

    for (int i = 1; i <= 10; i++) {
        if (seat == "A" + to_string(i)) {
            available = true;
            break;
        }
    }

    if (!available) {
        cout << "\nSeat not available! Please select A1 to A10.\n";
        return;
    }

    cout << "\nBooking Successful!\n";
    cout << "Movie: " << selectedMovie << endl;
    cout << "Seat Number: " << seat << endl;
    cout << "Ticket Price: Rs. " << selectedPrice << endl;
}
