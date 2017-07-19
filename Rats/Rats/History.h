//
//  History.h
//  Rats
//
//  Created by Kevin Lee on 7/6/17.
//  Copyright © 2017 Kevin Lee. All rights reserved.
//

#ifndef History_h
#define History_h

#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
private:
    int     m_grid[MAXROWS][MAXCOLS];
    int     m_rows;
    int     m_cols;
    
};

#endif /* History_h */
