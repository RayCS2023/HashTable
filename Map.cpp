//
//  Map.cpp
//  HashTable
//
//  Created by Raymond Chen on 2020-02-10.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#include "Map.hpp"
using std::string;
using std::to_string;

//constructor
Map::Map() {
    size = 0;
}

//destructor
Map::~Map() {
    clear();
}

//primary hash function
int Map::hash(const long &key) const {
    return key%size;
}

//insert a key into Hashtable
bool Map::insert(const long &key, const string &val) {
    string found = search(key); //see if the key exist
    int k = hash(key);
    
    if(found == ""){ //if the key wasn't find
        Node* node = new Node(val,key); // construct a new node
        hashTable[k].insert(node); // insert into list
    }
    else{
        return false; 
    }

    return true;
}

//set the size of the hashable
bool Map::setSize(const int &s) {
    clear(); //clear all the values previously
    List t;
    size = s;
    hashTable.assign(size, t);// assign empty lists to hashtable slots
    return true;
}

//search for key in hashtable
string Map::search(const long &key) {
    string cout = "";
    int k = hash(key);
    
    Node* tmp = hashTable[k].getHead(); //get the head node of the chain
    
    //traverse the list to find the key
    while(tmp !=nullptr){
        if(tmp->number == key){
            cout = "found " + tmp->val + " in " + to_string(k);
        }
        tmp = tmp->p_next;
    }
    return cout;
}

//remove a key in hashtable
bool Map::remove(const long &key) {
    int k = hash(key);
    
    Node* tmp = hashTable[k].getHead(); //get the head node of the chain
    
    //traverse the chain to see if the key is found, delete node if found
    while(tmp !=nullptr){
        if(tmp->number == key){
            hashTable[k].remove(tmp);
            return true;
        }
        tmp = tmp->p_next;
    }
    return false;
}

//prints the chain at index
void Map::printChain(const int &index) { 
    Node* tmp = hashTable[index].getHead(); //get the head node of the chain
    
    //traverse the chain and print thee keys
    while(tmp!=nullptr){
        if(tmp->p_next == nullptr){
            std::cout << tmp->number << std::endl;
        }
        else{
            std::cout << tmp->number << " ";
        }
        tmp = tmp->p_next;
    }
}

//called in destructor to deallocate all memory used by the Lists
void Map::clear() {
    //for every slot in hashtable, find the chain and deallocate its memory
    for(int i = 0; i < hashTable.size(); i++){
        if(hashTable[i].getHead() != nullptr){
            hashTable[i].clear();
        }
    }
}










