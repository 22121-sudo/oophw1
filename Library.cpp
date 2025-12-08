#include "Library.h"
#include <algorithm>
#include <sstream>
Library::Library() = default;
void Library::addBook(const Book& b) { if (!b.getIsbn().empty()) books_.push_back(b); }
void Library::addMember(const Member& m) { if (!m.getMemberId().empty()) members_.push_back(m); }
bool Library::hasBook(const std::string& i) const { for (auto& b : books_) if (b.getIsbn() == i) return true; return false; }
bool Library::activeLoanExists(const std::string& i) const { for (auto& l : loans_) if (l.getIsbn() == i && !l.isReturned()) return true; return false; }
bool Library::isBookAvailable(const std::string& i) const { return hasBook(i) && !activeLoanExists(i); }
bool Library::memberExists(const std::string& id) const { for (auto& m : members_) if (m.getMemberId() == id) return true; return false; }
bool Library::loanBook(const std::string& i, const std::string& id, const std::string& s, const std::string& d) {
    if (!hasBook(i) || !memberExists(id) || activeLoanExists(i)) return false;
    try { loans_.emplace_back(i, id, s, d); } catch (...) { return false; }
    return true;
}
bool Library::returnBook(const std::string& i, const std::string& id) {
    for (auto& l : loans_) if (l.getIsbn() == i && l.getMemberId() == id && !l.isReturned()) { l.markReturned(); return true; }
    return false;
}
std::vector<Book> Library::findByAuthor(const std::string& a) const {
    std::vector<Book> r;
    auto t = toLower(a);
    for (auto& b : books_) if (toLower(b.getAuthor().getName()).find(t) != std::string::npos) r.push_back(b);
    return r;
}
std::string Library::to_string() const {
    int c = 0; for (auto& l : loans_) if (!l.isReturned()) ++c;
    std::ostringstream oss; oss << "Library: " << books_.size() << " books, " << members_.size() << " members, " << c << " active loans."; return oss.str();
}
std::string Library::toLower(std::string s) { std::transform(s.begin(), s.end(), s.begin(), ::tolower); return s; }
