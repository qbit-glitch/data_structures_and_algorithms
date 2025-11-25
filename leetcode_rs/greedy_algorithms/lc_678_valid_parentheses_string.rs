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



// Optimal Solution
fn check_valid_string_optimal(s: String) -> bool {
    let mut min: i32 = 0;
    let mut max: i32 = 0;

    for ch in s.chars(){
        if ch == '(' {
            min += 1;
            max += 1;
        } else if ch == ')' {
            min -=1; max-=1;
        } else {
            min -= 1; max += 1;
        }

        if min < 0 {
            min = 0;
        }
        if max < 0 {
            return false;
        }
    }
    return min == 0;
}


fn main(){
    let s: String = ")()((**)".to_string();
    println!("{}", check_valid_string_optimal(s.clone()));
}