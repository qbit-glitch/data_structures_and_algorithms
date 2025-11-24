/**
 * Code360: Fractional Knapsack
 * Link: https://www.naukri.com/code360/problems/fractional-knapsack_975286
*/

package main

import (
	"fmt"
	"sort"
)

type Pair[T, U any] struct{
	Weights T
	Value U
}

func maximumValue(items []Pair[int, int], n int, w int) float64 {
	
	// original <weights, values> pairs
	fmt.Println(items)
	
	// using the sort.Slice method with a custom comparator to sort the pairs
	sort.Slice(items, func(i, j int) bool{
		return (float64(items[i].Value) / float64(items[i].Weights)) > (float64(items[j].Value) / float64(items[j].Weights))
	})

	// After sorting the items:  <weights, values> pairs
	fmt.Println(items)
	

	total_weights := 0
	total_val := 0.0

	// for index, element := range array {}
	for _, i := range items {
		if i.Weights + total_weights <= w{
			total_val += float64(i.Value)
			total_weights += i.Weights
		} else {
			total_val += (float64(i.Value) / float64(i.Weights)) * (float64(w) - float64(total_weights))
			break
		}
	}
	return total_val
}

func main(){
	items := []Pair[int, int] {{20,12}, {24,35}, {36,41}, {40,25}, {42,32}}
	fmt.Println(maximumValue(items, len(items), 100))
}