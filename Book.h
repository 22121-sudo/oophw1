#ifndef BOOK_H
#define BOOK_H
#include "Author.h"
#include <string>
class Book {
public:
    static int totalBooks;
    Book();
    Book(const std::string&, const Author&, int, double, const std::string&);
    Book(const Book&);
    Book(Book&&) noexcept;
    Book& operator=(const Book&);
    Book& operator=(Book&&) noexcept;
    ~Book();
    std::string getTitle() const;
    Author getAuthor() const;
    int getYear() const;
    double getPrice() const;
    std::string getIsbn() const;
    void setTitle(const std::string&);
    void setAuthor(const Author&);
    void setYear(int);
    void setPrice(double);
    void setIsbn(const std::string&);
    std::string to_string() const;
    static int getTotalBooks();
private:
    std::string title_;
    Author author_;
    int year_;
    double price_;
    std::string isbn_;
    void incrementCount();
    void decrementCount();
};
#endif
