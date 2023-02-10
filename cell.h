#ifndef CELL_H
#define CELL_H
#include "date.h"

enum class Color
{
    RED,
    GREEN,
    YELLOW,
    NOCOLOR
};

class Cell
{
public:
    Cell();
    ~Cell();
public:
    void set_value(const std::string&);
    std::string get_value() const;
    void set_color(Color); 
    Color get_color() const;
    int to_int();
    double to_double();
    std::string color_to_string(Color);
    Date to_date();
    Color to_enum(const std::string&);
    void reset();
private:
    std::string m_value;
    Color m_color;
};
#endif // CELL_H