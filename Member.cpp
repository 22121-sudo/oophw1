#include "Member.h"
#include <sstream>
Member::Member() : name_("Unknown"), memberId_(""), yearJoined_(1900) {}
Member::Member(std::string n, std::string id, int y) : name_(std::move(n)), memberId_(std::move(id)), yearJoined_(y) {
    if (memberId_.empty()) memberId_ = "UNKNOWN";
    if (yearJoined_ < 1900 || yearJoined_ > 2025) yearJoined_ = 1900;
}
std::string Member::getName() const { return name_; }
std::string Member::getMemberId() const { return memberId_; }
int Member::getYearJoined() const { return yearJoined_; }
void Member::setName(const std::string& s) { name_ = s; }
void Member::setMemberId(const std::string& id) { if (!id.empty()) memberId_ = id; }
void Member::setYearJoined(int y) { if (1900 <= y && y <= 2025) yearJoined_ = y; }
std::string Member::to_string() const { std::ostringstream oss; oss << name_ << " [" << memberId_ << "], joined: " << yearJoined_; return oss.str(); }
