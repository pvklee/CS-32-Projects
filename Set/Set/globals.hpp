//
//  globals.hpp
//  Set
//
//  Created by Kevin Lee on 7/8/17.
//  Copyright © 2017 Kevin Lee. All rights reserved.
//

#ifndef globals_hpp
#define globals_hpp

#include <stdio.h>
#include "Set.hpp"

void unite(const Set& s1, const Set& s2, Set& result);
void subtract(const Set& s1, const Set& s2, Set& result);

#endif /* globals_hpp */
