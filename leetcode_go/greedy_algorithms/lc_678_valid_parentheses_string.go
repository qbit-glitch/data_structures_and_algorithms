/**
 * Leetcode-678: Valid Parentheses
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
*/


package main

import (
	"fmt"
)

// Brute forces solution: trying out all possible combinations using recursion
func fn_r(s string, ind int, cnt int) bool {
	if cnt < 0 {
		return false
	}
	if ind == len(s) {
		return cnt == 0
	}

	if s[ind] == '(' {
		return fn_r(s, ind+1, cnt+1)
	} else if s[ind] == ')' {
		return fn_r(s, ind+1, cnt-1)
	} else {
		return fn_r(s, ind+1, cnt+1) || fn_r(s, ind+1, cnt-1) || fn_r(s, ind+1, cnt)
	}
}

func checkValidString(s string) bool{
	var ind int = 0
	var cnt int = 0
	return fn_r(s, ind, cnt)
}


// Optimal Solution: instead of using cnt using min and max to track the range of values it can have
func checkValidString_optimal(s string) bool {
	var min int = 0
	var max int = 0

	for _, ch := range s{
		if ch == '(' {
			min += 1
			max += 1
		} else if ch == ')' {
			min -= 1
			max -= 1
		} else {
			min -= 1
			max += 1
		}

		if min < 0 {
			min = 0
		} 
		if max < 0 {
			return false
		}
	}

	return min == 0
}



func main(){
	var s string = "(()(**)"
	fmt.Println(checkValidString_optimal(s))
}