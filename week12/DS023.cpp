#include <iostream>
#include <cstring> // 문자열 처리를 위해 사용

using namespace std;

class Product {
private:
    char name[50];
    int price;
    int discount;
    char manufacturer[30];
    char size[20];

public:
    // 생성자
    Product() {
        strcpy(name, "");
        price = 0;
        discount = 0;
        strcpy(manufacturer, "");
        strcpy(size, "");
    }

    // 상품 정보 입력
    void input() {
        cout << "Enter product name: ";
        cin.ignore();
        cin.getline(name, 50);
        
        cout << "Enter product price: ";
        cin >> price;

        cout << "Enter discount rate (%): ";
        cin >> discount;

        cout << "Enter product size: ";
        cin >> size;

        cout << "Enter manufacturer: ";
        cin >> manufacturer;
    }

    // 상품 정보 출력
    void output() const {
        int discounted_price = calculateDiscountedPrice();
        cout << discounted_price << " (";
        if (discount != 0) {
            cout << "-" << discount << "%) ";
        } else {
            cout << "0%) ";
        }
        cout << name << " " << size << " " << manufacturer << endl;
    }

    // 할인율에 따른 판매 가격 계산기
    int calculateDiscountedPrice() const {
        return price - (price * discount / 100);
    }
};

class ProductManager {
private:
    Product* products[100];
    int product_count;

public:
    // 생성자
    ProductManager() : product_count(0) {}

    // 소멸자
    ~ProductManager() {
        for (int i = 0; i < product_count; ++i) {
            delete products[i];
        }
    }

    // 상품 추가
    void addProduct() {
        if (product_count < 100) {
            products[product_count] = new Product();
            products[product_count]->input();
            ++product_count;
        } else {
            cout << "Cannot add more products. List is full." << endl;
        }
    }

    // 상품 목록 출력
    void listProducts() const {
        for (int i = 0; i < product_count; ++i) {
            products[i]->output();
        }
    }
};

int main() {
    ProductManager manager;
    int choice;

    do {
        cout << "1. Add 2. List 3. Quit > ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addProduct();
            break;
        case 2:
            manager.listProducts();
            break;
        case 3:
            cout << "Quitting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
