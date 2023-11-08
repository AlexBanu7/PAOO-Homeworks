#ifndef CREDIT_CARD_CONFIG_HPP
#define CREDIT_CARD_CONFIG_HPP

#include <iostream>

#ifndef COPYRIGHT_INFO
#define COPYRIGHT_INFO "Copyright 02"
#endif

namespace credit_card {

inline void version()
{
    std::cout << "Application " << "Credit Card" << std::endl 
              << "Version " << "0.2" << std::endl 
              << COPYRIGHT_INFO << std::endl
              << std::endl;
}

} // namespace credit_Card

#endif