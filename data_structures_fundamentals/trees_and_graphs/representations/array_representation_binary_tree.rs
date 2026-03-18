/// Array representation of Binary Tree
/// Note: In binary Tree, there is no ordering whatsoever
/// Implementation contains:
///     - Binary Tree Data Structure initialization
///     - insertion
///     - deletion
///     - preorder traversal
///     - inorder traversal
///     - postorder traversal
///     - search an element in BT


struct Binary_Tree<T> {
    data: Vec<i32>,
    size: i32,
}

impl<T> Binary_Tree<T> {
    fn new(capacity: i32) -> Self {
        Binary_Tree {
            data: Vec::with_capacity(capacity),
            size: 0,
        }
    }

    fn insert(&mut self, value: i32) -> i32 {
        self.size += 1;
        self.data[size] = value;
        return self.size;
    }

    fn deletion(&mut self, idx: i32) -> i32 {
        self.data[idx] = self.data[size];
        self.data[size] = 
    }
}