---
title: "C++ Notes #1"
author: Umesh Kumar Singh
theme: 
    name: gruvbox-dark
    override :
        footer:
            style: progress_bar
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
    typst:
        ppi: 400
    
    typst:
        colors:
            background: ff0000
            foreground: 00ff00
---

Some Common Curiosity Questions
===

# How to sort a vector of pairs based on the second element

The shortest and the most easiest would be using the lambda function.

\- Example-1
```cpp
// Sort the vectors in increasing order with respect to the second element of each pair in a vector

vector<pair<int, int>> vec;

sort(vec.begin(), vec.end(), [](auto &left, auto &right) {
    return left.second < right.second;
});
```

\- Example-2
```cpp
// Sort the vectors in decreasing order with respect to the second element of each pair in a vector

vector<pair<int, int>> vec;

sort(vec.begin(), vec.end(), [](auto &left, auto &right) {
    return left.second > right.second;
});
```
<!-- end_slide -->

Some Common Curiosity Questions
===

