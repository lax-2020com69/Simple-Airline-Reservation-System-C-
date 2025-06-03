#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// User Class
class User {
    string username, password;

public:
    bool login() {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        ifstream file("users.txt");
        string u, p;
        while (file >> u >> p) {
            if (u == username && p == password) {
                cout << "Login successful!\n";
                return true;
            }
        }
        cout << "Invalid credentials.\n";
        return false;
    }

    static void registerUser() {
        string u, p;
        cout << "Choose a username: ";
        cin >> u;
        cout << "Choose a password: ";
        cin >> p;
        ofstream file("users.txt", ios::app);
        file << u << " " << p << endl;
        cout << "User registered successfully!\n";
    }
};

// Flight Class
class Flight {
public:
    string flightNo;
    vector<int> seats;

    Flight(string fNo = "AI101", int seatCount = 10) {
        flightNo = fNo;
        seats = vector<int>(seatCount, 0);
    }

    void loadSeats() {
        ifstream file("seat.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string fNo;
            ss >> fNo;
            if (fNo == flightNo) {
                for (int i = 0; i < seats.size(); i++) {
                    ss >> seats[i];
                }
            }
        }
    }

    void saveSeats() {
        // Read all lines and update this flight line
        ifstream in("seat.txt");
        vector<string> lines;
        string line;
        bool found = false;

        while (getline(in, line)) {
            stringstream ss(line);
            string fNo;
            ss >> fNo;
            if (fNo == flightNo) {
                string newLine = flightNo;
                for (int s : seats) newLine += " " + to_string(s);
                lines.push_back(newLine);
                found = true;
            } else {
                lines.push_back(line);
            }
        }
        in.close();

        if (!found) {
            string newLine = flightNo;
            for (int s : seats) newLine += " " + to_string(s);
            lines.push_back(newLine);
        }

        ofstream out("seat.txt");
        for (const auto& l : lines) out << l << "\n";
    }

    void displaySeats() {
        cout << "\nFlight " << flightNo << " seat status:\n";
        for (int i = 0; i < seats.size(); i++) {
            cout << "Seat " << setw(2) << i + 1 << ": " << (seats[i] ? "Booked" : "Available") << "\n";
        }
    }

    void bookSeat() {
        int seatNo;
        displaySeats();
        cout << "Enter seat number to book (1-" << seats.size() << "): ";
        cin >> seatNo;
        if (seatNo < 1 || seatNo > seats.size() || seats[seatNo - 1]) {
            cout << "Invalid or already booked.\n";
        } else {
            seats[seatNo - 1] = 1;
            saveSeats();
            cout << "Seat " << seatNo << " booked successfully.\n";
        }
    }

    void cancelSeat() {
        int seatNo;
        cout << "Enter seat number to cancel (1-" << seats.size() << "): ";
        cin >> seatNo;
        if (seatNo < 1 || seatNo > seats.size() || !seats[seatNo - 1]) {
            cout << "Invalid or not booked.\n";
        } else {
            seats[seatNo - 1] = 0;
            saveSeats();
            cout << "Seat " << seatNo << " cancelled successfully.\n";
        }
    }
};

// Load all flights from flight.txt
vector<Flight> loadFlights() {
    ifstream file("flight.txt");
    string line;
    vector<Flight> flights;

    while (getline(file, line)) {
        stringstream ss(line);
        string fNo;
        int count;
        ss >> fNo >> count;
        Flight f(fNo, count);
        f.loadSeats();
        flights.push_back(f);
    }
    return flights;
}

// Save all flights back to seat.txt (optional - handled individually in class)
void saveAllSeats(const vector<Flight>& flights) {
    ofstream file("seat.txt");
    for (const auto& f : flights) {
        file << f.flightNo;
        for (int s : f.seats) file << " " << s;
        file << endl;
    }
}

// Main Program
int main() {
    int choice;
    cout << "==== Airline Reservation System ====\n";
    cout << "1. Register\n2. Login\nChoice: ";
    cin >> choice;

    User user;
    if (choice == 1) {
        User::registerUser();
        return 0;
    }

    if (!user.login()) return 0;

    vector<Flight> flights = loadFlights();

    while (true) {
        cout << "\n=== Main Menu ===\n";
        for (int i = 0; i < flights.size(); i++) {
            cout << i + 1 << ". Flight " << flights[i].flightNo << "\n";
        }
        cout << "0. Exit\nChoose flight: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > flights.size()) {
            cout << "Invalid choice.\n";
            continue;
        }

        Flight& selected = flights[choice - 1];
        int subChoice;

        while (true) {
            cout << "\n--- Flight Menu (" << selected.flightNo << ") ---\n";
            cout << "1. View Seats\n2. Book Seat\n3. Cancel Seat\n4. Back to Flights\n";
            cout << "Enter choice: ";
            cin >> subChoice;

            if (subChoice == 1) selected.displaySeats();
            else if (subChoice == 2) selected.bookSeat();
            else if (subChoice == 3) selected.cancelSeat();
            else if (subChoice == 4) break;
            else cout << "Invalid option.\n";
        }
    }

    cout << "Thank you for using the system!\n";
    return 0;
}


