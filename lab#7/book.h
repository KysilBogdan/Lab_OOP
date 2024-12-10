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

    bool isValidString(const string& input) const;
    bool isValidPrice(double input) const;

public:
    Book();
    Book(const string& title, const string& author, double price);
    ~Book();

    string getTitle() const;
    string getAuthor() const;
    double getPrice() const;

    void setTitle(const string& title);
    void setAuthor(const string& author);
    void setPrice(double price);

    void display() const;
    void inputDetails();
    static void displayBooksByMinPrice(const vector<Book>& books, double minPrice);
};

#endif // BOOK_H
