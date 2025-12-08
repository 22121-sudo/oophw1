#include "Author.h"
#include <sstream>
Author::Author() : name_("Unknown"), birthYear_(1900) {}
Author::Author(std::string name, int birthYear) : name_(std::move(name)), birthYear_(birthYear) {
    if (birthYear_ < 1850 || birthYear_ > 2025) birthYear_ = 1900;
}
std::string Author::getName() const { return name_; }
int Author::getBirthYear() const { return birthYear_; }
void Author::setBirthYear(int year) { if (1850 <= year && year <= 2025) birthYear_ = year; }
std::string Author::to_string() const { std::ostringstream oss; oss << name_ << " (" << birthYear_ << ")"; return oss.str(); }
