#include <iostream>
#include <vector>
#include <limits>
#include "book.h"
#include "book.cpp"

using namespace std;

// Функція для очищення буфера введення
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функція для перевірки правильності введення ціни
double getValidPriceInput() {
    double inputPrice;
    while (true) {
        cout << "Введіть мінімальну ціну для фільтрації: ";
        cin >> inputPrice;

        if (cin.fail()) {
            clearInputBuffer();
            cout << "Помилка: Введіть числове значення.\n";
        } else if (inputPrice < 0) {
            cout << "Помилка: Ціна не може бути від'ємною. Спробуйте ще раз.\n";
        } else {
            return inputPrice;
        }
    }
}

int getValidBookIDInput(const vector<Book>& books, const string& operationDescription) {
    int id;
    while (true) {
        cout << operationDescription << " (ID книги): ";
        if (!(cin >> id)) {
            clearInputBuffer();
            cout << "Помилка: Введіть числове значення.\n";
        } else if (id < 1 || id > books.size()) {
            cout << "Помилка: ID книги не існує. Спробуйте ще раз.\n";
        } else {
            return id - 1; // Повертаємо індекс (ID - 1) для вектора
        }
    }
}

int main() {
    vector<Book> books;

    // Ініціалізація двома книгами
    Book book1("Гаррі Поттер і Таємна кімната", "Дж. Роулінг", 200.0);
    Book book2("Зелена миля", "Стівен Кінг", 300.0);
    books.push_back(book1);
    books.push_back(book2);

    // Виведення всіх книг перед запитом нових даних
    cout << "Існуючі книги в базі даних:\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "ID: " << i + 1 << " ";
        books[i].display();
    }

    // Операція додавання нової книги
    cout << "\nОперація: Додавання нової книги\n";
    Book userBook;
    userBook.inputDetails();
    books.push_back(userBook);

    // Операція оновлення даних книги
    cout << "\nОперація: Оновлення даних книги\n";
    int bookIDToUpdate = getValidBookIDInput(books, "Введіть ID книги для оновлення");
    clearInputBuffer();  // Очищення буфера перед введенням
    books[bookIDToUpdate].inputDetails();

    // Операція фільтрації книг за ціною
    double minPrice = getValidPriceInput();
    cout << "\nОперація: Фільтрація книг за ціною\n";
    cout << "Книги з ціною від " << minPrice << " грн і вище:\n";
    Book::displayBooksByMinPrice(books, minPrice);

    // Операція видалення книги
    cout << "\nОперація: Видалення книги\n";
    int bookIDToDelete = getValidBookIDInput(books, "Введіть ID книги для видалення");
    books.erase(books.begin() + bookIDToDelete);
    cout << "Книга з ID " << bookIDToDelete + 1 << " була видалена.\n";

    // Виведення всіх книг після видалення
    cout << "\nУсі книги після видалення:\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "ID: " << i + 1 << " ";
        books[i].display();
    }

    // Операція обміну місцями двох книг
    cout << "\nОперація: Обмін місцями двох книг\n";
    int firstID = getValidBookIDInput(books, "Введіть ID першої книги для обміну місцями");
    int secondID = getValidBookIDInput(books, "Введіть ID другої книги для обміну місцями");
    if (firstID != secondID) {
        swap(books[firstID], books[secondID]);
        cout << "Книги з ID " << firstID + 1 << " та " << secondID + 1 << " обміняні місцями.\n";
    } else {
        cout << "ID однакові, обмін не виконано.\n";
    }

    // Операція додавання нової книги після певного ID
    cout << "\nОперація: Додавання нової книги після певного ID\n";
    int insertID = getValidBookIDInput(books, "Введіть ID книги після якої потрібно додати нову книгу");
    clearInputBuffer();  // Очищення буфера перед введенням
    cout << "Введіть дані для нової книги:\n";
    Book newBook;
    newBook.inputDetails();
    books.insert(books.begin() + insertID + 1, newBook);
    cout << "Нова книга додана після книги з ID " << insertID + 1 << ".\n";

    // Виведення всіх книг після змін
    cout << "\nУсі книги після змін:\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "ID: " << i + 1 << " ";
        books[i].display();
    }

    return 0;
}
