#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

vector<Contact> contacts;

// Function to add a contact
void addContact() {
    Contact c;
    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter Phone Number: ";
    getline(cin, c.phoneNumber);
    contacts.push_back(c);
    cout << "Contact added successfully!\n";
}

// Function to display all contacts
void displayContacts() {
    if (contacts.empty()) {
        cout << "No contacts found!\n";
        return;
    }
    cout << "\nContacts List:\n\n";
    for (const auto& c : contacts) {
        cout << "Name: " << c.name << "\n";
        cout << "Phone Number: " << c.phoneNumber << "\n\n";
    }
}

// Function to search for a contact by name
void searchContact() {
    string name;
    cout << "Enter Name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (const auto& c : contacts) {
        if (c.name == name) {
            cout << "\nContact Found:\n";
            cout << "Name: " << c.name << "\n";
            cout << "Phone Number: " << c.phoneNumber << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Add Contact\n2. Display All Contacts\n3. Search Contact by Name\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
