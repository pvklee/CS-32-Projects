#include "History.h"
#include <iostream>
using namespace std;


History::History(int nRows, int nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        cout << "***** Arena created with invalid size " << nRows << " by "
        << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    
    for (int r = 1; r <= m_rows; r++)
        for (int c = 1; c <= m_cols; c++)
            m_grid[r-1][c-1] = EMPTY;
}

bool History::record(int r, int c)
{
    if (r <= 0  ||  c <= 0  ||  r > MAXROWS  ||  c > MAXCOLS)
    {
        return false;
    }
    m_grid[r-1][c-1]++;
    return true;
}

void History::display() const
{
    char displayGrid[MAXROWS][MAXCOLS];
    int r, c;
    
    clearScreen();
    for (r = 1; r <= m_rows; r++)
    {
        for (c = 1; c <= m_cols; c++)
        {
            displayGrid[r-1][c-1] = (m_grid[r-1][c-1] == EMPTY ? '.' : '*');
            cout << displayGrid[r-1][c-1];
        }
        cout << endl;
    }
    cout << endl;
}
