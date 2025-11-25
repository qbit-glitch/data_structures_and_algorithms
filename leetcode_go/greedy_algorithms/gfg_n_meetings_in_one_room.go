/**
 * GFG: N meetings in one room
 * Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/


package main

import (
	"fmt"
	"sort"
)

type Triplet struct {
	start int
	end int
	position int
}

func maxMeetings(start []int, end []int)	int {
	
	var meetings []Triplet = make([]Triplet, len(start));

	for i, _ := range start {
		meetings[i] = Triplet{start[i], end[i], i}
	}

	// Sort the meetings array
	sort.Slice(meetings, func(left, right int) bool {
		return meetings[left].end < meetings[right].end;
	})

	fmt.Println(meetings)

	var prev_end int = -1
	var cnt int = 0
	for _,elem := range meetings{
		if elem.start > prev_end{
			cnt += 1
			prev_end = elem.end
		}
	}
		
	return cnt
}

func main(){
	var start []int = []int {0,3,1,5,5,8}
	var end []int = []int {5,4,2,9,7,9}
	fmt.Println(maxMeetings(start, end))
}
