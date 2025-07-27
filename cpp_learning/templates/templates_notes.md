---
title: "C++ Templates"
author: Umesh Kumar Singh
theme: 
    name: gruvbox-dark
    override :
        footer:
            style: progress_bar
            # left: "My **name** is {author}"
            # center: "_@qbit_glitch_"
            right: "{current_slide} / {total_slides}"
            height: 1
        slide_title:
            padding_bottom: 0
            padding_top: 0
            separator: true
        headings:
            h1:
                prefix: "██"
            h2:
                prefix: "▓▓▓"
        code:
            theme_name: base16-ocean.dark
    image_protocol: kitty-local
    terminal_font_size: 18
---

Definition
===

A function template is a parametric function definition, where a particular function instance is created by one or more parameter values. The compiler uses a function template to generate a function definition when necessary. If it is never necessary, no code results from the template. A function definition that is generated from a template is an instance or an instantiation of the template.

<!-- end_slide -->

Function Templates and Overloading
===

```cpp
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

```
<!-- end_slide -->

Function Templates with Multiple Parameters: `decltype(auto)` & `constexpr if`
===

```cpp
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
```

<!-- end_slide -->

constexpr if
===

The expression inside our constexpr if statement, `std::is_pointer_v<T>`, is a type trait—in particular, one offered by the `<type_traits>` Standard Library module.

Standard type trait constructs whose name end in _v map one or more types onto a compile-time constant (a Boolean for `std::is_pointer_v<T>`); those ending in _t map one or more types onto another type. 

The `std::is_pointer_v<T>` expression, in particular, is a constant expression that evaluates to true if T is a pointer type, and false otherwise.

If, you instantiate the constexpr if version of the template with T equal to int, the code in the if branch is simply discarded, leaving only the code in the else branch.

Because all constexpr if statements need to be evaluated at compile time, it goes without saying that only constant expressions (literals, constants, type trait expressions, `constexpr` / `consteval` functions, and so on) may appear inside their condition.