//
//  main.cpp
//  Set
//
//  Created by Kevin Lee on 7/8/17.
//  Copyright © 2017 Kevin Lee. All rights reserved.
//

#include "Set.hpp"
#include <iostream>
using namespace std;

void test()
{
    Set a;
    Set b;
    a.insert(10);
    a.insert(20);
    a.insert(30);
    b.insert(2);
    b.insert(4);
    b.insert(5);
    b.insert(7);
    a.display();
    b.display();
    a.swap(b);
    a.display();
    b.display();
}

int main()
{
    test();
}
