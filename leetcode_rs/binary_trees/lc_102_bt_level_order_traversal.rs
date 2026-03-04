/// Leetcode-102: Binary Tree Level Order Traversal

/// **Hint**: Level Order Traversal of a Binary Tree can be done using a Queue data structure.
/// For Implementing a Queue Data Structure: use the standard library container named: `VecDeque`
/// *Sample Usage of VecDeque* :
/// ```rust
/// use std::collections::VecDeque;
/// 
/// fn main() {
///     let mut queue = VecDeque::new();
///     queue.push_back(1);
///     queue.push_back(2);
///     queue.push_back(3);
/// 
///     // Dequeue elements
///     while let Some(front_element) = queue.pop_front() {
///         println!("Dequeued Element: {}", front_element);
///     }
/// }
/// ```

// Constructing a binary tree

/// Some Pronunciations and understanding :
///  left: Option < Rc < RefCell < TreeNode >>>
//    ^^^^^^   ^^   ^^^^^^^   ^^^^^^^^
//      |       |      |          |
//      |       |      |        the actual node data
//      |       |    runtime borrow checking — allows interior mutability
//      |     reference counted smart pointer — allows multiple owners
//    maybe a value, maybe nothing (None)

use std::cell::RefCell;
use std::rc::Rc;
use std::collections::VecDeque;

#[derive(Debug, PartialEq, Eq)]
struct TreeNode{
    val: i32,
    left: Option<Rc<RefCell<TreeNode>>>,
    right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode{
    #[inline]
    pub fn new(val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        Some(Rc::new(RefCell::new(TreeNode{
            val,
            left: None,
            right: None,
        })))
    }

    pub fn insert(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => Self::new(val),
            Some(node) => {
                let mut n = node.borrow_mut();

                if val < n.val {    // insert the new node on the left of the current node
                    let left = Self::insert(n.left.clone(), val);
                    n.left = left;
                } else {
                    let right = Self::insert(n.right.clone(), val);
                    n.right = right;
                }
                drop(n);    // drop the borrow before returning from the function
                Some(node)
            }
        }
    }
}


/// printing each node via depth-first traversal
fn print_tree(root: &Option<Rc<RefCell<TreeNode>>>, prefix: &str, is_left: bool) {
    if let Some(node) = root {
        let n = node.borrow();

        let connector = if is_left {"|--"} else {"'--"};
        println!("{}{}{}", prefix, connector, n.val);

        let left_child = n.left.clone();
        let right_child = n.right.clone();

        drop(n);

        let new_prefix = format!("{}{}",prefix, if is_left {"|  "} else {"   "});
        print_tree(&left_child, &new_prefix, true);
        print_tree(&right_child, &new_prefix, false);
    }
}

struct Solution;

impl Solution{
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();

        if let Some(node) = root {
            queue.push_back(node.clone());
        }
        
        while !queue.is_empty() {
            
            let len = queue.len();
            let mut level: Vec<i32> = Vec::new();
            
            for _ in 0..len {
                if let Some(que) = queue.pop_front(){
                    
                    let n = que.borrow();
                    if let Some(left_child) = &n.left {
                        queue.push_back(Rc::clone(left_child));
                    }
                    if let Some(right_child) = &n.right {
                        queue.push_back(Rc::clone(right_child));
                    }
                    level.push(n.val);
                }
            }
            ans.push(level);
        }
        ans    
    }

    pub fn print_level_order(root: Option<Rc<RefCell<TreeNode>>>) {
        let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        if let Some(node) = &root {
            queue.push_back(node.clone());

            while let Some(que) = queue.pop_front() {
                let q = que.borrow();
                println!("{}", q.val);

                if let Some(left) = &q.left {
                    queue.push_back(Rc::clone(left));
                }
                if let Some(right) = &q.right {
                    queue.push_back(Rc::clone(right));
                }
            }
        }
        
    }
}


/// Define a function to print the `type` of a custom variable

use std::any::type_name;
fn print_type_of<T>(_: &T) {
    println!("Type: {}", type_name::<T>());
}



fn main(){
    let root = [50,30,70,20,40,60,80,10,13,24,56,78,90]
                .iter()
                .fold(None, |acc, &v| TreeNode::insert(acc, v));
    
    // printing each node via depth first traversal
    if let Some(node) = &root {
        let n = node.borrow();
        println!("{}",n.val);

        print_tree(&n.left, "", true);
        print_tree(&n.right, "", false);
    }

    Solution::print_level_order(root.clone());

    let levels = Solution::level_order(root.clone());
    println!("{levels:?}");
}