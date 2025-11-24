---
title: "Rust Notes #1"
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

## 1. What is `usize` in rust ?

\- The usize type in Rust is a primitive, pointer-sized unsigned integer type that can represent every memory address in the process. Its size is determined by the architecture of the machine, being 64 bits on a 64-bit system and 32 bits on a 32-bit system. This adaptability ensures portability across different platforms.

\- It is primarily used for indexing and memory-related operations, such as array indexing, because it corresponds to the size of a pointer. The usize type is essential in systems programming and is designed to be the natural choice for representing sizes and indices.
It can represent any location in memory, making it ideal for operations that involve memory addresses or sizes.

<!-- end_slide -->

Some Common Curiosity Questions
===

## 2. How to create a Vector of Pairs in rust ?

In Rust, you can create a vector of pairs using several idiomatic approaches. The most common and efficient method is to use the zip function from the standard library to combine two vectors into a single iterator of tuples, which can then be collected into a `Vec<(T, U)>`.

For example:

```rust
let xvector = vec![0., 1., 2., 3., 4.];
let yvector = vec![0., 2., 4., 6., 8.];
let data: Vec<(f64, f64)> = xvector.into_iter().zip(yvector).collect();
```

This approach moves the elements out of the original vectors and avoids the need to dereference references, resulting in a clean and efficient solution.

<!-- end_slide -->

Some Common Curiosity Questions
===

## 3. How to sort a vector of pairs

To sort a vector of pairs in Rust, you can use the sort_by_key method to sort based on a specific element of the pair, or sort_by for more complex custom logic. For sorting by the first element of each pair, use `sort_by_key(|pair| pair.0)`. To sort by the second element, use `sort_by_key(|pair| pair.1)`. This approach is efficient and clean for simple cases.

For more complex sorting, such as sorting by multiple fields or applying custom logic, use sort_by with a closure that returns an Ordering value. For example, to sort a vector of tuples by the second element in ascending order, you can use `pairs.sort_by(|a, b| a.1.cmp(&b.1))`.

If you need to sort by multiple fields, you can use a tuple as the key in sort_by_key, which compares lexicographically. For instance, to sort by the second element first and then the first element, use `v.sort_by_key(|pair| (pair.1, pair.0))`.

If you need descending order for a specific field, reverse the comparison logic in the closure. For example, to sort by the first element in descending order, use ```sort_by(|a, b| b.0.cmp(&a.0))```.

The sort_by_key method is often preferred for key-based sorting as it is more readable and efficient.

<!-- end_slide -->

Some Common Curiosity Questions
===

## 4. How to iterate through vector of pairs

To iterate through a vector of pairs in Rust, you can use the iter() method on the vector and then use destructuring in a for loop to access each pair. For example, if you have a vector of tuples, you can iterate over them directly:

```rust
let pairs = vec![(1, 2), (3, 4), (5, 6)];
for (a, b) in pairs.iter() {
    println!("{} {}", a, b);
}
```

This will print each element of the pairs. The iter() method provides an iterator over references to the elements, and destructuring with (a, b) allows you to extract the components of each tuple.


### 5. How to typecast `int` to `f64`

\- In Rust, to convert an integer to a floating-point number such as f64 (double precision), you use the as keyword for explicit casting.

\- For example, if you have an integer x, you can convert it to a f64 with `let y = x as f64;`.

\- This operation is well-defined and will produce the floating-point representation of the integer value, with rounding if necessary.

\- Rust does not allow implicit type conversions between primitive types, so explicit casting is required.

\- The as keyword performs the minimal amount of work to treat the value as the new type, and for integer-to-float conversions, it follows standard numeric casting rules.

<!-- end_slide -->

Some Common Curiosity Questions
===


