#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <vector>
#include <string>
class Library {
public:
    Library();
    void addBook(const Book&);
    void addMember(const Member&);
    bool hasBook(const std::string&) const;
    bool isBookAvailable(const std::string&) const;
    bool loanBook(const std::string&, const std::string&, const std::string&, const std::string&);
    bool returnBook(const std::string&, const std::string&);
    std::vector<Book> findByAuthor(const std::string&) const;
    std::string to_string() const;
private:
    std::vector<Book> books_;
    std::vector<Member> members_;
    std::vector<Loan> loans_;
    bool memberExists(const std::string&) const;
    bool activeLoanExists(const std::string&) const;
    static std::string toLower(std::string);
};
#endif
