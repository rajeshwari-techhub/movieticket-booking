
#include <iostream>
#include <string>
using namespace std;

// Functions defined in other files
void recommend(string genre);
void bookTicket();

int main() {
    int choice;
    string genre;

    do {
        cout << "\n===== MOVIE RECOMMENDATION SYSTEM =====\n";
        cout << "1. Recommend Movies\n";
        cout << "2. Book a Seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter your favorite genre: ";
                cin >> genre;
                recommend(genre);
                break;

            case 2:
                bookTicket();
                break;

            case 3:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
