/**
 * Leetcode-860: Lemonade Change
 * Link: https://leetcode.com/problems/lemonade-change/description/
*/

fn lemonade_change(bills: Vec<i32>) -> bool {
    let mut five: i32 = 0;
    let mut ten: i32 = 0;

    for (_,bill) in bills.iter().enumerate(){
        if *bill == 5 {
           five += 1; 
        } else if *bill == 10 {
            if five > 0 {
                ten += 1;
                five -= 1;
            } else {
                return false;
            }
        } else {
            if five > 0 && ten > 0 {
                ten -= 1;
                five -= 1;
            } else if five >= 3 {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    true
}

fn main(){
    let bills: Vec<i32> = vec![5,5,5,10,20];
    println!("{}", lemonade_change(bills));
}