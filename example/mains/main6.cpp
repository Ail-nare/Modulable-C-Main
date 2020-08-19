//
// Created by Ail on 30/06/2020.
//

#include "MainC++.hpp"
#include "Args.hpp"
#include <iostream>

// This main will display and every argument and environment variables
int main(int nb_of_arg, char **args, Args &&env)
{
    std::cout << nb_of_arg << std::endl;

    for (int i = 0; i < nb_of_arg; ++i)
        std::cout << args[i] << std::endl;

    std::cout << std::endl;

    for (const auto &arg : env)
        std::cout << arg << std::endl;

    return 0;
}