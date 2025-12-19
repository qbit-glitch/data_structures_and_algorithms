/**
 * GFG: Minimum Platforms
 * Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
*/

fn min_platforms(mut arr: Vec<i32>, mut dep: Vec<i32>) -> i32 {
    arr.sort();
    dep.sort();

    let mut i: usize = 0;
    let mut j: usize = 0;
    let mut cnt: i32 = 0;
    let mut max_cnt: i32 = 0;

    while i < arr.len() {
        if arr[i] < dep[j] {
            cnt+=1;
            i += 1;
        } else {
            cnt -= 1;
            j += 1;
        }
        max_cnt = std::cmp::max(cnt, max_cnt);
    }
    max_cnt
}

fn main(){
    let arr: Vec<i32> = vec![900, 945, 955, 1100, 1500, 1800];
    let dep: Vec<i32> = vec![920, 1200, 1130, 1150, 1900, 2000];

    println!("{}", min_platforms(arr, dep));
}