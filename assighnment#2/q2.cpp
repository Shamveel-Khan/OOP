#include <iostream>
using namespace std;

class ghost {
    protected:
        string name;
        string type;
        int scareLevel;
    
    public:
    ghost(string n, int s, string t) : name(n), scareLevel(s), type(t) {}
        
    virtual ~ghost() {} 
    
    virtual void haunt() const {  
        cout << name << " is haunting generically!" << endl;
    }
    
    virtual void display() const {
        cout << "\n.................\n";
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Scare Level: " << scareLevel << endl;
        cout << "\n.................\n";
    }
    
    friend ostream& operator<<(ostream& out, const ghost& g) {
            out << "Name: " << g.name << "\n"
            << "Type: " << g.type << "\n"
            << "Scare Level: " << g.scareLevel << "\n";
        return out;
    }
    
    friend ghost operator+(const ghost& g1, const ghost& g2) {
        string newName = g1.name + " & " + g2.name;
        int newLevel = g1.scareLevel + g2.scareLevel;
    
        return ghost(newName, newLevel, "Mixed ghost"); 
    }
};

class Poltergeist : virtual public ghost {
public:
    Poltergeist(string n, int s) : ghost(n, s, "Poltergeist") {}

    void haunt() const override {
        cout << name << " moves objects!" << endl;
    }
};

class Banshee : public ghost {
public:
    Banshee(string n, int s) : ghost(n, s, "Banshee") {}

    void haunt() const override {
        cout << name << " screams loudly!" << endl;
    }
};

class Shadowghost : virtual public ghost {
public:
    Shadowghost(string n, int s) : ghost(n, s, "Shadowghost") {}

    void haunt() const override {
        cout << name << " whispers creepily..." << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public Shadowghost {
public:
    ShadowPoltergeist(string n, int s)
        : ghost(n, s, "ShadowPoltergeist"), Poltergeist(n, s), Shadowghost(n, s) {}

    void haunt() const override {
        Poltergeist::haunt();  
        Shadowghost::haunt(); 
    }
};

int main() {
    
}
