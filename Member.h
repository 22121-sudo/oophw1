#ifndef MEMBER_H
#define MEMBER_H
#include <string>
class Member {
public:
    Member();
    Member(std::string, std::string, int);
    std::string getName() const;
    std::string getMemberId() const;
    int getYearJoined() const;
    void setName(const std::string&);
    void setMemberId(const std::string&);
    void setYearJoined(int);
    std::string to_string() const;
private:
    std::string name_;
    std::string memberId_;
    int yearJoined_;
};
#endif
