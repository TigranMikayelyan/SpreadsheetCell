#include <iostream>
#include "spreadsheet.h"

void Spreadsheet::print() 
{
    std::cout << "Row = " << m_row << std::endl;
    std::cout << "Column = " << m_column << std::endl;
    std::cout << "Size = " << m_cells.size() << std::endl;
    auto it = m_cells;
    for (int i = 0; i < it.size(); ++i) 
    {
        auto ii = it[i];
        std::cout << i << " ";
         for (int j = 0; j < ii.size(); ++j) 
         {
            std::cout << ii[j].get_value()  << " ";
         }
         std::cout << '\n';
    }
}

void Spreadsheet::insert_row(int row_ind)
{
    if (row_ind >= m_row || row_ind < 0)
    {
        throw std::out_of_range("Invalid index!");
    }
    std::vector<Cell> tmp;
    m_cells.insert(m_cells.begin() + row_ind, tmp);
    ++m_row;
}

void Spreadsheet::insert_column(int column_ind)
{
    if (column_ind > 0 || column_ind < m_column)
    { 
        ++m_column;
        for (int i = 0; i < m_row; ++i)
        { 
            std::vector<Cell> tmp(column_ind);
            for (int j = 0, t = 0; j < m_column; ++j, ++t)
            {
                if (j == column_ind)
                {
                    --t;
                   
                    continue;
                }
                tmp[j] = m_cells[i][t];
            }
            std::swap(m_cells[i], tmp);
        }
    }
}

void Spreadsheet::add_row(int row_ind)
{
    if (row_ind >= 0) 
    {
        m_row = row_ind;
        m_cells.resize(row_ind);
    } 
    else 
    {
        std::cout << "ERROR" << '\n';
        exit(0);
    }
}

void Spreadsheet::remove_row(int row_ind)
{
    if (row_ind >= m_row || row_ind < 0)
    {
        throw std::out_of_range("Invalid index!");
    }
    m_cells.erase(m_cells.begin() + row_ind);
    m_row--;
}

void Spreadsheet::add_column(int column_ind)
{
    if (column_ind >= 0) 
    {
        m_column = column_ind;
        vec.resize(column_ind);
        for (int i = 0; i < m_cells.size(); ++i) 
        {    
            if (m_cells[i].size() < column_ind) 
            {
                m_cells[i].resize(column_ind);
            } 
            else 
            {
                m_cells.push_back(vec);
            }
        }
    } 
    else 
    {
        std::cout << "ERROR" << '\n';
        exit(0);
    }
}

void Spreadsheet::remove_column(int column_ind)
{
    if (column_ind >= m_row || column_ind < 0)
    {
        throw std::out_of_range("Invalid index!");
    }
    m_cells.erase(m_cells.begin() + column_ind);
    m_column--;
}

void Spreadsheet::set_cell_at(int row_ind, int column_ind, const Cell& c)
{
    if (!m_row || !m_column)
    {
        throw std::out_of_range("Invalid index!");
    }
    if (row_ind < 0 || row_ind >= m_row || column_ind < 0 && column_ind >= m_column)
    {
        throw std::out_of_range("Invalid index!");
    }
    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_column; ++j)
        {
            if (i == row_ind && j == column_ind)
            {
                m_cells[i][j] = c;
            }
        }
    }
}

void Spreadsheet::set_cell_at(int row_ind, int column_ind, const std::string& str)
{
    if (!m_row || !m_column)
    {
        throw std::out_of_range("Invalid index!");
        return;
    }
    if (row_ind < 0 || row_ind >= m_row || column_ind < 0 || column_ind >= m_column)
    {
        throw std::out_of_range("Invalid index!");
        return;
    }
     m_cells[row_ind][column_ind].set_value(str);
}

Cell Spreadsheet::get_cell_at(int row_ind, int column_ind)
{
    if (row_ind < 0 || row_ind >= m_row || column_ind < 0 || column_ind >= m_column)
    {
        throw std::out_of_range("Invalid index!");
    }
    return m_cells[row_ind][m_column];
}

void Spreadsheet::swap_rows(int row1, int row2)
{
    std::swap(m_cells[row1], m_cells[row2]);
}

void Spreadsheet::swap_columns(int col1, int col2)
{

    for (int i = 0; i < m_row; ++i) 
    {
        Cell tmp = m_cells[i][col1];
        m_cells[i][col1] = m_cells[i][col2];
        m_cells[i][col2] = tmp;
    }
}