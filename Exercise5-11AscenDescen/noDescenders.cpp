#include <algorithm>
#include <string>

#include "noDescenders.h"

bool isNotDescend (const char c){
    if (c == 'g' || c == 'j' || c == 'p' || c == 'q' || c == 'y')
        return true;
    else
        return false;
}

bool noDescenders(const std::string& word){
    return word.end() == std::find_if(word.begin(), word.end(), isNotDescend);
}
