/**
 * Leetcode-55: jump Game
 * Link: https://leetcode.com/problems/jump-game/
*/

package main
import "fmt"

func canJump(nums []int) bool {
	var maxInd int = 0
	for idx,_ := range(nums){
		if(idx > maxInd){
			return false
		}
		maxInd = max(maxInd, idx + nums[idx])
	}
	return true
}

func main(){
	var nums = []int {1,2,3,1,1,0,2,5}
	fmt.Println(canJump(nums))
}