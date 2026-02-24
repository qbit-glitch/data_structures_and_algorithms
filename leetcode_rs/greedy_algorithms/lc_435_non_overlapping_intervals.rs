/**
 * Leetcode-435: Non Overlapping Intervals
*/

struct Solution;


impl Solution {
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        if intervals.len() == 0 || intervals.len() == 1 {
            return 0;
        }
        // sort with respect to the end_time of each interval
        intervals.sort_by(|a,b| a[1].cmp(&b[1]));
        println!("{:?}", intervals);

        let mut cnt: i32=1;
        let mut last_end_time = intervals[0][1];
        
        let mut i: usize = 1;

        while i < intervals.len() {
            // count the number of actual non-overlapping intervals
            if intervals[i][0] >= last_end_time {
                cnt += 1;
                last_end_time = intervals[i][1];
            }
            i+=1;
        }

        return intervals.len() as i32 - cnt;
    }
}

fn main(){
    let intervals: Vec<Vec<i32>> = vec![vec![0,0],vec![9,11],vec![1,3],vec![2,6],vec![8,10],vec![15,18],vec![20,26],vec![21,22],vec![23,24],vec![25,29],vec![30,35]];
    let results = Solution::erase_overlap_intervals(intervals.clone());
    println!("{:?}", results);
}