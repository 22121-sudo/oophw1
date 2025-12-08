#ifndef LOAN_H
#define LOAN_H
#include <string>
class Loan {
public:
    Loan(const std::string&, const std::string&, const std::string&, const std::string&);
    std::string getIsbn() const;
    std::string getMemberId() const;
    std::string getStartDate() const;
    std::string getDueDate() const;
    bool isReturned() const;
    void markReturned();
    bool isOverdue(const std::string&) const;
    std::string to_string() const;
private:
    std::string isbn_;
    std::string memberId_;
    std::string startDate_;
    std::string dueDate_;
    bool returned_;
};
#endif
