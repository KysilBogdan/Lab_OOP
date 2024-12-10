#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

    // Приватні методи для валідації
    bool isValidString(const string& input) const;
    bool isValidPrice(double input) const;

public:
    // Конструктори
    Book();
    Book(const string& title, const string& author, double price);

    // Деструктор
    ~Book();

    // Методи доступу до полів
    string getTitle() const;
    string getAuthor() const;
    double getPrice() const;

    void setTitle(const string& title);
    void setAuthor(const string& author);
    void setPrice(double price);

    // Метод для відображення даних
    void display() const;

    // Метод для вводу даних
    void inputDetails();

    // Статичний метод для фільтрації книг за мінімальною ціною
    static void displayBooksByMinPrice(const vector<Book>& books, double minPrice);
};

#endif // BOOK_H
