//
// Created by Ail on 30/06/2020.
//

#include "MainC++.hpp"
#include "Args.hpp"
#include <iostream>

// This main will display the number of argument and every argument
int main(short nb_of_arg, const Args &args)
{
    std::cout << nb_of_arg << std::endl;

    for (const auto &arg : args)
        std::cout << arg << std::endl;

    return 0;
}