#include <iostream>
#include <vector>
#include <limits>
#include "book.h"

using namespace std;

// Функція для перевірки правильності введення ціни
double getValidPriceInput() {
    double inputPrice;
    while (true) {
        cout << "Введіть мінімальну ціну для фільтрації: ";
        cin >> inputPrice;
        
        // Перевірка на некоректний ввід
        if (cin.fail()) {
            cin.clear(); // Очищення помилки вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера
            cout << "Помилка: Введіть числове значення.\n";
        } else if (inputPrice < 0) {
            cout << "Помилка: Ціна не може бути від'ємною. Спробуйте ще раз.\n";
        } else {
            return inputPrice;
        }
    }
}

int getValidBookIDInput(const vector<Book>& books) {
    int id;
    while (true) {
        cout << "Введіть ID книги для видалення: ";
        if (!(cin >> id)) {
            cin.clear(); // Очищення помилки вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера
            cout << "Помилка: Введіть числове значення.\n";
        } else if (id < 0 || id >= books.size()) {
            cout << "Помилка: ID книги не існує. Спробуйте ще раз.\n";
        } else {
            return id;
        }
    }
}

int main() {
    vector<Book> books;

    // Створення книги за замовчуванням і додавання до вектора
    Book defaultBook;
    books.push_back(defaultBook);

    // Виведення всіх книг перед запитом нових даних
    cout << "Існуючі книги в базі даних:\n";
    for (const auto& book : books) {
        book.display();
    }

    // Введення даних користувачем
    cout << "\nВведіть дані книги:" << endl;
    Book userBook;
    userBook.inputDetails();
    books.push_back(userBook);

    // Оновлення даних книги
    cout << "\nОновлення даних книги:" << endl;
    userBook.setTitle("Хоббіт");
    userBook.setAuthor("Дж. Р. Р. Толкін");
    userBook.setPrice(300.0);
    books.push_back(userBook);

    // Виведення книг, що відповідають мінімальній ціні
    double minPrice = getValidPriceInput();
    cout << "\nКниги з ціною від " << minPrice << " грн і вище:\n";
    Book::displayBooksByMinPrice(books, minPrice);

    // Видалення книги за ID
    int bookIDToDelete = getValidBookIDInput(books);
    books.erase(books.begin() + bookIDToDelete);
    cout << "\nКнига з ID " << bookIDToDelete << " була видалена.\n";

    // Виведення всіх книг після видалення
    cout << "\nКниги після видалення:\n";
    for (const auto& book : books) {
        book.display();
    }

    return 0;
}
