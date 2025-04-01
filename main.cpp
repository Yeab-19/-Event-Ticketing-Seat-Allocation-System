#include <iostream>
#include <string>
using namespace std;

const int Max_users = 5;

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
    Event event;
    int seat_numbers[Max_users];
    int user_count;
    bool is_vip;

    Ticket* next;
};

class TicketSystemLinkedList {
private:
    Ticket* head;

public:
    void delete_ticket() {
        int id;
        cout << "Enter Ticket ID to delete: ";
        cin >> id;

        Ticket* temp = head;
        Ticket* prev = NULL;

        while (temp) {
            if (temp->ticket_id == id) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                cout << "Ticket " << id << " deleted successfully." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Ticket not found." << endl;
    }
};
   int main() {
    TicketSystemLinkedList system;
    int choice;

    while (true) {
        cout << "\n--- Event Ticketing & Seat Allocation System ---" << endl;
        cout << "1. Delete Ticket" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.delete_ticket();
                break;
            case 2:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
