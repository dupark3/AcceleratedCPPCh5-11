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
    // read function also stores the length of the longest word in maxLen, so that we can size the output table later
    std::cout << "Input string to check for absence of ascenders and descenders: "
              << std::endl;
    std::vector<std::string> words;
    string_size maxLen = 0;
    read(std::cin, words, maxLen);

    std::string maxString; // will store the longest word without ascenders or descenders

    // set up the output table header
    std::cout << std::endl
              << "Word" << std::string(maxLen, ' ')
              << " Ascenders?  Descenders?" << std::endl
              << std::string(maxLen + 27, '-') << std::endl; // underline table heading

    // Use index i to march through the vector, passing each word into noAscenders function
    for (vec_size i = 0; i != words.size(); ++i){
        bool noAsc;
        // Write word in first column
        std::cout << words[i] << std::string(maxLen - words[i].size(), ' ');

        // Write Yes or No on second and third column for ascenders and descenders, respectively
        if (noAscenders(words[i])){
            std::cout << "       No          ";
            noAsc = true;
        } else {
            std::cout << "       Yes         ";
        }
        if (noDescenders(words[i])){
            std::cout << " No";
            if (noAsc == true)
                maxString = words[i].size() > maxString.size()? words[i] : maxString;
        } else{
            std::cout << " Yes";
        }

        std::cout << std::endl;
    }



    // Print the longest word without ascenders or descenders
    std::cout << std::endl
              << "The longest word without Ascenders or Descenders is: "
              << maxString
              << std::endl;

    return 0;
}
