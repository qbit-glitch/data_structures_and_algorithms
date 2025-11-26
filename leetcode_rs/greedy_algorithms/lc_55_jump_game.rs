/**
 * Leetcode-55: jump Game
 * Link: https://leetcode.com/problems/jump-game/
*/

fn can_jump(nums: Vec<i32>) -> bool {
    let mut max_ind: i32 = 0;
    for (idx, el) in nums.iter().enumerate() {
        if (idx as i32) > max_ind {
            return false;
        }
        max_ind = std::cmp::max((idx as i32) + el, max_ind);
    }
    return true;
}

fn main(){
    let nums: Vec<i32> = vec![1,2,3,1,1,0,2,5];
    println!("{}", can_jump(nums));
}