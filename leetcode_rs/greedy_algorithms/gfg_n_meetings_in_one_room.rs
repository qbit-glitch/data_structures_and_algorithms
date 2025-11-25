/**
 * GFG: N meetings in one room
 * Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/
#[derive(Debug)]
struct Triplet {
    start: i32,
    end: i32,
    position: i32,
}

fn max_meetings(start: Vec<i32>, end: Vec<i32>) -> i32 {
    let mut meetings: Vec<Triplet> = vec![];
    for i in 0..start.len() {
        meetings.push(Triplet{
            start: start[i],
            end: end[i],
            position: i as i32
        });
    }
    
    meetings.sort_by(|a,b| {
        a.end.cmp(&b.end)
    });
    println!("{:#?}", meetings);

    let mut cnt : i32 = 0;
    let mut prev_end: i32 = 0;
    for element in meetings.iter() {
        if element.start > prev_end {
            cnt += 1;
            prev_end = element.end;
        }
    }

    return cnt;
}


fn main(){
    let start: Vec<i32> = vec![0,3,1,5,5,8];
    let end: Vec<i32> = vec![5,4,2,9,7,9];

    println!("{}", max_meetings(start, end));    
}