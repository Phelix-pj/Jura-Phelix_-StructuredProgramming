#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <memory>
#include <limits>
#include <fstream> // Enables File I/O for "printing" physical ticket

using namespace std;

// A parent class name Trip is created with encapsulation implementation

class Trip {
protected:
    string from, to, depTime;
    double price;

public:
    // Default Constructor: Sets safe initial values so we don't have "garbage data"
    Trip() : from("N/A"), to("N/A"), depTime("00:00"), price(0.0) {}

    // Method to safely update trip data
    void setDetails(string f, string t, string d, double p) {
        from = f;
        to = t;
        depTime = d;
        price = p;
    }

    // GETTERS: Added so the Main Menu can see the Route for the booking list
    string getRoute() const { return from + " to " + to; }
};

/* BUS CLASS: Uses INHERITANCE to take features from 'Trip'.
   It also manages the physical DATA STRUCTURE (the 2D seat array).
*/
class Bus : public Trip {
private:
    string busID;
    string seats[10][4]; // 2D Array: [Rows][Columns]

public:
    // Constructor: Runs the moment 'make_unique' is called in main
    Bus(string id) : busID(id) {
        // Nested loop to initialize all 40 seats as "EMPTY"
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 4; j++) seats[i][j] = "EMPTY";
    }

    string getID() const { return busID; }

    // Logic to draw the bus layout on the screen
    void displayMap() {
        cout << "\n--- BUS: " << busID << " | ROUTE: " << from << " to " << to << " ---";
        cout << "\n      [A]     [B]     [C]     [D]\n";
        for (int i = 0; i < 10; i++) {
            cout << setw(2) << i + 1 << " | "; // Align row numbers nicely
            for (int j = 0; j < 4; j++) {
                // If the seat string isn't "EMPTY", it prints an X
                cout << (seats[i][j] == "EMPTY" ? "[   ] " : "[ X ] ");
            }
            cout << endl;
        }
    }

    /* RESERVE METHOD: Handles Multi-seat booking and File Printing. */
    void reserve() {
        int numSeats;
        displayMap();

        cout << "How many seats would you like to book? ";
        if (!(cin >> numSeats) || numSeats <= 0) {
            cout << "Error: Invalid count.\n";
            cin.clear(); cin.ignore(1000, '\n');
            return;
        }

        struct SeatCoord { int r; int c; char cChar; };
        vector<SeatCoord> selectedSeats;
        string passengerName;

        for (int i = 0; i < numSeats; i++) {
            int r; char cChar;
            cout << "Select Row (1-10) and Seat Column (A-D) for seat #" << i + 1 << ": ";
            cin >> r >> cChar;

            int c = toupper(cChar) - 'A';
            int actualRow = r - 1;

            if (actualRow >= 0 && actualRow < 10 && c >= 0 && c < 4 && seats[actualRow][c] == "EMPTY") {
                selectedSeats.push_back({actualRow, c, (char)toupper(cChar)});
            } else {
                cout << "Seat " << r << cChar << " is taken or invalid. Transaction Stopped.\n";
                return;
            }
        }

        double totalFare = price * numSeats;
        double pay;
        cout << "Total Fare: $" << totalFare << " | Enter payment: ";
        cin >> pay;

        if (pay >= totalFare) {
            cout << "Enter Passenger Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, passengerName);

            for (auto& s : selectedSeats) {
                seats[s.r][s.c] = passengerName;
            }

            string fileName = "Ticket_" + passengerName + ".txt";
            ofstream ticketFile(fileName);

            if (ticketFile.is_open()) {
                ticketFile << "========================================\n";
                ticketFile << "         OFFICIAL BUS TICKET             \n";
                ticketFile << "========================================\n";
                ticketFile << "Passenger: " << passengerName << "\n";
                ticketFile << "Route:     " << from << " to " << to << "\n";
                ticketFile << "Seats:     ";
                for (auto& s : selectedSeats) ticketFile << (s.r + 1) << s.cChar << " ";
                ticketFile << "\nTotal Paid: $" << totalFare << "\n";
                ticketFile << "========================================\n";
                ticketFile.close();
                cout << "\n[SUCCESS] Ticket printed to " << fileName << "\n";
            }
        } else {
            cout << "Insufficient funds.\n";
        }
    }
};

// ==========================================
// 2. AUTHENTICATION & MAIN CONTROLLER
// ==========================================

class AuthSystem {
private:
    const string adminPass = "admin123";
public:
    bool login() {
        string input;
        cout << "\nAdmin Password: ";
        cin >> input;
        return (input == adminPass);
    }
};

int main() {
    vector<unique_ptr<Bus>> fleet;
    AuthSystem auth;
    int choice;

    while (true) {
        cout << "\n1. Book Seats  2. Admin Panel  3. Exit\nSelection: ";

        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) { // --- CUSTOMER FLOW ---
            if (fleet.empty()) {
                cout << "No buses available.\n";
            } else {
                cout << "\n--- SELECT A BUS ---\n";
                for (size_t i = 0; i < fleet.size(); i++) {
                    // ADJUSTMENT: Now shows ID AND Route (e.g., 1. Bus 001 [Kisumu to Nairobi])
                    cout << i + 1 << ". Bus " << fleet[i]->getID()
                         << " [" << fleet[i]->getRoute() << "]" << endl;
                }

                cout << "Selection: ";
                int bIdx; cin >> bIdx;
                if (bIdx > 0 && bIdx <= fleet.size()) fleet[bIdx - 1]->reserve();
            }
        }
        else if (choice == 2) { // --- ADMIN FLOW ---
            if (auth.login()) {
                bool stayInAdmin = true;
                while (stayInAdmin) {
                    cout << "\n--- ADMIN PANEL ---\n";
                    cout << "1. Add Bus\n2. Remove Bus\n3. Back to Main Menu\nSelection: ";
                    int aOpt;
                    if (!(cin >> aOpt)) { cin.clear(); cin.ignore(1000, '\n'); continue; }

                    if (aOpt == 1) {
                        string id, f, t, d; double p;
                        cout << "ID: "; cin >> id;
                        auto newBus = make_unique<Bus>(id);
                        cout << "From: ";
                        cin >> f;
                        cout << "To: ";
                        cin  >> t;
                        cout << "Time: "; cin >> d; cout << "Price: "; cin >> p;
                        newBus->setDetails(f, t, d, p);
                        fleet.push_back(move(newBus));
                        cout << "Bus successfully added!\n";
                    }
                    else if (aOpt == 2) {
                        string id; cout << "Bus ID to remove: "; cin >> id;
                        bool found = false;
                        for (auto it = fleet.begin(); it != fleet.end(); ++it) {
                            if ((*it)->getID() == id) {
                                fleet.erase(it);
                                cout << "Bus deleted.\n";
                                found = true;
                                break;
                            }
                        }
                        if(!found) cout << "Bus ID not found.\n";
                    }
                    else if (aOpt == 3) {
                        stayInAdmin = false;
                    }
                }
            } else {
                cout << "Invalid Password!\n";
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
    }
    return 0;
}
