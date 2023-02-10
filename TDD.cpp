#include <iostream>
#include "cell.h"
#include "spreadsheet.h"
#include "date.h"

void test_cell_values()
{
    Cell c1;
    c1.set_value("22");
    if (c1.get_value() != "22")
    {
       std::cout << "Test failed! Problem: getValue()" << std::endl;
    }
    else
    {
        std::cout << "Test passed!" << std::endl;
    }
    if (c1.to_int() != 22)
    {
        std::cout << "Test failed! Problem: toInt()" << std::endl;
    }
    else
    {
        std::cout << "Test passed!" << std::endl;
    }
    Cell c2;
    c2.set_value("3.14");
    if (c2.to_double() != 3.14)
    {
        std::cout << "Test failed! Problem: toDouble()" << std::endl;
    }
    else
    {
        std::cout << "Test passed!" << std::endl;
    }
    
    Cell c3;       
    c3.setValue("08082006");
    Date dt((Month(08)), (Day(08)), (Year(2006)));
    if (c3.toDate() != dt)
    {
        std::cout << "Test failed! Problem: toDate()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }


    c3.reset();
    if (c3.get_value() != "")
    {
        std::cout << "Test failed! Problem: reset()" << std::endl;
    }
    else
    {
        std::cout << "Test passed!" << std::endl;
    }
}
void test_spreadsheet_value()
{
    Spreadsheet sp1;
    Cell c1;
    sp1.set_cell_at(1, 1, c1);
    if (get_cell_at(1, 1) != c1)
    {
        std::cout << "Test failed! Problem: getCellAt()" << std::endl;
    }
    else
    {
        std::cout << "Test passed!" << std::endl;
    }
    Spreadsheet sp2;
    std::string st = "Hello";
    sp2.set_cell_at(1, 1, st);
    if (get_cell_at(1, 1) != st)
    {
        std::cout << "Test failed! Problem: getCellAt()" << std::endl;
    }
    else
    {
        std::cout << "Test passed!" << std::endl;
    }
}