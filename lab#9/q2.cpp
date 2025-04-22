#include <iostream>
#include <string>

using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string dishName, double price) : dishName(dishName), price(price) {}
    
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
    
    string getDishName() const { return dishName; }
    double getPrice() const { return price; }
};

class Appetizer : public MenuItem {
private:
    bool isSpicy;
    bool needsGarnish;

public:
    Appetizer(string dishName, double price, bool isSpicy, bool needsGarnish) 
        : MenuItem(dishName, price), isSpicy(isSpicy), needsGarnish(needsGarnish) {}
    
    void showDetails() override {
        cout << "Appetizer: " << dishName << " (Price: $" << price << ")" << endl;
        cout << "- " << (isSpicy ? "Spicy" : "Mild") << endl;
        cout << "- " << (needsGarnish ? "Served with garnish" : "No garnish") << endl;
        cout << "- Preparation time: 10-15 minutes" << endl;
    }
    
    void prepare() override {
        cout << "Preparing appetizer " << dishName << ":" << endl;
        cout << "1. Gather fresh ingredients" << endl;
        cout << "2. Combine ingredients according to recipe" << endl;
        if (needsGarnish) {
            cout << "3. Add garnish for presentation" << endl;
        }
        if (isSpicy) {
            cout << "4. Add spices to taste" << endl;
        }
        cout << "5. Plate and serve immediately" << endl;
    }
};

class MainCourse : public MenuItem {
private:
    int cookTimeMinutes;
    string sideDish;

public:
    MainCourse(string dishName, double price, int cookTimeMinutes, string sideDish) 
        : MenuItem(dishName, price), cookTimeMinutes(cookTimeMinutes), sideDish(sideDish) {}
    
    void showDetails() override {
        cout << "Main Course: " << dishName << " (Price: $" << price << ")" << endl;
        cout << "- Cook time: " << cookTimeMinutes << " minutes" << endl;
        cout << "- Served with: " << sideDish << endl;
        cout << "- Full portion size" << endl;
    }
    
    void prepare() override {
        cout << "Preparing main course " << dishName << ":" << endl;
        cout << "1. Prepare ingredients and seasonings" << endl;
        cout << "2. Heat cooking surface to appropriate temperature" << endl;
        cout << "3. Cook main ingredients for " << cookTimeMinutes << " minutes" << endl;
        cout << "4. Prepare " << sideDish << " as side dish" << endl;
        cout << "5. Plate main dish with " << sideDish << endl;
        cout << "6. Add final seasoning and serve" << endl;
    }
};

int main() {
    MenuItem* dishes[4];
    
    dishes[0] = new Appetizer("Shamveel's Samosas", 7.99, true, true);
    dishes[1] = new Appetizer("Usman's Spring Rolls", 6.50, false, true);
    dishes[2] = new MainCourse("Moiz's Biryani", 15.99, 30, "Raita");
    dishes[3] = new MainCourse("Abdullah's Karahi", 17.50, 25, "Naan");
    
    for (int i = 0; i < 4; i++) {
        cout << "\n===================================" << endl;
        dishes[i]->showDetails();
        cout << "\n";
        dishes[i]->prepare();
    }
    
    for (int i = 0; i < 4; i++) {
        delete dishes[i];
    }
    
    return 0;
}