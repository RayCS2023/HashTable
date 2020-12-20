//
//  List.hpp
//  HashTable
//
//  Created by Raymond Chen on 2020-02-09.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include <iostream>

class Node{
private:
    Node* p_prev;
    Node* p_next;
    std::string val;
    long number;
public:
    Node(const std::string &val, const long &number);
    ~Node();
    friend class List;
    friend class Map;
//    string getVal() const;
//    unsigned long long int getNumber() const;
//    Node* getNext() const;
//    Node* getPrev() const;
};


class List {
public:
    List();
    ~List();
    void insert(Node* obj);
    void remove(Node* obj);
    bool empty() const;
    void clear();
    Node* getHead() const;
    Node* getTail() const;
    
private:
    Node* head;
    Node* tail;
    int count;
};

#endif /* List_hpp */
