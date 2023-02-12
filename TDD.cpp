#include "TDD.h"

void test_cell_functions()
{
    std::cout << std::endl;
    std::cout << "Cell functions: " << std::endl;
    std::cout << std::endl;
    Cell cell;
    cell.set_value("41");
    if (cell.to_int() == 41)
    {
        std::cout << "set_value() - passed!" << std::endl;
        std::cout << "to_int() - passed!" << std::endl;
    }
    std::string str = cell.get_value();
    if(str == "41")
    {
        std::cout << "get_value - passed!" << std::endl;
    }
    cell.reset();
    if (cell.get_value() == "" && cell.get_color() == Color::NOCOLOR)
    {
        std::cout << "reset() - passed!" << std::endl;
    }
    cell.set_value("41.5");
    if (cell.to_double() == 41.5)
    {
        std::cout << "to_double() - passed!" << std::endl;
    }
    Color c;
    cell.set_color(c);
    if (cell.color_to_string(cell.get_color()) == "Green")
    {
        std::cout << "set_color() - passed!" << std::endl;
        std::cout << "get_color() - passed!" << std::endl;
        std::cout << "to_string() - passed!" << std::endl;
    }
}

void test_spreadsheet_functions()
{
    std::cout << std::endl;
    std::cout << "Spreadsheet functions: " << std::endl;
    std::cout << std::endl;
    Spreadsheet spreadsheet;
    int size = 2;
    spreadsheet.add_row(size);
    spreadsheet.add_column(size);
    if (spreadsheet.get_row() == size && spreadsheet.get_column() == size)
    {
        std::cout << "add_row() - passed! " << std::endl;
        std::cout << "add_column() - passed! " << std::endl;
        std::cout << "get_row() - passed! " << std::endl;
        std::cout << "get_column() - passed! " << std::endl;
    }
    spreadsheet.set_cell_at(0, 0, "42");
    Cell cl = spreadsheet.get_cell_at(0, 0);
    if (cl.get_value() == "42")
    {
        std::cout << "set_cell_at() - passed!" << std::endl;
        std::cout << "get_cell_at() - passed!" << std::endl;
    }
    spreadsheet.insert_column(0);
    spreadsheet.insert_row(0);
    if (spreadsheet.get_column() == size + 1 && spreadsheet.get_row() == size + 1)
    {
        std::cout << "insert_column() - passed!" << std::endl;
        std::cout << "insert_row() - passed!" << std::endl;
    }
    spreadsheet.remove_row(0);
    spreadsheet.remove_column(0);
    if (spreadsheet.get_row() == size && spreadsheet.get_column() == size)
    {
        std::cout << "remove_row() - passed!" << std::endl;
        std::cout << "remove_column() - passed!" << std::endl;
    }
     std::cout << "!" << std::endl;

    // spreadsheet.set_cell_at(0, 0, "Tiko");
    // spreadsheet.set_cell_at(1, 0, "Vle");
     
    spreadsheet.swap_rows(0, 1);
    Cell c = spreadsheet.get_cell_at(0, 0);
    std::cout << c.get_value() << std::endl;
    if (c.get_value() == "Vle")
    {
        std::cout << "get_value() - passed!" << std::endl;
    }
    c.reset();
    spreadsheet.swap_columns(0, 1);
    c = spreadsheet.get_cell_at(0, 0);
    if (c.get_value() == "")
    {
        std::cout << "swap_columns() - passed!" << std::endl;
    }
}