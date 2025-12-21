/**
 * GFG: Job Sequencing Problem
 * Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/


/** Algo:
 * 1. Create a vector of structs of fields {id, deadline, profit}
 * 2. Sort the vector of struct in decreasing order of profits
 * 3. Get the maximum deadline among the deadline array
 * 4. Initialize a hasharray with all elements as -1 with lenght = deadline.size()+1
 *      so that we can index the deadlines.
 * 5. Loop through each jobs in the newly sorted vector
 *      i. for j = jobs[i].deadline   -> j>0
 *            if(hasharray[j] == -1)    -> no job is scheduled at that location
 *                  cnt++ | maxProfit += jobs[i].profit | hasharray[j] = jobs[i].id
 *                  break
 * 6. Return {cnt, maxProfit}  
*/


struct Job {
    id: i32,
    deadline: i32,
    profit: i32,
}

fn job_sequencing(deadlines: Vec<i32>, profits: Vec<i32>) -> (i32, i32){
    let mut jobs: Vec<Job> = vec![];
    for i in 0..deadlines.len() {
        jobs.push(Job{
            id: i as i32,
            deadline: deadlines[i],
            profit: profits[i]
        });
    }
    jobs.sort_by(|a,b| {
        b.profit.cmp(&a.profit)
    });

    let mut max_deadline: i32 = 0;
    for i in &deadlines {
        max_deadline = std::cmp::max(max_deadline, *i);
    }
    
    
    let mut cnt: i32 = 0;
    let mut cnt_profits: i32 = 0;

    let mut hash_array: Vec<i32> = vec![-1; deadlines.len()+1];



    for (_, v) in jobs.iter().enumerate(){
        for j in (1..=v.deadline as usize).rev() {
            if hash_array[j] == -1 {
                cnt += 1;
                cnt_profits += v.profit;
                hash_array[j] = v.id;
                break;
            }
        }
    }
    
    (cnt, cnt_profits)
}

fn main(){
    let deadlines: Vec<i32> = vec![2,1,2,1,1];
    let profits: Vec<i32> = vec![100,19,27,25,15];

    println!("{:?}", job_sequencing(deadlines, profits));
}