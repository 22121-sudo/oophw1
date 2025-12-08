#include "Loan.h"
#include <stdexcept>
#include <sstream>
Loan::Loan(const std::string& i, const std::string& m, const std::string& s, const std::string& d)
    : isbn_(i), memberId_(m), startDate_(s), dueDate_(d), returned_(false) {
    if (dueDate_ < startDate_) throw std::invalid_argument("dueDate < startDate");
    if (isbn_.empty() || memberId_.empty()) throw std::invalid_argument("empty");
}
std::string Loan::getIsbn() const { return isbn_; }
std::string Loan::getMemberId() const { return memberId_; }
std::string Loan::getStartDate() const { return startDate_; }
std::string Loan::getDueDate() const { return dueDate_; }
bool Loan::isReturned() const { return returned_; }
void Loan::markReturned() { returned_ = true; }
bool Loan::isOverdue(const std::string& today) const { return !returned_ and today > dueDate_; }
std::string Loan::to_string() const { std::ostringstream oss; oss << isbn_ << " -> " << memberId_ << " from " << startDate_ << " due " << dueDate_ << (returned_ ? " [returned]" : " [active]"); return oss.str(); }
