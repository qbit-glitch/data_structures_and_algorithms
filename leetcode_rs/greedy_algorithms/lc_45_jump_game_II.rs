/**
 * Leetcode-45: Jump Game - II
 * Link: https://leetcode.com/problems/jump-game-ii/description/
*/



// This solution is a Brute Force -> Trying out all possible using recursion

fn fn_r(nums: &Vec<i32>, ind: i32, cnt: i32) -> i32 {
    if ind >= (nums.len() - 1) as i32 {
        return cnt;
    }

    let mut mini: i32 = i32::MAX;
    let mut i: i32 = 1;
    while i <= nums[ind as usize] {
        mini = std::cmp::min(mini, fn_r(&nums, i as i32 + ind, cnt+1));
        i += 1;
    }
    return mini;
}

fn min_jumps(nums: &Vec<i32>) -> i32{
    let ind: i32 = 0;
    let cnt: i32 = 0;
    return fn_r(&nums, ind, cnt);
}



// Optimal Solution
fn min_jumps_optimal(nums: &Vec<i32>) -> i32{
    let mut jumps: i32 = 0;
    let mut l : i32 = 0;
    let mut r: i32 = 0;

    while r < (nums.len()-1) as i32 {
        let mut farthest: i32 = 0;
        for i in l..r+1 {
            farthest = std::cmp::max(farthest, i+nums[i as usize]);
        }
        l = r+1;
        r = farthest;
        jumps += 1;
    }
    return jumps;
}


fn main(){
    let nums: Vec<i32> = vec![2,3,1,4,1,1,1,2];
    println!("{}", min_jumps_optimal(&nums));
}