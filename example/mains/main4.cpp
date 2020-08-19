//
// Created by Ail on 30/06/2020.
//

#include "MainC++.hpp"
#include "Args.hpp"
#include <iostream>

// This main will display and every argument and environment variables
int main(const Args &args, Args env)
{
    for (const auto &arg : args)
        std::cout << arg << std::endl;

    std::cout << std::endl;

    for (const auto &arg : env)
        std::cout << arg << std::endl;

    return 0;
}