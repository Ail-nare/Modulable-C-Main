//
// Created by Ail on 30/06/2020.
//

#include "MainC++.hpp"
#include "Args.hpp"
#include <iostream>

// This main will display every argument
int main(const Args args)
{
    for (const auto &arg : args)
        std::cout << arg << std::endl;

    return 0;
}