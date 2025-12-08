#include "Book.h"
#include <sstream>
int Book::totalBooks = 0;
void Book::incrementCount() { ++totalBooks; }
void Book::decrementCount() { --totalBooks; }
Book::Book() : title_("Untitled"), author_(), year_(1900), price_(0.0), isbn_("") { incrementCount(); }
Book::Book(const std::string& t, const Author& a, int y, double p, const std::string& i)
    : title_(t), author_(a), year_(y), price_(p), isbn_(i) {
    if (year_ < 1450 || year_ > 2025) year_ = 1900;
    if (price_ < 0.0) price_ = 0.0;
    incrementCount();
}
Book::Book(const Book& o) : title_(o.title_), author_(o.author_), year_(o.year_), price_(o.price_), isbn_(o.isbn_) { incrementCount(); }
Book::Book(Book&& o) noexcept : title_(std::move(o.title_)), author_(std::move(o.author_)), year_(o.year_), price_(o.price_), isbn_(std::move(o.isbn_)) {
    incrementCount();
    o.year_ = 0; o.price_ = 0.0;
}
Book& Book::operator=(const Book& o) {
    if (this != &o) { title_ = o.title_; author_ = o.author_; year_ = o.year_; price_ = o.price_; isbn_ = o.isbn_; }
    return *this;
}
Book& Book::operator=(Book&& o) noexcept {
    if (this != &o) { title_ = std::move(o.title_); author_ = std::move(o.author_); year_ = o.year_; price_ = o.price_; isbn_ = std::move(o.isbn_); o.year_ = 0; o.price_ = 0.0; }
    return *this;
}
Book::~Book() { decrementCount(); }
std::string Book::getTitle() const { return title_; }
Author Book::getAuthor() const { return author_; }
int Book::getYear() const { return year_; }
double Book::getPrice() const { return price_; }
std::string Book::getIsbn() const { return isbn_; }
void Book::setTitle(const std::string& t) { title_ = t; }
void Book::setAuthor(const Author& a) { author_ = a; }
void Book::setYear(int y) { if (1450 <= y && y <= 2025) year_ = y; }
void Book::setPrice(double p) { if (p >= 0.0) price_ = p; }
void Book::setIsbn(const std::string& s) { isbn_ = s; }
std::string Book::to_string() const { std::ostringstream oss; oss << """ << title_ << "" by " << author_.to_string() << ", " << year_ << " [" << isbn_ << "] - " << price_ << " lv."; return oss.str(); }
int Book::getTotalBooks() { return totalBooks; }
