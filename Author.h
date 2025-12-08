#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>
class Author {
public:
    Author();
    explicit Author(std::string name, int birthYear);
    std::string getName() const;
    int getBirthYear() const;
    void setBirthYear(int year);
    std::string to_string() const;
private:
    std::string name_;
    int birthYear_;
};
#endif
