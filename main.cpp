#include <iostream>
#include "Library.h"
int main() {
    Library lib;
    Author a{"Ivan Vazov", 1850};
    Book b1{"Pod igoto", a, 1894, 25.50, "ISBN-001"};
    Book b2{"Nima zemya", a, 1900, 18.90, "ISBN-002"};
    lib.addBook(b1);
    lib.addBook(b2);
    Member m{"Petar Petrov", "M001", 2023};
    lib.addMember(m);
    std::cout << lib.to_string() << "\n";
    lib.loanBook("ISBN-001","M001","2025-11-03","2025-11-17");
    std::cout << lib.isBookAvailable("ISBN-001") << "\n";
    lib.returnBook("ISBN-001","M001");
    std::cout << lib.isBookAvailable("ISBN-001") << "\n";
    return 0;
}
