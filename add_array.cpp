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
    void add_ticket() {
        if (ticket_count >= 300) {
            cout << "Ticket storage is full!" << endl;
            return;
        }

        int id, event_date;
        string event_name, event_location;
        bool vip;

        cout << "Enter Ticket ID: ";
        cin >> id;
        cin.ignore();

        int user_count;
        cout << "Enter number of users (1 to " << Max_users << "): ";
        cin >> user_count;
        cin.ignore();

        if (user_count < 1 || user_count > Max_users) {
            cout << "Invalid number of users. Please enter between 1 and 5" << Max_users << "." << endl;
            return;
        }

        Ticket new_ticket;
        new_ticket.ticket_id = id;
        new_ticket.user_count = user_count;

        for (int i = 0; i < user_count; i++) {
            cout << "Enter User " << (i + 1) << " Name: ";
            getline(cin, new_ticket.users[i].name);

            cout << "Enter User " << (i + 1) << " Email: ";
            getline(cin, new_ticket.users[i].email);

            cout << "Enter Seat Number for User " << (i + 1) << ": ";
            cin >> new_ticket.seat_numbers[i];
            cin.ignore();
        }

        cout << "Enter Event Name: ";
        getline(cin, event_name);
        new_ticket.event.event_name = event_name;

        cout << "Enter Event Date (YYYY-MM-DD): ";
        cin >> event_date;
        cin.ignore();
        new_ticket.event.event_date = event_date;

        cout << "Enter Event Location: ";
        getline(cin, event_location);
        new_ticket.event.event_location = event_location;

        cout << "Is this a VIP ticket? (1 for Yes, 0 for No): ";
        cin >> vip;
        new_ticket.is_vip = vip;

        tickets[ticket_count] = new_ticket;
        ticket_count++;

        cout << "Ticket " << id << " added successfully." << endl;
    }

};

int main() {
    TicketSystemArray system;
    int choice;

    while (true) {
        cout << "\n--- Event Ticketing System ---" << endl;
        cout << "1. Add Ticket" << endl;
        cout << "2. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.add_ticket();
                break;
            case 2:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
