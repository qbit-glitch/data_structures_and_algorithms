/**
 * Leetcode-145: Post order traversal
*/

// Definition of the Binary Tree

use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
struct TreeNode{
    val: i32,
    left: Option<Rc<RefCell<TreeNode>>>,
    right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode{
    pub fn new(val: i32) -> Option<Rc<RefCell<Self>>> {
        Some(Rc::new(RefCell::new(TreeNode{
            val,
            left: None,
            right: None,
        })))
    }

    pub fn insert(root: Option<Rc<RefCell<Self>>>, val: i32) -> Option<Rc<RefCell<Self>>> {
        match root {
            None => Self::new(val),
            Some(node) => {
                let mut n = node.borrow_mut();

                if val < n.val {
                    let left = Self::insert(n.left.clone(), val);
                    n.left = left;
                }

                else {
                    let right = Self::insert(n.right.clone(), val);
                    n.right = right;
                }
                drop(n);
                Some(node)
            }
        }
    }
}

fn print_tree(root: &Option<Rc<RefCell<TreeNode>>>, prefix: &str, is_left: bool) {
    if let Some(node) = root {
        let n = node.borrow();
        
        let connector = if is_left { "|-- " } else {"'-- "};
        println!("{}{}{}", prefix, connector, n.val);

        let left = n.left.clone();
        let right = n.right.clone();
        drop(n);    // drop before recursing

        let new_prefix = format!("{}{}", prefix, if is_left { "|  "} else {"   "});
        print_tree(&left, &new_prefix, true);
        print_tree(&right, &new_prefix, false);
    }
}


struct Solution;

impl Solution{
    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut post: Vec<i32> = Vec::new();
        Self::postorder_rec(&root, &mut post);
        post
    }

    pub fn postorder_rec(root: &Option<Rc<RefCell<TreeNode>>>, post: &mut Vec<i32>) {
        match root {
            None => {},
            Some(node) => {
                let n = node.borrow();
                if let Some(left) = &n.left {
                    Self::postorder_rec(&Some(left.clone()), post);
                }

                if let Some(right) = &n.right {
                    Self::postorder_rec(&Some(right.clone()), post);
                }
                post.push(n.val);
            }
        }
    }
}






fn main(){
    let root = [50,30,70,20,40,60,80,10,24,13,56,78,90]
            .iter()
            .fold(None, |acc, &v| TreeNode::insert(acc, v));

    if let Some(node) = &root {
        let n = node.borrow();
        println!("{}",n.val);

        print_tree(&n.left, "", true);
        print_tree(&n.right, "", false);
    }

    let post = Solution::postorder_traversal(root.clone());
    println!("{post:?}");
}

