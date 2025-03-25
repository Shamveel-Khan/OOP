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
    
    int getScarelevel() {
        return scareLevel;
    }

    virtual void haunt() const {  
        cout << name << " is haunting!" << endl;
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

class visitor {
    string name;
    int braveryLevel;
    public:
        visitor(string n,int bl):name(n),braveryLevel(bl) {}
        void react(int g) {
            if(g+1>braveryLevel) {
                cout<<"\nVisitor ran away!!\n";
            }
            else if(g+1<braveryLevel) {
                cout<<"\nVisitor laughs!!\n";
            }
            else {
                cout<<"\nVisitor Stays!!\n";
            }
        }
        void display() const {
            cout << "\n.................\n";
            cout<<"Name: "<<name<<endl;
            cout<<"Bravery Level: "<<braveryLevel<<endl;
            cout << "\n.................\n";
        }
};

class hauntedHouse {
    string name;
    ghost** listGhosts;
    int ghostCount;
    int TotalGhostCapacity;
    public:
        hauntedHouse(string n,int tgc): name(n),TotalGhostCapacity(tgc) {
            listGhosts = new ghost*[TotalGhostCapacity];
            ghostCount=0;
        }
        void addGhost(ghost* g) {
            listGhosts[ghostCount++]=g;
        }
        void displayGhost() const {
            cout<<"\n---Displaying All Ghost---\n";
            for(int i =0;i<ghostCount;i++) {
                listGhosts[i]->display();
                cout<<" \n ";
            }
            cout<<".......................\n";
        }
        int totalScareLevels() {
            int sum=0;
            for(int i=0;i<ghostCount;i++) {
                sum += listGhosts[i]->getScarelevel();
            }
            return sum;
        }
        void visit(visitor* list,int visitorCount) {
            int  j=0;
            for(int i=0;i<visitorCount;i++) {
                list[i].react(listGhosts[j%ghostCount]->getScarelevel());
                cout<<endl;
                j++;
            }
        }
};   

int main() {
    hauntedHouse hh("Bhoot Bangla", 5);

    ghost* g1 = new Poltergeist("Shamveel", 5);
    ghost* g2 = new Banshee("Moiz", 8);
    ghost* g3 = new Shadowghost("Usman", 6);
    ghost* g4 = new ShadowPoltergeist("Kabeer", 10);
    ghost* g5 = new Poltergeist("Abdullah", 4);

    hh.addGhost(g1);
    hh.addGhost(g2);
    hh.addGhost(g3);
    hh.addGhost(g4);
    hh.addGhost(g5);

    hh.displayGhost();
    cout << "Total Scare Level: " << hh.totalScareLevels() << endl;

    visitor v1("Ali",7);
    visitor v2("Hassan",9);
    visitor v3("Hamza",5);
    visitor visitors[3] = {v1,v2,v3};
    hh.visit(visitors, 3);

    delete g1;
    delete g2;
    delete g3;
    delete g4;
    delete g5;

    return 0;
}
