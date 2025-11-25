/**
 * Leetcode-860: Lemonade Change
 * Link: https://leetcode.com/problems/lemonade-change/description/
*/

package main

import (
	"fmt"
)

func lemonadeChange(bills []int) bool {
	var five int = 0;
	var ten int = 0;
	for _, i := range bills {
		if i == 5 {
			five++;
		} else if i == 10 {
			if five > 0 {
				five--
				ten++
			} else {return false}
		} else {
			if five > 0 && ten > 0 {
				five --
				ten--
			} else if five >= 3 {
				five -= 3
			} else {
				return false
			}
		}
	} 
	return true
}

func main(){
	var bills []int = []int {5,5,5,10,20}
	fmt.Println(lemonadeChange(bills))
}