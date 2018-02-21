#include <iostream>
#include <string>
#include <vector>

#include "noAscenders.h"
#include "noDescenders.h"
#include "read.h"

typedef std::vector<std::string>::size_type vec_size;
typedef std::string::size_type string_size;

int main() {
    // Obtain input using read function for unknown number of words.
    // Using vector since the only need for this container is to add elements in the back
    std::cout << "Input string to check for absence of ascenders and descenders: "
              << std::endl;
    std::vector<std::string> words;
    string_size maxLen = 0;
    read(std::cin, words, maxLen);

    std::cout << std::endl
              << "Word" << std::string(maxLen, ' ')
              << " Ascenders?  Descenders?" << std::endl
              << std::string(maxLen + 27, '-') << std::endl;

    // Create new vector to store words without ascenders or descenders
    std::vector<std::string> noAscNoDesc;

    // Use index i to march through the vector, passing each word into noAscenders function
    for (vec_size i = 0; i != words.size(); ++i){
        bool noAsc;
        // Write word in first column
        std::cout << words[i] << std::string(maxLen - words[i].size(), ' ');

        if (noAscenders(words[i])){
            std::cout << "       No          ";
            noAsc = true;
        } else
            std::cout << "       Yes         ";

        if (noDescenders(words[i])){
            std::cout << " No";
            if (noAsc == true)
                noAscNoDesc.push_back(words[i]);
        } else
            std::cout << " Yes";

        std::cout << std::endl << std::endl;
    }

    // Iterate through vector to store the longest word as a string and print tat string
    std::string maxString;
    for (vec_size j = 0; j != noAscNoDesc.size(); ++j){
        maxString = noAscNoDesc[j].size() > maxString.size()? noAscNoDesc[j] : maxString;
    }
    std::cout << "The longest word without Ascenders or Descenders is: " << maxString << std::endl;

    return 0;
}
