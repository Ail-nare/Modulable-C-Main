//
// Created by Ail on 30/06/2020.
//

#include "MainC++.hpp"
#include "Args.hpp"
#include <iostream>

// This main will display the adr of the env
int main(void *, const void *env)
{
    std::cout << env << std::endl;
    return 0;
}