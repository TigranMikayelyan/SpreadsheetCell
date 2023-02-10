#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <vector>
#include "cell.h"

class Spreadsheet
{
public:
    void set_cell_at(int, int, const Cell&);
    void set_cell_at(int, int, const std::string&);
    Cell get_cell_at(int, int);
    void insert_row(int);
    void insert_column(int);
    void add_row(int);
    void remove_row(int);
    void add_column(int);
    void remove_column(int);
    void swap_rows(int, int);
    void swap_columns(int, int);
    void print();
private:
    std::vector<std::vector<Cell>> m_cells;
    std::vector<Cell> vec;
    int m_row;
    int m_column;                                                        
};
#endif // SPREADSHEET_H