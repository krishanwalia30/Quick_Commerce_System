#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include <set>

class DeliveryPerson{
    string name;
    int phoneNo;
    
    public: 
        DeliveryPerson(string name, int phoneNo): name(name), phoneNo(phoneNo) {}
        
        pair<string, int> showDeliveryPersonDetail(){
            return make_pair(name, phoneNo);
        }
        void displayDeliveryPerson() const {
            std::cout << "Delivery Person: " << name << ", Phone: " << phoneNo << std::endl;
        }   
};

class Product {
    string productName;
    int price;
    
    public:
        Product(string productName, int price): productName(productName), price(price) {}
        
        pair<string, int> showProductDetail(){
            return make_pair(productName, price);
        }
        
        int getPrice(){
            return price;
        }
        
        string getProductName(){
            return productName;
        }
};

class Cart {
    vector<Product> productsInCart;
    
    public:
        void addToCart(Product& product) {
            productsInCart.push_back(product);
        }
        float totalAmount() {
            float sum =0;
            for (Product x: productsInCart){
                sum += x.getPrice();
            }
            return sum;
        }
        
        int totalItems(){
            return productsInCart.size();
        }
};

// Order class definition
class Order {
    Cart& cart;
    double totalAmount;
    // std::time_t orderTime;
    DeliveryPerson deliveryPerson;
    double totalQuantity;

public:
    Order(Cart& cart, DeliveryPerson& deliveryPerson)
        : cart(cart), totalAmount(cart.totalAmount()), deliveryPerson(deliveryPerson), totalQuantity(cart.totalItems()) {}

    void displayOrder() const {
        cout << "Order Total: $" << totalAmount << ", Items Count: " << cart.totalItems() <<endl;
    }

    void displayDeliveryDetails() const {
        deliveryPerson.displayDeliveryPerson();
    }

    int getRemainingTime() const {
        return 10; // Assuming 10 minutes for the sake of simplicity
    }
    
    int orderTotal() {
        return totalAmount;
    }
    
    int orderQuantity() {
        return totalQuantity;
    }
};

class User {
    string name;
    int phoneNo;
    // vector<pair<int, int>> orderHistory;
    vector<Order> orderHistory;

    public:
        User(string s, int pno){
            name=s;
            phoneNo=pno;
        }
        
        void placeOrder(Order& order) {
            orderHistory.push_back(order);
            
            cout<< "Order Placed SUccessfully!"<<endl;
        }
        
        void showOrderHistory() {
            cout<< "ItemCount" << "\t\t\t" << "Amount" << "\t\t\t" << endl;
            for (Order o: orderHistory ) {
                // o.displayOrder();
                cout << o.orderQuantity() << "\t\t\t\t\t" << o.orderTotal() << endl;
            }
        }
        
        void trackOrder() {
            
            cout << "Remaining Time: " << (orderHistory.back()).getRemainingTime()<<endl;
            (orderHistory.back()).displayDeliveryDetails();
        }
};


void showMenu(vector<Product> menu) {
    cout << "Product Name" << "\t\t\t\t" << "Product Price" << endl;
    for (int i=0; i< menu.size();i++) {
        Product x = menu[i];
        cout <<i+1<<". "<< x.getProductName() << "\t\t\t\t\t\t" << x.getPrice()<< endl;
    }
}

vector<DeliveryPerson> availableStaff = {
    DeliveryPerson("Abhi", 9090909),
    DeliveryPerson("Ram", 9090901),
    DeliveryPerson("Rahul", 9090902),
    DeliveryPerson("Ravi", 9090903),
    DeliveryPerson("Amit", 9090903),
    DeliveryPerson("Sameer", 9090903),
    DeliveryPerson("Soham", 9090903),
};
vector<Product> menu = {
    Product("Apple", 10),
    Product("Banana", 20),
    Product("Bread", 60),
    Product("Litchi",60 ),
    Product("Kiwi  ", 50),
    Product("Butter", 50),
    Product("Milk  ", 55),
    Product("Parle G", 40),
    Product("Walnuts", 70),
    Product("Almonds", 50),
    Product("Cheery", 50),
};

int main(){
    set<int> registeredUsers;
    
    User u = User("abc", 9090);
    
    int choice = 0;
    while(choice != 4){
        cout << endl<<"--------------------";
        cout << endl << "QUICK COMMERCE SYSTEM" << endl;
        cout << "--------------------"<<endl;
        cout<< "Choose from the below options,"<<endl;
        // cout << "--------------------"<<endl;
        cout << "1. Place Order" << endl;
        cout << "2. Order History" << endl;
        cout << "3. Track Last Order" << endl;
        cout << "--------------------"<<endl;
        cout << "Enter Your Choice: ";
        cin >> choice ;
        
        if (choice == 1) {
            cout <<endl<< "--------------------"<<endl;
            cout << "CHOOSE FROM THE MENU"<<endl;
            cout << "--------------------"<<endl;
            showMenu(menu);
            Cart userCart;
            cout << endl << "Enter item indexes to be added to the cart, followed by a '0' to confirm."<< endl;
            cout<< "Items: ";

            int j;
            while(cin>>j){
                if (j> 0){
                    // addedProducts.push_back(menu[j-1]);
                    userCart.addToCart(menu[j-1]);
                }
                else{
                    break;
                }
            }
            
            // Place the order.
            Order order = Order(userCart, availableStaff[0]);
            order.displayOrder();
            order.displayDeliveryDetails();
            u.placeOrder(order);
        }
        else if (choice == 2){
            u.showOrderHistory();
        }
        else if (choice ==3) {
            u.trackOrder();
        }
    }
    return 0;
}
