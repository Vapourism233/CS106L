/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <fstream>
#include <sstream>

std::unordered_set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::unordered_set<std::string> applicants;
    std::fstream file;
    file.open(filename);
    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            iss >> name;
            applicants.insert(name);
        }
    }
    return applicants;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    // TODO: Implement this function.
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    std::string filename = ""
    return 0;
}
