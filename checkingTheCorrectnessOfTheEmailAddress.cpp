#include <iostream>
#include <string>

// Function for obtaining the first part of email (to the symbol @)
std::string getLocalPart(const std::string& email) {
    std::string localPart;
    for (char c : email) {
        if (c == '@') break; // stop if the symbol is found @
        localPart += c; // Add the symbol to the local part
    }
    return localPart;
}

// Function for obtaining the second part of email (after symbol @)std::string getDomainPart(const std::string& email) {
    std::string domainPart;
    bool atFound = false; // flag for checking the presence of a symbol @
    for (char c : email) {
        if (c == '@') {
            atFound = true; // install the flag if the symbol is found @
            continue; // miss the character @
        }
        if (atFound) {
            domainPart += c; // Add the symbol to the domain part
        }
    }
    return domainPart;
}
