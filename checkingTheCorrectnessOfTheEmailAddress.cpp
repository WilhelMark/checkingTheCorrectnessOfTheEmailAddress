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
