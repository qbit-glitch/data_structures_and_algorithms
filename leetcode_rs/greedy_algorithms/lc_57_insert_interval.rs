/**
 * Leetcode-57: Insert interval
 * Link: https://leetcode.com/problems/insert-interval/
*/


struct Solution;

impl Solution{
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = vec![];
        let mut start = -1;
        let mut end;

        let mut i = 0;
        let mut inserted = false;
        while i < intervals.len() {
            if !inserted && new_interval[1] < intervals[i][0] {
                ans.push(new_interval.clone());
                inserted = true;
                start = 0;
            }

            if (new_interval[1] >= intervals[i][0]) && (new_interval[0] <= intervals[i][1]) && (start == -1) {
                start = std::cmp::min(intervals[i][0], new_interval[0]);
                while i < intervals.len() && new_interval[1] >= intervals[i][0] {
                    i += 1;
                }
                if i > 0{
                    i = i-1;
                }
                end = std::cmp::max(new_interval[1], intervals[i][1]);
                ans.push(vec![start, end]);
                inserted = true;
            } else {
                ans.push(intervals[i].clone());
            }
            i += 1;
        }
        if start == -1 {
            ans.push(new_interval.clone());
        }
        ans
    }
}

fn main(){
    let intervals: Vec<Vec<i32>> = vec![vec![1,5]];
    let new_interval = vec![6,8];
    let solution = Solution::insert(intervals, new_interval);
    println!("{:?}", solution);
}