#include <bits/stdc++.h>
#include <fmt/core.h>


template <typename T> T larger(T a, T b){
    return a>b? a : b;
}

template<typename T> T* larger(T* a, T* b){
    return *a > *b ? a : b;
}

template<typename T> const T* larger(const std::vector<T>& data){
    const T* result{};
    for(auto& value: data){
        if(!result || value > *result)
            result = &value;
    }
    return result;
}

int main(){
    const int big_int{17011983}, small_int{10};
    fmt::print("Large of {} and {} is {}\n", big_int, small_int, larger(big_int, small_int));
    fmt::print("Large of {} and {} is {}\n", big_int, small_int, *larger(&big_int, &small_int));
    
    const std::vector<double> data {-1.4, 7.3, -100, 54.1, 16.3};
    fmt::print("The largest value in data: {}\n", *larger(data));

    const std::vector<std::string> words {"The", "highest", "words", "the", "fewer"};
    fmt::print("The largest word in words: {}\n", *larger(words));
}