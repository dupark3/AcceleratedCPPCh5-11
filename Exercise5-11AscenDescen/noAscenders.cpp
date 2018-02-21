#include <algorithm> // find_if
#include <string>

#include "noAscenders.h"

// Predicate to test if a character is an ascender
bool isNotAscend (const char c){
    if (c == 'b' || c == 'd' || c == 'f' || c == 'h' || c == 'k' || c == 'l' || c == 't')
        return true;
    else
        return false;
}

bool noAscenders (const std::string& word){
    // Find_if function will return an iterator at the first instance the predicate is true
    // If find_if returns word.end(), it means there was NO instance in which the predicate was true
    return word.end() == std::find_if(word.begin(), word.end(), isNotAscend);
}
