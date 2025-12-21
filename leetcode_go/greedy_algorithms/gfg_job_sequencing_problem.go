/**
 * GFG: Job Sequencing Problem
 * Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/



/** Algo:
 * 1. Create a vector of structs of fields {id, deadline, profit}
 * 2. Sort the vector of struct in decreasing order of profits
 * 3. Get the maximum deadline among the deadline array
 * 4. Initialize a hasharray with all elements as -1 with lenght = deadline.size()+1
 *      so that we can index the deadlines.
 * 5. Loop through each jobs in the newly sorted vector
 *      i. for j = jobs[i].deadline   -> j>0
 *            if(hasharray[j] == -1)    -> no job is scheduled at that location
 *                  cnt++ | maxProfit += jobs[i].profit | hasharray[j] = jobs[i].id
 *                  break
 * 6. Return {cnt, maxProfit}  
*/



package main

import (
	"fmt"
	"sort"
)

type Job struct{
	id int
	deadline int
	profit int
}



func jobSequencing(deadlines []int, profits []int) (int, int){
	var jobs []Job = make([]Job, len(deadlines))
	for i := 0; i<len(deadlines); i++ {
		jobs[i] = Job{
			i,
			deadlines[i],
			profits[i],
		}
	}

	sort.Slice(jobs, func(left , right int) bool {
		return jobs[left].profit > jobs[right].profit
	})

	var maxDeadline int = 0
	var cnt int = 0
	var cntProfit int = 0

	for _,v := range deadlines {
		maxDeadline = max(maxDeadline, v)
	}

	var hashArray []int = make([]int, len(deadlines)+1)
	for i,_ := range hashArray {
		hashArray[i] = -1
	}


	for _,v := range jobs {
		for j:= v.deadline; j>0; j-- {
			if hashArray[j] == -1 {
				cnt += 1
				cntProfit += v.profit
				hashArray[j] = v.id
				break
			}
		}
	}
	
	return cnt, cntProfit;
}

func main() {
	var deadlines []int = []int {2,1,2,1,1}
	var profits []int = []int {100,19,27,25,15}

	fmt.Println(jobSequencing(deadlines, profits))
}