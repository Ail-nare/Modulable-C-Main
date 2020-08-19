# Modulable-CXX-Main

Usage:

 - Include the MainC++.hpp ONLY in the file that define the main (ex: 'main.cpp').
 - The first argument 'int ac' can be ignore.
 - The 2nd and 3nd agrument can be of any type/class, as long as it can be construct with a (char \*\*).

Example:

    #include "MainC++.hpp"
    #include "Args.hpp"
    #include <iostream>
    
    // This main will display every argument
    int main(const Args args) // class Args is a std::vector<std::string> whiwh can be construct with a (char **)
    {
        for (const auto &arg : args)
            std::cout << arg << std::endl;

            return 0;
    }