/**
 * Leetcode-45: Jump Game - II
 * Link: https://leetcode.com/problems/jump-game-ii/description/
 */

package main

import (
	"fmt"
	"math"

	"golang.org/x/exp/constraints"
)

func min[T constraints.Ordered] (a,b T) T{
	if a < b {
		return a
	} else {
		return b
	} 
}


// Brute Force: recursive solution -> trying out all possible combinations
func fn_r(nums []int, ind int, jumps int) int{
	if ind >= len(nums)-1 {
		return jumps;
	}
	var min_jumps = math.MaxInt
	for i := 1; i<= nums[ind]; i++ {
		min_jumps = min(min_jumps, fn_r(nums, ind + i, jumps+1))
	}
	return min_jumps
}

func jump(nums []int) int {
	var ind int = 0
	var cnt int = 0
	return fn_r(nums, ind, cnt)
}


// Optimal Solution using range of the values : [left, right]
func minJumps(nums []int) int {
	var l int = 0
	var r int = 0
	var jumps int = 0
	for r < len(nums)-1 {
		var farthest int = 0
		for i:=l; i<=r; i++ {
			farthest = max(farthest, i + nums[i])
		}
		l = r+1
		r = farthest
		jumps += 1
	}
	return jumps
}




func main(){
	var nums []int = []int {2,3,1,4,1,1,1,2}
	fmt.Println(minJumps(nums))
}