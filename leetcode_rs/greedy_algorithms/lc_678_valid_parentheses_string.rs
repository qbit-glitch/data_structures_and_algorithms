/**
 * Leetcode-678: Valid Parentheses
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
*/

// Brute Force: Trying out all possible combinations using recursion
fn fn_rec(s: String, ind: usize, cnt: i32) -> bool {
    if cnt < 0 {
        return false;
    }
    if ind == s.len() {
        return cnt == 0;
    }

    if s.chars().nth(ind).unwrap() == '(' {
        return fn_rec(s, ind+1, cnt+1);
    }
    else if s.chars().nth(ind).unwrap() == ')' {
        return fn_rec(s, ind+1, cnt-1);
    } else {
        return fn_rec(s.clone(), ind+1, cnt+1) || fn_rec(s.clone(), ind+1, cnt-1) || fn_rec(s, ind+1, cnt);
    }
}

fn check_valid_string(s: String) -> bool{
    let ind: usize = 0;
    let cnt: i32 = 0;

    return fn_rec(s, ind, cnt);
}

fn main(){
    let s: String = ")()((**)".to_string();
    println!("{}", check_valid_string(s.clone()));
}