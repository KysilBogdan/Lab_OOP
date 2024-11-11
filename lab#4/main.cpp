#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Book {
private:
    string title;   // Назва книги
    string author;  // Автор книги
    double price;   // Ціна книги

public:
    // Конструктор за замовчуванням
    Book() : title(""), author(""), price(0.0) {}

    // Конструктор з параметрами
    Book(string t, string a, double p) : title(t), author(a), price(p) {}

    // Метод для введення даних
    void inputData() {
        cout << "Enter book title: ";
        cin.ignore();  
        getline(cin, title);  // Вводимо назву книги
        
        cout << "Enter author: ";
        getline(cin, author);  // Вводимо автора
        
        cout << "Enter price: ";
        while (!(cin >> price)) { // перевірка на коректність введення ціни
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Неправильне введення ціни. Будь ласка, введіть правильну ціну: ";
        }
    }

    // Метод для виведення даних
    void outputData() const {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
    }

    // Метод для присвоєння значення полям
    void setData(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    // Методи для отримання значень полів
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    // Створення екземпляра класу
    Book book1; // за замовчуванням
    Book book2("The Catcher in the Rye", "J.D. Salinger", 15.99); // з параметром

    // Виведення початкових даних
    cout << "Initial data for book1:" << endl;
    book1.outputData();
    cout << "\nInitial data for book2:" << endl;
    book2.outputData();

    // Введення нових даних для book1
    cout << "\nEnter new details for book1:" << endl;
    book1.inputData();

    // Виведення даних обох книг після введення
    cout << "\nData for book1:" << endl;
    book1.outputData();
    cout << "\nData for book2:" << endl;
    book2.outputData();

    return 0;
}
