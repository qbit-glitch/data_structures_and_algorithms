/**
 * Topic: Building a simple BT in an incremental manner
*/

#[derive(Debug)]
struct TreeNode<T> {
    val: T,
    left: Option<Box<TreeNode<T>>>,
    right: Option<Box<TreeNode<T>>>,
}

impl<T: Ord + std::fmt::Display> TreeNode<T> {
    fn new(val: T) -> Box<Self> {
        Box::new(Self{
            val,
            left: None,
            right: None,
        })
    }

    fn insert(root: Option<Box<Self>>, val: T) -> Option<Box<Self>> {
        match root {
            None => Some(Self::new(val)),
            Some(mut node) => {
                if val < node.val {
                    node.left = Self::insert(node.left, val);
                } else {
                    node.right = Self::insert(node.right, val);
                }
                Some(node)
            }
        }
    }
}

fn print_tree<T>(node: &Option<Box<TreeNode<T>>>, prefix: &str, is_left: bool) 
where
    T: std::fmt::Display
{
    if let Some(n) = node {
        let connector = if is_left {"|-- "} else {"└-- "};
        println!("{}{}{} ", prefix, connector, n.val);
    
        if n.left.is_some() || n.right.is_some() {
            let new_prefix = format!("{}{}", prefix, if is_left {"|  "} else {"   "});
            print_tree(&n.left, &new_prefix, true);
            print_tree(&n.right, &new_prefix, false);
        }
    } 
}

// ---------------------- TRAVERSALS -------------------------------

#[derive(Debug)]
struct Traversals<T>{
    pre: Vec<T>,
    ino: Vec<T>,
    post: Vec<T>,
}

impl<T> Default for Traversals<T> {
    fn default() -> Self{
        Traversals{
            pre: Vec::new(),
            ino: Vec::new(),
            post: Vec::new(),
        }
    }
}


fn all_traversals<T: Clone>(root: &Option<Box<TreeNode<T>>>) -> Traversals<T> {
    let mut result = Traversals::default();
    let mut stack: Vec<(*const TreeNode<T>, u8)> = Vec::new();

    match root {
        Some(node) => stack.push((node.as_ref() as *const TreeNode<T>, 0)),
        None => {},
    }

    while let Some((ptr, cnt)) = stack.pop() {
        let node = unsafe{&*ptr};

        match cnt {
            0 => {
                result.pre.push(node.val.clone());
                stack.push((ptr, 1));

                match &node.left {
                    Some(left) => stack.push((left.as_ref() as *const TreeNode<T>, 0)),
                    None => {},
                }
            }

            1 => {
                result.ino.push(node.val.clone());
                stack.push((ptr, 2));

                match &node.right {
                    Some(right) => stack.push((right.as_ref() as *const TreeNode<T>, 0)),
                    None => {},
                }
            }

            2 => result.post.push(node.val.clone()),

            _ => unreachable!(),

        }
    }

    result
}




// ----------------------- MAIN FUNCTION -----------------------------
fn main() {
    let root = [50,30,70,20,40,60,80,10,13,24,56,78,90].iter().fold(None, |acc, &v| TreeNode::insert(acc, v));

    println!("{root:?}");

    if let Some(r) = &root {
        println!("{}", r.val);
        print_tree(&r.left, "", true);
        print_tree(&r.right, "", false);
    }

    let Traversals{pre, ino, post} = all_traversals(&root);

    println!("PreOrder Traversal: {:?}", pre);
    println!("inoOrder Traversal: {:?}", ino);
    println!("postOrder Traversal: {:?}", post);
}