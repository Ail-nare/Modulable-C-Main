//
// Created by Ail on 09/03/2020.
//

#ifndef ARK_ARGS_HPP
#define ARK_ARGS_HPP

#include <vector>
#include <string>
#include <stdexcept>

class Args: public std::vector<std::string> {
    static constexpr const char *out_of_bound = "Args out of bound!";
public:
    Args()=delete;
    Args(const char * const * args) noexcept;

    std::string &operator[](unsigned int idx);
    const std::string &operator[](unsigned int idx) const;
};

inline Args::Args(const char * const * args) noexcept
{
    int len = 0;

    for (; args[len]; ++len);
    this->resize(len);
    for (int i = 0; i < len; ++i)
        (*static_cast<std::vector<std::string> *>(this))[i] = args[i];
}

inline std::string & Args::operator[](unsigned int idx)
{
    if (idx >= (unsigned int )this->size())
        throw std::out_of_range(Args::out_of_bound);
    return (*static_cast<std::vector<std::string> *>(this))[idx];
}

inline const std::string & Args::operator[](unsigned int idx) const
{
    if (idx >= (unsigned int )this->size())
        throw std::out_of_range(Args::out_of_bound);
    return (*static_cast<const std::vector<std::string> *>(this))[idx];
}

#endif //ARK_ARGS_HPP
