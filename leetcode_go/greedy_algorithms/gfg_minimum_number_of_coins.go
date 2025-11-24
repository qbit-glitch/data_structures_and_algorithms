/**
 * GFG: Minimum Number Of Coins
 * Link: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
*/

package main
import(
	"fmt"
)

func findMin(n int)  int {
	coins := []int{10,5,2,1}
	var total_coins int = 0
	for _, coin := range coins {
		q := n/coin;
		if q!=0 {
			total_coins += q
			n = n - q*coin
		}
	}
	return total_coins
}

func main(){
	fmt.Println(findMin(121))
}