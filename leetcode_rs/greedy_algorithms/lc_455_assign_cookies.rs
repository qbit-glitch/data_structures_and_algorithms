
fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {      
    g.sort();
    s.sort();

    let mut s_pointer = 0 as usize;
    let mut g_pointer = 0 as usize;

    while s_pointer < s.len() {
        if g_pointer < g.len() && g[g_pointer] <= s[s_pointer] {
            g_pointer += 1;
        }
        s_pointer += 1;
    }

    let final_val = g_pointer as i32;
    final_val
}



fn main(){
    let greed = vec![1,5,3,3,4];
    let size = vec![4,2,1,2,1,3];
    let result = find_content_children(greed, size);
    println!("{}",result);
}