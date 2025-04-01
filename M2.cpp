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
void search_ticket() {
        int id;
        cout << "Enter Ticket ID to search: ";
        cin >> id;

        for (int i = 0; i < ticket_count; i++) {
            if (tickets[i].ticket_id == id) {
                cout << "Ticket ID: " << tickets[i].ticket_id << endl;
                cout << "Users: ";
                for (int j = 0; j < tickets[i].user_count; j++) {
                    cout << tickets[i].users[j].name << " (" << tickets[i].users[j].email << ") - Seat: " << tickets[i].seat_numbers[j];
                    if (j < tickets[i].user_count - 1) {
                        cout << ", ";
                    }
                }
                cout << endl;
                cout << "Event: " << tickets[i].event.event_name << " on " << tickets[i].event.event_date << " at " << tickets[i].event.event_location << endl;
                cout << "VIP: " << (tickets[i].is_vip ? "Yes" : "No") << endl;
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
        cout << "1. search Ticket" << endl;
        cout << "2. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.search_ticket();
                break;
            case 2:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
