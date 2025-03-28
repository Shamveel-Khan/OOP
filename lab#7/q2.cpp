#include <iostream>
using namespace std;

class product
{
protected:
    int productId;
    string name;
    double price;
    int stock;

public:
    product(int p, string s, double pr, int st) : productId(p), name(s), price(pr), stock(st) {}
    virtual double applyDiscount()
    {
        return price * 0.8; // 20% discount
    }
    virtual double calculateTotalPrice(int quantity)
    {
        return price * quantity;
    }
    virtual void displayProductInfo()
    {
        cout << ".................\n";
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << ".................\n";
    }
    product operator+(product &p)
    {
        return product(productId, name, price + p.price, stock);
    }
    friend ostream &operator<<(ostream &os, const product &p)
    {
        os << "Product ID: " << p.productId << endl
           << "Product Name: " << p.name << endl
           << "Price: " << p.price << endl
           << "Stock: " << p.stock << endl;
        return os;
    }
};

class electronics : public product
{
    int warranty; // in months
    string brand;

public:
    electronics(int p, string s, double pr, int st, int w, string b)
        : product(p, s, pr, st), warranty(w), brand(b) {}

    void displayProductInfo() override
    {
        cout << ".................\n";
        cout << "Warranty: " << warranty << endl;
        cout << "Brand: " << brand << endl;
        cout << ".................\n";
    }
};

class clothes : public product
{
    string color;
    string size;
    string fabricMaterial;

public:
    clothes(int p, string s, double pr, int st, string c, string sz, string fm)
        : product(p, s, pr, st), color(c), size(sz), fabricMaterial(fm) {}

    double applyDiscount() override
    {
        if (fabricMaterial == "Thick")
        {
            return price * 0.7;
        }
        else
        {
            return price * 0.8;
        }
    }
};

class foodItem : public product
{
    string expiryDate;
    int calories;

public:
    foodItem(int p, string s, double pr, int st, string ed, int cal)
        : product(p, s, pr, st), expiryDate(ed), calories(cal) {}

    double calculateTotalPrice(int quantity) override
    {
        if (quantity > 10)
        {
            return price * quantity * 0.8;
        }
        else
        {
            return price * quantity;
        }
    }
};

class book : public product
{
    string author;
    string genre;

public:
    book(int p, string s, double pr, int st, string a, string g)
        : product(p, s, pr, st), author(a), genre(g) {}

    void displayProductInfo() override
    {
        cout << ".................\n";
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << ".................\n";
    }
};

int main()
{
    cout << " \n ";
    electronics e1(101, "Infinix Smart 7", 25000, 15, 12, "Infinix");
    e1.displayProductInfo();

    clothes c1(102, "Kurta", 4500, 30, "Blue", "Medium", "Cotton");
    cout << "Original Price: " << c1.calculateTotalPrice(1) << endl;
    cout << "Discounted Price: " << c1.applyDiscount() << endl;

    foodItem f1(103, "Cola Next Bottle", 100, 50, "one year later", 100);
    cout << "Total Price for 5 items: " << f1.calculateTotalPrice(5) << endl;
    cout << "Total Price for 12 items (Bulk Discount): " << f1.calculateTotalPrice(12) << endl;

    book b1(104, "Anton calculas", 1200, 20, "Shamveel", "Math");
    b1.displayProductInfo();

    return 0;
}
