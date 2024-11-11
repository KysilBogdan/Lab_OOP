#include <iostream>
#include <string>
#include <vector>
#include <limits> // Для numeric_limits
using namespace std;

class Book {
public:
    struct BookData {
        string title;  // Назва книги
        string author; // Автор книги
        double price;  // Ціна книги
    };

    BookData data; // Поле класу для зберігання даних

    // Конструктор класу для ініціалізації даних
    Book(string t, string a, double p) {
        setData(t, a, p);  // Викликаємо setData для перевірки правильності введених даних
    }

    // Метод для встановлення даних з перевіркою
    void setData(string t, string a, double p) {
        if (t.empty()) {
            cout << "Назва книги не може бути порожньою!" << endl;
            return;
        }
        if (a.empty()) {
            cout << "Автор книги не може бути порожнім!" << endl;
            return;
        }
        if (p <= 0) {
            cout << "Ціна книги повинна бути більше 0!" << endl;
            return;
        }
        data.title = t;
        data.author = a;
        data.price = p;
    }

    // Метод для виведення інформації про книгу
    void displayInfo() const {
        cout << "\nНазва книги: " << data.title 
             << "\nАвтор: " << data.author 
             << "\nЦіна: " << data.price << " грн" << endl;
    }

    // Статичний метод для фільтрації та виведення книг за критерієм ціни
    static void displayBooksByPrice(const vector<Book>& books, double minPrice) {
        bool found = false;
        for (const auto& book : books) {
            if (book.data.price >= minPrice) {
                book.displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "\nНемає книг з ціною вище або рівною " << minPrice << " грн." << endl;
        }
    }

};

int main() {
    vector<Book> books; // Колекція книг

    // Створення кількох екземплярів класу Book
    books.push_back(Book("To Kill a Mockingbird", "Harper Lee", 250));
    books.push_back(Book("1984", "George Orwell", 200));
    books.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", 150));
    books.push_back(Book("Moby Dick", "Herman Melville", 100));  // Некоректна ціна
    books.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 350));

    // Виведення інформації про всі книги
    cout << "Інформація про всі книги:\n";
    for (const auto& book : books) {
        book.displayInfo();
    }

    // Додатковий ввід книги від користувача
    string title, author;
    double price;

    cout << "\nВведіть дані для нової книги:" << endl;
    cout << "Назва книги: ";
    getline(cin, title); // Читаємо назву книги

    cout << "Автор книги: ";
    getline(cin, author); // Читаємо автора книги

    // Для введення ціни використаємо getline і потім конвертуємо
    cout << "Ціна книги: ";
    string priceStr;
    getline(cin, priceStr); // Читаємо ціну як рядок

    // Перетворення введеної ціни на число
    try {
        price = stod(priceStr); // Перетворюємо рядок на число
        if (price <= 0) {
            throw invalid_argument("Ціна повинна бути більше 0");
        }
    } catch (...) {
        cout << "Введена ціна некоректна!" << endl;
        return 1;
    }

    // Додавання нової книги до вектору
    Book newBook(title, author, price);
    books.push_back(newBook); // Додаємо нову книгу в колекцію

    // Виведення інформації про всі книги після додавання нової
    cout << "\nІнформація про всі книги після додавання нової:\n";
    for (const auto& book : books) {
        book.displayInfo();
    }

    // Фільтрація книг за ціною
    double minPrice;
    cout << "\nВведіть мінімальну ціну для фільтрації книг: ";
    string minPriceStr;
    getline(cin, minPriceStr); // Читаємо мінімальну ціну як рядок
    try {
        minPrice = stod(minPriceStr); // Перетворюємо на число
        Book::displayBooksByPrice(books, minPrice);
    } catch (...) {
        cout << "Введена ціна некоректна!" << endl;
    }

    return 0;
}
