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
    //From the set, take all names that share your initials and place pointers to them in a new std::queue.
    std::queue<std::string*> matches; 
    std::string initials = "JL";
    for(auto it = students.begin(); it != students.end(); it++){
        if(it->at(0) == initials[0] && it->at(1) == initials[1]){
            matches.push(const_cast<std::string*> (&(*it))); // matches cannot push const string* so we need to cast it to string*
    }
    return matches;
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    std::unordered_set<std::string> applicants = get_applicants("students.txt");
    std::set<std::string> students(applicants.begin(), applicants.end());
    std::queue<std::string*> matches = find_matches(students);
    while(!matches.empty()){
        std::cout << *matches.front() << std::endl;
        matches.pop();
    }

    return 0;
}
