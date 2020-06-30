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


template <typename f, typename ...>
struct st_first_arg {
    typedef f first;
};

template <typename ...Ts>
using first_arg = typename st_first_arg<Ts...>::first;

template <typename ...Ts>
inline int declMain(int ac, char **av, char **env, int (*mainFunc)(Ts...))
{
    static_assert(sizeof...(Ts) <= 3, "Your main can't have more than 3 arguments as parameters");
    if constexpr (sizeof...(Ts) == 0) {
        return mainFunc();
    } else if constexpr (sizeof...(Ts) == 1) {
        if constexpr (std::is_arithmetic<first_arg<Ts...>>::value) {
            return mainFunc(ac);
        } else {
            return mainFunc(av);
        }
    } else if constexpr (sizeof...(Ts) == 2) {
        if constexpr (std::is_arithmetic<first_arg<Ts...>>::value) {
            return mainFunc(ac, av);
        } else {
            return mainFunc(av, env);
        }
    } else if constexpr (sizeof...(Ts) == 3) {
        return mainFunc(ac, av, env);
    }
    (void)ac;
    (void)av;
    (void)env;
    (void)mainFunc;
}

#endif //CXX_MAIN_HPP