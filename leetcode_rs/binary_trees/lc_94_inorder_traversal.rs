/**
 * Leetcode-94: In-Order Traversal of Binary Tree
*/

// Definition for a binary tree node.


use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Option<Rc<RefCell<Self>>> {
        Some(Rc::new(RefCell::new(TreeNode {
            val,
            left: None,
            right: None
        })))
    }

    pub fn insert(root: Option<Rc<RefCell<Self>>>, val: i32) -> Option<Rc<RefCell<Self>>> {
        match root {
            None => Self::new(val),
            Some(node) => {
                let mut n = node.borrow_mut();

                if val < n.val {
                    let left_child = Self::insert(n.left.clone(), val);
                    n.left = left_child;
                } else {
                    let right_child = Self::insert(n.right.clone(), val);
                    n.right = right_child;
                }
                drop(n);    // mutable borrow must be dropped before returning
                Some(node)
            }
        }
    }
}

fn print_tree(root: &Option<Rc<RefCell<TreeNode>>>, prefix: &str, is_left: bool) {
    if let Some(node) = root {
        let n = node.borrow();

        let connector = if is_left { "├── " } else { "└── " };
        println!("{}{}{}", prefix, connector, n.val);

        let left_child = n.left.clone();
        let right_child = n.right.clone();
        drop(n);    // drop before recursing

        let new_prefix = format!("{}{}", prefix, if is_left { "│   " } else { "    " });
        print_tree(&left_child,  &new_prefix, true);
        print_tree(&right_child, &new_prefix, false);
    
    }
}




struct Solution;

impl Solution {
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ino: Vec<i32> = Vec::new();
        Self::inorder_rec(&root.clone(), &mut ino);
        ino
    }

    pub fn inorder_rec(root: &Option<Rc<RefCell<TreeNode>>>, ino: &mut Vec<i32>) {
        match root {
            None => {},
            Some(node) => {
                let n = node.borrow();
                if let Some(left) = &n.left {
                    Self::inorder_rec(&Some(left.clone()), ino);
                }
                ino.push(n.val);
                if let Some(right) = &n.right {
                    Self::inorder_rec(&Some(right.clone()), ino);
                }
            }
        }
    }

}


// ----------------------- MAIN FUNCTION -----------------------------
fn main() {
    let root = [50,30,70,20,40,60,80,10,13,24,56,78,90].iter().fold(None, |acc, &v| TreeNode::insert(acc, v));

    println!("{root:?}");

    if let Some(node) = &root {
        let r = node.borrow();
        
        println!("{}", r.val);

        print_tree(&r.left, "", true);
        print_tree(&r.right, "", false);
    }

    let ino = Solution::inorder_traversal(root.clone());
    println!("{ino:?}");
}

