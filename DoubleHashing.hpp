//
//  DoubleHashing.hpp
//  HashTable
//
//  Created by Raymond Chen on 2020-02-11.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#ifndef DoubleHashing_hpp
#define DoubleHashing_hpp
#include <vector>
#include <iostream>

class Person{
private:
    std::string name;
    long number;
    friend class DoubleHashing;
public:
    Person();
    Person(const long &number, const std::string &name);
};

class DoubleHashing{
public:
    DoubleHashing();
    int hash(const long &key) const;
    int hashTwo(const long &key) const;
    bool setSize(const int &s);
    bool insert(const long &key, const std::string &val);
    std::string search(const long &key);
    bool remove(const long &key);
    
private:
    int size;
    int count;
    std::vector<Person> hashTable;
};


#endif /* DoubleHashing_hpp */
