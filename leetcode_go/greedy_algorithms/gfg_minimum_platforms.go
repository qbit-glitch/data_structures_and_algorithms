/**
 * GFG: Minimum Platforms
 * Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
*/

package main

import (
	"fmt"
	"sort"
)

func minPlatforms(arr []int, dep []int)	int {
	sort.Ints(arr[:])
	sort.Ints(dep[:])

	i := 0
	j := 0
	cnt := 0
	maxCnt := 0

	for i < len(arr) {
		if arr[i] <= dep[j] {
			cnt += 1
			i += 1
		} else {
			cnt -= 1
			j += 1
		}
		maxCnt = max(maxCnt, cnt)
	}
	return maxCnt
}

func main(){
	arr := []int {900,945,955,1100,1500,1800}
	dep := []int {920,1200,1130,1155,1900,2000}
	
	fmt.Println(minPlatforms(arr, dep))
}