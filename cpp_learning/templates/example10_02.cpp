#include <bits/stdc++.h>
#include <fmt/core.h>


// Using `decltype(auto)`
template<typename T1, typename T2>
decltype(auto) larger(const T1& a,const T2& b){
    return a > b ? a : b;
}

// Using `constexpr if`
template<typename T>
decltype(auto) larger(const T& a, const T& b){
    if constexpr(std::is_pointer_v<T>)   // Evaluated only at compile time
        return *a > *b ? a : b;          // Only compiled if T is a pointer
    
    else
        return a > b ? a : b;
}



