//
//  openhttest.cpp
//  HashTable
//
//  Created by Raymond Chen on 2020-02-09.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#include <iostream>

#include "DoubleHashing.hpp"
using std::string;
using std::cin;
using std::endl;
using std::cout;
using std::stol;
using std::stoi;
int main(int argc, const char * argv[]) {


        string line;
        string command;
        string info;
        DoubleHashing hashFunction;

        while (!cin.eof()){

            getline(cin, line);
            if(line == "")
                break;

            std::size_t space_index = line.find(" ");
            command = line.substr(0,space_index);
            info = line.substr(space_index);
            std::size_t semi_colon_index = line.find(";");

            if(command == "n"){
                if(hashFunction.setSize(stoi(info))){
                    cout << "success" << endl;
                }
                else{
                    cout << "failure" << endl;
                }
            }
            else if(command == "i"){
                string name = info.substr(semi_colon_index);
                long number = stol(info.substr(0,semi_colon_index-1));
                if(hashFunction.insert(number, name)){
                    cout << "success" << endl;
                }
                else{
                    cout << "failure" << endl;
                }
            }
            else if(command == "s"){
                long number = stol(info.substr(0,semi_colon_index-1));
                string c_out = hashFunction.search(number);
                if(c_out != ""){
                    cout << c_out << endl;
                }
                else{
                    cout << "not found" << endl;
                }
            }
            else if(command == "d"){
                long number = stol(info.substr(0,semi_colon_index-1));
                if(hashFunction.remove(number)){
                    cout << "success" << endl;
                }
                else{
                    cout << "failure" << endl;
                }
            }
        }
    return 0;
}
