//
//  DoubleHashing.cpp
//  HashTable
//
//  Created by Raymond Chen on 2020-02-11.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#include "DoubleHashing.hpp"
#include <cmath>
using std::floor;
using std::to_string;
using std::string;

//default Person constructor
Person::Person(){
    number = -1;
    name = "";
    
}

//Person constructor
Person::Person(const long &number, const std::string &name) {
    this->number = number;
    this->name = name;
}
//DoubleHashing Constructor
DoubleHashing::DoubleHashing() {
    size = 0;
    count = 0;
}

//primary hashing function
int DoubleHashing::hash(const long &key) const {
        return key%size;
}

//secondary hashing function
int DoubleHashing::hashTwo(const long &key) const {
    long t = floor(key/size);
    int result = t%size;
    return result%2==0? result+1:result;
}

//sets the size of hashtable
bool DoubleHashing::setSize(const int &s) {
    size = s;
    count = 0;
    Person p;
    hashTable.assign(size, p); // assign each slot to a default person object
    return true;
}


//insert into hashtable
bool DoubleHashing::insert(const long &key, const std::string &val) {
    string found = search(key);
    
    //return if table is full
    if(count == size)
        return false;
    //return if exist
    if(found != "")
        return false;

    int probe = hash(key);
    int offset = hashTwo(key);
    
    //starts with hashed value of key and check if the slot is availble
    while(hashTable[probe].number != -1) {
        probe = (probe+offset)%size; // keep increasing by second hashed value until you get to a availble spot
    }
    
    hashTable[probe] = Person(key,val); //assign to slot
    count++;
    return true;
}

//search for a key in hashtable
string DoubleHashing::search(const long &key) {
    bool found = false;
    int timer = 1;
    int probe = hash(key);
    int offset = hashTwo(key);
    string cout = "";
    
    //using the same alogrithm as insert to find the node
    while(hashTable[probe].number != key) {
        if(timer == size) // incase we run into a infinite loop, but unlikey since our size is relative prime second hashed key
            break;
        probe = (probe+offset)%size;
        timer++;
    }
    //if after loop, the key is found
    if(hashTable[probe].number == key){
        found = true;
        cout = "found " + hashTable[probe].name + " in " + to_string(probe);
    }
    return cout;
}

//remove from hashtable
bool DoubleHashing::remove(const long &key) {
    bool found = false;
    int timer = 1;
    int probe = hash(key);
    int offset = hashTwo(key);
    
    //using the same alogrithm as insert to find the node
    while(hashTable[probe].number != key) {
        if(timer == size) // incase we run into a infinite loop, but unlikey since our size is relative prime second hashed key
            break;
        probe = (probe+offset)%size;
        timer++;
    }
    //if after loop, the key is found
    if(hashTable[probe].number == key){
        found = true;
        hashTable[probe] = Person(); // set slot to the default Person object
        count--;
    }
    return found;
}

