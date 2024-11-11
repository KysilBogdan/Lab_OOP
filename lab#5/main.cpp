#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    // Структура для зберігання даних книги
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

    // Статичний метод для фільтрації книг за автором
    static void displayBooksByAuthor(const vector<Book>& books, const string& authorName) {
        bool found = false;
        for (const auto& book : books) {
            if (book.data.author == authorName) {
                book.displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "\nНемає книг цього автора." << endl;
        }
    }
};

int main() {
    vector<Book> books; // Колекція книг

    // Створення кількох екземплярів класу Book
    books.push_back(Book("To Kill a Mockingbird", "Harper Lee", 250));
    books.push_back(Book("1984", "George Orwell", 200));
    books.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", 150));
    books.push_back(Book("Moby Dick", "Herman Melville", -100));  // Некоректна ціна
    books.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 350));

    // Виведення інформації про всі книги
    cout << "Інформація про всі книги:\n";
    for (const auto& book : books) {
        book.displayInfo();
    }

    // Фільтрація книг за ціною
    double minPrice;
    cout << "\nВведіть мінімальну ціну для фільтрації книг: ";
    cin >> minPrice;
    Book::displayBooksByPrice(books, minPrice);

    // Фільтрація книг за автором
    string authorName;
    cout << "\nВведіть ім'я автора для фільтрації книг: ";
    cin.ignore(); // Очистка буфера після вводу числа
    getline(cin, authorName);
    Book::displayBooksByAuthor(books, authorName);

    return 0;
}
