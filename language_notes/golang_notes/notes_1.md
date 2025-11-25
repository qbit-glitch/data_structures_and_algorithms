---
title: "Golang Notes #1"
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

Some Curiosity Questions
===

# 1. How to sort an array of pairs with respect to the second element

There are two ways : 

1. To sort an array of pairs based on the second element in Go, you can define a custom type that implements the `sort.Interface` with methods `Len`, `Less`, and `Swap`. The `Less` method should compare the second elements of the pairs. Here's an example using a `Pair` struct with `Key` and `Value` fields:

```go
type Pair struct{
    Key string
    Value int
}

type ByValue []Pair

func (s ByValue) Len() int {
    return len(s)
}

func (s ByValue) Swap(i int, j int){
    s[i], s[j] = s[j], s[i]
}

func (s ByValue) Less(i, j int) bool{
    return s[i].Value < s[j].Value
}

// After defining these functions call the function sorting the Array of Pairs
pairs := []Pair {{'a',1}, {'b',0}, {'c',-1}}
sort.Sort(ByValue(pairs))
fmt.Println(pairs)

```

<!-- end_slide -->

Some Curiosity Questions
===

# 1. How to sort an array of pairs with respect to the second element

2. Using `sort.Slice` using custom comparison function

```go
type Pair struct{
    Key string
    Value int
}

pairs := []Pair {{'a',1}, {'b',0}, {'c',-1}}

sort.Slice(pairs, func(i,j int){
    return pairs[i].Value < pairs[j].Value
})

fmt.Println(pairs)

```

<!-- end_slide -->

Some Curiosity Questions
===

## 2. Are Semi-Colons necessary at the end of every statement in Go

\- In Go, semicolons are not necessary at the end of every statement in most cases due to automatic semicolon insertion (ASI).

\- The Go compiler automatically inserts semicolons at the end of statements when it encounters a newline, provided the last token on the line is an identifier, a literal (such as a number or string), or one of specific keywords and operators like break, continue, fallthrough, return, ++, --, ), ], or }. This means that writing each statement on a separate line typically eliminates the need for explicit semicolons.

\- However, there are specific situations where semicolons are required. They are necessary when multiple statements appear on the same line, such as in for loop clauses to separate the initializer, condition, and continuation elements.

\- Additionally, semicolons are required within parenthesized lists of declarations, such as in const (a = 1; b = 2). While the second rule allows omission of semicolons before closing braces, such as in if true { doSomething() }, the compiler still treats the statement as properly terminated.

\- In summary, semicolons are not needed at the end of every statement in Go due to automatic insertion, but they are required in specific contexts like multiple statements on one line or within parenthesized declarations.

<!-- end_slide -->

Some Curiosity Questions
===

### 3. How to perform typecasting in Go

\- In Go, converting an int to a float64 (commonly referred to as "double" in other languages) requires explicit type conversion using the syntax float64(value).

\- This is because Go does not support implicit type casting, meaning you must manually specify the conversion.

For example:

```go
var intValue int = 42
var floatValue float64 = float64(intValue)
```

\- This conversion is safe for widening operations, such as from int to float64, as it can represent all integer values without loss of precision. However, the reverse—converting a float64 to an int—truncates the decimal part and may result in data loss.

\- When working with dynamic data stored in interface{}, such as JSON responses, you must first perform a type assertion to extract the underlying value before converting it to another type.

<!-- end_slide -->

Some Curiosity Questions
===

# 4. How to iterate through an array in Go

In Go, there are several ways to iterate through an array. The most common and idiomatic method uses the range keyword within a for loop, which provides both the index and the value of each element.
The syntax for this approach is:

```go
for index, element := range array {
    // process element
}
```

Here, index represents the current element's position, and element holds the value at that index. If you only need the value and not the index, you can use the blank identifier _ to ignore the index:

```go
for _, element := range array {
    // process element
}
```

Alternatively, you can use a traditional for loop with an index counter, initializing it to 0, checking if it is less than the array's length using len(array), and incrementing it after each iteration.

The syntax for this method is:

```go
for i := 0; i < len(array); i++ {
    // process array[i]
}
```

This approach gives you direct access to each element via its index. While this method is more verbose, it is useful when you need to modify the array elements during iteration or when working with complex indexing logic.

For multidimensional arrays or slices, you can nest for loops using range to iterate over each dimension.

Additionally, you can use range to iterate over strings, maps, and channels, making it a versatile construct for various data types.

<!-- end_slide -->

Some Curiosity Questions
===

## 5. How initialize an array of a fixed capacity in Go

In Go, arrays have a fixed size determined at compile time, so you cannot initialize an array with a "particular capacity" in the same way as a slice. However, you can create a slice with a specified length and capacity using the make function. To initialize an empty slice with a specific capacity, use `make([]Type, 0, capacity)`, where Type is the element type and capacity is the desired capacity.

For example, `make([]int, 0, 10)` creates an empty slice of integers with a capacity of 10. This slice has a length of 0 and can grow up to the specified capacity without reallocation. While []Type{} creates an empty slice with zero length and zero capacity, make allows explicit control over the initial capacity, which is useful when you know the approximate number of elements you will add.


```go
mySlice1 := make([]int, 0)
mySlice2 := []int{}
fmt.Println("mySlice1", cap(mySlice1))
fmt.Println("mySlice2", cap(mySlice2))
```
Output:

```go
mySlice1 0
mySlice2 0
```

Both slices have 0 capacity which implies both slices have 0 length (cannot be greater than the capacity) which implies both slices have no elements. This means the 2 slices are identical in every aspect.