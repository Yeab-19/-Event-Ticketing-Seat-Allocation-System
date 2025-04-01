#include <iostream>
#include <string>
using namespace std;

const int Max_users = 7;
struct User {
    string name;
    string email;
};

struct Event {
    string event_name;
    int event_date;
    string event_location;
};

struct Ticket {
    int ticket_id;
    User users[Max_users];
    int user_count;
    Event event;
    int seat_numbers[Max_users];
    bool is_vip;
};

class TicketSystemArray {
private:
    Ticket tickets[300];
    int ticket_count = 0;


public:
       void update_ticket() {
        int id;
        cout << "Enter Ticket ID to update: ";
        cin >> id;

        for (int i = 0; i < ticket_count; i++) {
            if (tickets[i].ticket_id == id) {
                int user_index;
                cout << "Enter user index to update seat number (1 to " << tickets[i].user_count << "): ";
                cin >> user_index;
                cin.ignore();
                user_index--; // Adjust for 0-based index

                if (user_index < 0 || user_index >= tickets[i].user_count) {
                    cout << "Invalid user index." << endl;
                    return;
                }

                cout << "Enter new seat number for User " << (user_index + 1) << ": ";
                cin >> tickets[i].seat_numbers[user_index];
                cin.ignore();
                cout << "Ticket " << id << " updated successfully." << endl;
                return;
            }
        }
        cout << "Ticket not found." << endl;
    }

};

int main() {
    TicketSystemArray system;
    int choice;

    while (true) {
        cout << "\n--- Event Ticketing System ---" << endl;
        cout << "1. Update Ticket" << endl;
        cout << "2. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.update_ticket();
                break;
            case 2:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

