#include <iostream>
#include <algorithm>
using namespace std;

class Product
{
    int id;
    string name;
    int quantity;

public:
    Product(int id, string n, int q)
    {
        this->id = id;
        this->name = n;
        this->quantity = q;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }

    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

bool compareByName(Product *a, Product *b)
{
    return a->getName() < b->getName();
}

class Inventory
{
    string name;
    int numberOfProducts;
    Product **list;
    int capacity;

public:
    Inventory(int cap, string invName)
    {
        name = invName;
        numberOfProducts = 0;
        capacity = cap;
        list = new Product *[capacity];
    }

    void addProduct(Product *p)
    {
        if (numberOfProducts < capacity)
        {
            list[numberOfProducts++] = p;
        }
        else
        {
            cout << "Inventory is full!" << endl;
        }
    }

    void sortProducts()
    {
        sort(list, list + numberOfProducts, compareByName);
    }

    void searchById(int id)
    {
        for (int i = 0; i < numberOfProducts; i++)
        {
            if (list[i]->getId() == id)
            {
                cout << "Product found:\n";
                list[i]->display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found.\n";
    }

    void displayProducts()
    {
        cout << "Product List:\n";
        for (int i = 0; i < numberOfProducts; i++)
        {
            list[i]->display();
        }
    }

    ~Inventory()
    {
        delete[] list;
    }
};

int main()
{
    Inventory warehouse(5, "Warehouse");

    Product p1(101, "Laptop", 5);
    Product p2(102, "Mouse", 10);
    Product p3(103, "Keyboard", 7);
    Product p4(104, "Monitor", 3);
    Product p5(105, "Chair", 8);

    warehouse.addProduct(&p1);
    warehouse.addProduct(&p2);
    warehouse.addProduct(&p3);
    warehouse.addProduct(&p4);
    warehouse.addProduct(&p5);

    cout << "Before Sorting:\n";
    warehouse.displayProducts();

    warehouse.sortProducts();

    cout << "\nAfter Sorting:\n";
    warehouse.displayProducts();

    int n;
    cout << "enter id to search for: ";
    cin >> n;
    cout << "\nSearching for product with ID:" << n << "\n";
    warehouse.searchById(n);

    return 0;
}