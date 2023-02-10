#include <iostream>
#include <map>
#include "cell.h"

Cell::Cell()
{
    m_value = "";
    m_color = Color::NOCOLOR;
}

Cell::~Cell()
{
    reset();
}

void Cell::set_value(const std::string& value)
{
    m_value = value;
}

std::string Cell::get_value() const
{
    return m_value;
}

void Cell::set_color(Color c)
{
    m_color = c;
}

Color Cell::get_color() const
{
    return m_color;
}

int Cell::to_int()
{
    return std::stoi(m_value);
}

double Cell::to_double()
{
    return std::stoi(m_value);
}

std::string Cell::color_to_string(Color c)
{
    std::map<Color, std::string> C;
    C[Color::GREEN] = "Green";
    C[Color::RED] = "Red";
    C[Color::YELLOW] = "Yellow";
    C[Color::NOCOLOR] = "Nocolor";
    std::string result = C[c];
    return result;
}

Date Cell::to_date()
{
    int tmp = std::stoi(m_value);
    int d = tmp / 1000000;
    int m = (tmp % 1000000) / 10000;
    int y = tmp % 1000;
    Date date(Month(m), Day(d), Year(y + 2000));
    return date;
}

Color Cell::to_enum(const std::string& c)
{
    std::map<std::string, Color> M;
    M["Green"] = Color::GREEN;
    M["Red"] = Color::RED;
    M["Yellow"] = Color::YELLOW;
    M["Nocolor"] = Color::NOCOLOR;
    return M[c];
}

void Cell::reset()
{
    m_value = "";
    m_color = to_enum("Nocolor");
}