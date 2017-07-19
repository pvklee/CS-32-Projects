//
//  Set.cpp
//  Set
//
//  Created by Kevin Lee on 7/8/17.
//  Copyright © 2017 Kevin Lee. All rights reserved.
//

#include "Set.hpp"
#include <iostream>

Set::Set()
{
    m_size = 0;
}

Set::~Set()
{
//    int tempSize = m_size;
//    for (int i = 0; i < tempSize; i++)
//        eraseAt(i);
}

bool Set::empty() const
{
    if (m_size == 0)
        return true;
    return false;
}

int Set::size() const
{
    return m_size;
}

bool Set::insert(const ItemType& value)
{
    node* newNode = new node;
    newNode -> data = value;
    if (empty())
    {
        head = newNode;
        tail = newNode;
        newNode -> prev = newNode;
        newNode -> next = newNode;
    } else {
        head -> prev = newNode;
        tail -> next = newNode;
        newNode -> prev = tail;
        newNode -> next = head;
        tail = newNode;
    }
    m_size++;
    return true;
}

bool Set::erase(const ItemType& value)
{
    if (!empty())
    {
        node* temp = head;
        for (int i = 0; i < m_size; i++)
        {
            if (temp->data == value)
            {
                eraseAt(i);
            }
            temp = temp->next;
        }
    }
return false;
}

bool Set::eraseAt(int pos)
{
    if (!empty())
    {
        node* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        
        if (temp == head && m_size > 1)
            head = temp->next;
        if (temp == tail && m_size > 1)
            tail = temp->prev;
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        m_size --;
        return true;
    }
    return false;
}

bool Set::contains(const ItemType& value) const
{
    if (!empty())
    {
        node* temp = head;
        for (int i = 0; i < m_size; i++)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
    }
    return false;
}

void Set::display()
{
    if (!empty())
    {
        node* temp = head;
        for (int i = 0; i < m_size; i++)
        {
            std::cout << temp -> data << " ";
            temp = temp -> next;
        }
        std::cout << std::endl;
    }
}

bool Set::get(int pos, ItemType& value) const
{
    if (!empty())
    {
        node* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        if (temp->data == value)
            return true;
    }
    return false;
}

void Set::swap(Set& other)
{
    Set tempSet;
    node* tempNode = head;
    int i;
    int tempSize = m_size;
    for (i = 0; i < tempSize; i++)
    {
        tempSet.insert(tempNode->data);
        tempNode = tempNode->next;
        eraseAt(i);
    }
    tempNode = other.head;
    tempSize = other.size();
    for (i = 0; i < tempSize; i++)
    {
        insert(tempNode->data);
        tempNode = tempNode->next;
        other.eraseAt(0);
    }
    other = tempSet;
}

//void Set::copy(Set& other)
//{
//    
//}
//
//void Set::assign(Set& other)
//{
//    
//}
