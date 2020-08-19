//
// Created by Ail on 11/03/2020.
//

#ifndef CXX_MAIN_HPP
#define CXX_MAIN_HPP

#include <type_traits>

#define main(...)   mainCPP(__VA_ARGS__);                           \
                    int main(int ac, char **argv, char **env)       \
                    { return declMain(ac, argv, env, &mainCPP); }   \
                    int mainCPP(__VA_ARGS__)


inline int declMain(int, char **, char **, int (*mainFunc)())
{
    return mainFunc();
}

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type=0>
inline int declMain(int ac, char **, char **, int (*mainFunc)(T))
{
    return mainFunc(ac);
}

template <typename T, typename std::enable_if<!std::is_arithmetic<T>::value, int>::type=0>
inline int declMain(int, char **av, char **, int (*mainFunc)(T))
{
    return mainFunc(av);
}

template <typename T1, typename T2, typename std::enable_if<std::is_arithmetic<T1>::value, int>::type=0>
inline int declMain(int ac, char **av, char **, int (*mainFunc)(T1, T2))
{
    return mainFunc(ac, av);
}

template <typename T1, typename T2, typename std::enable_if<!std::is_arithmetic<T1>::value, int>::type=0>
inline int declMain(int, char **av, char **env, int (*mainFunc)(T1, T2))
{
    return mainFunc(av, env);
}

template <typename ...Ts, typename std::enable_if<(sizeof...(Ts) == 3), int>::type=0>
inline int declMain(int ac, char **av, char **env, int (*mainFunc)(Ts...))
{
    return mainFunc(ac, av, env);
}

template <typename ...Ts, typename std::enable_if<(sizeof...(Ts) > 3), int>::type=0>
inline int declMain(int, char **, char **, int (*)(Ts...))
{
    static_assert(sizeof...(Ts) <= 3, "Your main can't have more than 3 arguments as parameters");
    return 0;
}

#endif //CXX_MAIN_HPP