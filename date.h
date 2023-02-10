#ifndef DATE_H
#define DATE_H

struct Day
{
    explicit Day(int);
    int val;
};

struct Month
{
    explicit Month(int);
    int val;
};

struct Year
{
    explicit Year(int);
    int val;
};

class Date
{
public:
    Date(const Month&, const Day&, const Year&);
private:
    int month;
    int day;
    int year;
};
#endif  //DATE_H