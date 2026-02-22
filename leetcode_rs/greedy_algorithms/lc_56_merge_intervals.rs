/**
 * Leetcode-56: Merge Intervals
*/

struct Solution;

impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if intervals.len() == 0 || intervals.len() == 1 {
            return intervals;
        }
        
        // Sort the intervals based on the `start`
        intervals.sort_by(|a,b| a[0].cmp(&b[0]));

        let mut result: Vec<Vec<i32>> = vec![];
        let mut idx: usize = 0;
        let mut end: i32 = -1;
        let mut start: i32 = -1;

        let mut i: usize = 1;

        while i < intervals.len() {
        
            start = intervals[idx][0];
            let t = intervals[idx][1];

            if end == -1 {
                end = t;
            }

            if intervals[i][0] <= end {
                end = std::cmp::max(intervals[i][1], end);
            } else {
                result.push(vec![start, end]);
                idx = i; 
                end = -1;
            }
            
            i += 1;
        }

        if end != -1 {
            result.push(vec![start, end]);
        }

        if idx == intervals.len()-1 && end == -1 {
            result.push(intervals[idx].clone())
        }

        result
    } 
}

fn main() {
    let intervals: Vec<Vec<i32>> = vec![vec![0,0],vec![0,1],vec![8,10],vec![1,3],vec![2,6],vec![15,18],vec![20,26],vec![23,24],vec![25,29], vec![21,22], vec![30,35]];
    let results = Solution::merge(intervals);
    println!("{:?}", results);
}