/**
 * Code360: Fractional Knapsack
 * Link: https://www.naukri.com/code360/problems/fractional-knapsack_975286
*/




fn maximum_value(mut items: Vec<(i32,i32)>, w: i32) -> f64 {
    
    // before sorting
    println!("Before Sorting: \n{:?}", items);
    
    // custom sorting using values to weights ratio
    items.sort_by(|i,j| {
        let ratio_i = if i.0 != 0 { 
            (i.1 as f64)/ (i.0 as f64)
        } else {
            f64::NEG_INFINITY
        };

        let ratio_j = if j.0 != 0 {
            (j.1 as f64) / (j.0 as f64)
        } else {
            f64::NEG_INFINITY
        };

        ratio_j.partial_cmp(&ratio_i).unwrap()      // ensure valid ordering comparison
    });
    
    // after sorting
    println!("After Sorting: \n{:?}", items);

    let mut total_weights: i32 = 0;
    let mut total_val: f64 = 0.0;

    // weights and values are the references to elements in items vectors. Specifically they are of type &i32

    for (weights, values) in items.iter() {
        if total_weights + weights <= w {
            total_val += *values as f64;
            total_weights += weights;
        } else {
            total_val += ((*values as f64)/(*weights as f64)) * ((w - total_weights) as f64);
            break;
        }
    }

    total_val
}

fn main(){
    let weights = vec![50,40,90,120,10,200];
    let values = vec![40,50,25,100,30,45];

    let pairs: Vec<(i32, i32)> = weights.into_iter().zip(values).collect();
    // println!("{:?}", pairs);

    println!("{}", maximum_value(pairs, 200))
}

