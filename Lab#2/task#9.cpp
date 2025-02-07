#include <iostream>
using namespace std;

struct product {
    int productId;
    string name;
    int quantity;
    int price;
};

int main() {
    int n;
    cout<<"enter number of products: ";
    cin>>n;
    product* list = new product[n];
    int sum=0;
    for(int i=0;i<n;i++) {
        cout<<"input for product# "<<i+1<<endl;
        cout<<"input id: ";
        cin>>list[i].productId;
        cout<<"input name: ";
        cin>>list[i].name;
        cout<<"input quantity: ";
        cin>>list[i].quantity;
        cout<<"input price: ";
        cin>>list[i].price;
        cout<<endl;
        sum+= list[i].quantity * list[i].price;
    }
    cout<<"the total sum was: "<<sum;
    delete [] list;
}