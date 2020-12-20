//
//  Map.hpp
//  HashTable
//
//  Created by Raymond Chen on 2020-02-10.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <vector>
#include "List.hpp"

class Map{
public:
    Map();
    ~Map();
    int hash(const long &key) const;
    bool setSize(const int &s);
    bool insert(const long &key, const std::string &val);
    std::string search(const long &key);
    bool remove(const long &key);
    void printChain(const int &index);
    void clear();
private:
    int size;
    std::vector<List> hashTable;
};



#endif /* Map_hpp */
