#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "read.h"

std::istream& read(std::istream& in, std::vector<std::string>& vec, std::string::size_type& maxLen){
    if (in){
        vec.clear();
        std::string s;
        while (in >> s){
            maxLen = std::max(maxLen, s.size());
            vec.push_back(s);
        }
        in.clear();
    }
    return in;
}
