#include <iostream>
#include "date.h"

Day::Day(int d) : val(d) {}
Month::Month(int m) : val(m) {}
Year::Year(int y) : val(y) {}

Date::Date(const Month& m, const Day& d, const Year& y)
    : month(m.val), day(d.val), year(y.val){}