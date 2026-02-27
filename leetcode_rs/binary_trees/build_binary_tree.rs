/**
 * Key concepts: 
 * 1. Box<T> : to heap-allocate nodes enabling recursive types.
 * 2. Option<T> : To represent missing children, equivalent to NULL in other languages
 * 3. Implement Ord trait for T to enable comparisons during insertion (eg. a binary tree)
 * 4. use `impl<T: Ord>` to constrain generic types to those that can be ordered
*/

#[derive(Debug)]
struct Node<T>{
    data: T,
    left: Option<Box<Node<T>>>,
    right: Option<Box<Node<T>>>,
}

// Creating a constructor to initialize a new node
impl<T> Node<T> {
    fn new(data: T) -> Self {
        Node{
            data,
            left: None,
            right: None,
        }
    }
}

impl<T: Ord> Node<T> {
    pub fn insert(&mut self, data: T) {
        if data < self.data {
            match &mut self.left {
                Some(node) => node.insert(data),
                None => self.left = Some(Box::new(Node::new(data))),
            }
        } else {
            match &mut self.right {
                Some(node) => node.insert(data),
                None => self.right = Some(Box::new(Node::new(data))),
            }
        }
    }
}


fn main() {
    let mut root: Node<i32> = Node::new(23);
    root.insert(20);
    root.insert(30);
    root.insert(13);
    root.insert(25);
    root.insert(21);

    println!("{:?} ", root);
}