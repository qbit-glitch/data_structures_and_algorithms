package main

import (
	"fmt"
	"sort"
)


func findContentChildren(g []int, s []int) int {
	var n int = len(g);
	var m int = len(s);

	sort.Ints(g);
	sort.Ints(s);

	g_pointer := 0;
	s_pointer := 0;

	for s_pointer < m{
		if g_pointer < n && g[g_pointer] <= s[s_pointer]{
			g_pointer += 1;
		}
		s_pointer++;
	}
	return g_pointer;
}

func main(){
	var greed []int = []int {1,5,3,3,4};
	size := []int {4,2,1,2,1,3};

	fmt.Println(findContentChildren(greed, size));
}