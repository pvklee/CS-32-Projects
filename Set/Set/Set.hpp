//
//  Set.hpp
//  Set
//
//  Created by Kevin Lee on 7/8/17.
//  Copyright © 2017 Kevin Lee. All rights reserved.
//

#ifndef Set_hpp
#define Set_hpp

#include <stdio.h>
//#include <string>

typedef unsigned long ItemType;

class Set
{
public:
    struct node
    {
        ItemType data;
        node *prev;
        node *next;
    };
    
    node* head;
    node* tail;
    
    Set();
    ~Set();
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool eraseAt(int pos);
    bool contains(const ItemType& value) const;
    void display();
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);
//    void copy(Set& other);
//    void assign(Set& other);
    
private:
    int m_size;
    
};

#endif /* Set_hpp */
