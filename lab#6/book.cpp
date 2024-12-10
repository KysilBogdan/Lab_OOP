#include "book.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <vector>

using namespace std;

Book::Book() : title("Harry Potter 1"), author("J. Rowling"), price(450) {
}

Book::Book(const string& title, const string& author, double price) {
    if (!isValidString(title) || !isValidString(author) || !isValidPrice(price)) {
        throw invalid_argument("Некоректні дані для створення книги.");
    }
    this->title = title;
    this->author = author;
    this->price = price;
}

Book::~Book() {
}

bool Book::isValidString(const string& input) const {
    return !input.empty();
}

bool Book::isValidPrice(double input) const {
    return input > 0.0;
}

void Book::setTitle(const string& title) {
    if (isValidString(title)) {
        this->title = title;
    } else {
        cout << "Помилка: Назва книги не може бути порожньою.\n";
    }
}

void Book::setAuthor(const string& author) {
    if (isValidString(author)) {
        this->author = author;
    } else {
        cout << "Помилка: Автор книги не може бути порожнім.\n";
    }
}

void Book::setPrice(double price) {
    if (isValidPrice(price)) {
        this->price = price;
    } else {
        cout << "Помилка: Ціна повинна бути додатнім числом.\n";
    }
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

double Book::getPrice() const {
    return price;
}

void Book::display() const {
    cout << "Назва: " << title 
         << "\nАвтор: " << author 
         << "\nЦіна: " << price << " грн\n";
}

void Book::inputDetails() {
    string inputTitle, inputAuthor;
    double inputPrice;

    cout << "Введіть назву книги: ";
    getline(cin, inputTitle);
    while (!isValidString(inputTitle)) {
        cout << "Помилка: Назва книги не може бути порожньою. Спробуйте ще раз: ";
        getline(cin, inputTitle);
    }
    setTitle(inputTitle);

    cout << "Введіть автора книги: ";
    getline(cin, inputAuthor);
    while (!isValidString(inputAuthor)) {
        cout << "Помилка: Автор книги не може бути порожнім. Спробуйте ще раз: ";
        getline(cin, inputAuthor);
    }
    setAuthor(inputAuthor);

    cout << "Введіть ціну книги: ";
    while (!(cin >> inputPrice) || !isValidPrice(inputPrice)) {
        cout << "Помилка: Ціна повинна бути додатнім числом. Спробуйте ще раз: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setPrice(inputPrice);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистити буфер
}

// Статичний метод для фільтрації книг за мінімальною ціною
void Book::displayBooksByMinPrice(const vector<Book>& books, double minPrice) {
    cout << "\nКниги з ціною від " << minPrice << " грн і вище:\n";
    for (const auto& book : books) {
        if (book.getPrice() >= minPrice) {
            book.display();
        }
    }
}
