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

// Function for checking the correctness of the local part of email
bool isValidLocalPart(const std::string& localPart) {
    const std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-/=?^_`{|}~.-";
    
    // Checking the length of the local part
    if (localPart.length() < 1 || localPart.length() > 64) return false;

    bool lastWasDot = false; // to check two points in a row
    for (size_t i = 0; i < localPart.length(); ++i) {
        char c = localPart[i];
        if (validChars.find(c) == std::string::npos) return false; // Check for permissible characters
        
        // check for two points in a row
        if (c == '.') {
            if (lastWasDot) return false; // Two points in a row are not acceptable
            lastWasDot = true;
        } else {
            lastWasDot = false;
        }
    }
    
    // check for points at the beginning and at the end
    if (localPart.front() == '.' || localPart.back() == '.') return false;

    return true;
}
