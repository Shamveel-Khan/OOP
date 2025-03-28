#include <iostream>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double pr, string d, string dest)
        : ticketID(id), passengerName(name), price(pr), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << " to " << destination << " on " << date << "\n";
    }
    
    virtual void cancel() {
        cout << "Ticket with ID " << ticketID << " has been cancelled.\n";
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << "\nPassenger: " << passengerName
             << "\nPrice: " << price << "\nDate: " << date << "\nDestination: " << destination << "\n";
    }
};

class FlightTicket : public Ticket {
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double pr, string d, string dest, string airline, string flight, string seat)
        : Ticket(id, name, pr, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight Number: " << flightNumber << "\nSeat Class: " << seatClass << "\n";
    }
};

class TrainTicket : public Ticket {
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double pr, string d, string dest, string train, string coach, string time)
        : Ticket(id, name, pr, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        cout << "Train seat auto-assigned for " << passengerName << " on " << trainNumber << "\n";
    }
};

class BusTicket : public Ticket {
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double pr, string d, string dest, string company, int seat)
        : Ticket(id, name, pr, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout << "Last-minute refund available for bus ticket " << ticketID << "\n";
    }
};

class ConcertTicket : public Ticket {
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double pr, string d, string dest, string artist, string v, string seat)
        : Ticket(id, name, pr, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << "\n";
    }
};

int main() {
    FlightTicket f1(101, "Ali Khan", 50000, "2025-04-10", "Karachi", "PIA", "PK301", "Business");
    f1.displayTicketInfo();

    TrainTicket t1(102, "Ahmed Raza", 3000, "2025-05-15", "Lahore", "Green Line", "Economy", "10:00 AM");
    t1.reserve();

    BusTicket b1(103, "Hassan Ali", 1500, "2025-04-05", "Islamabad", "Daewoo", 12);
    b1.cancel();

    ConcertTicket c1(104, "Sara Khan", 5000, "2025-06-20", "Karachi", "Atif Aslam", "Expo Center", "VIP");
    c1.displayTicketInfo();

    return 0;
}