/**
 * GFG: Minimum Number Of Coins
 * Link: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
*/

fn find_min(mut n: i32) -> i32{
    let coins: Vec<i32> = vec![10,5,2,1];
    let mut total_coins: i32 = 0;
    for coin in coins.iter() {
        let q: i32 = n/coin;
        if q!=0 {
            total_coins += q;
            n = n - q*coin;
        }
    }
    total_coins
}

fn main(){
    println!("{}", find_min(121));
}