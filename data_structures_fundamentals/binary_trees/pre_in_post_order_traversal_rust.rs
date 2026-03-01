/**
 * Topic: PreOrder, InOrder, PostOrder Traversal in Binary Trees in rust programming language
*/

#[derive(Debug)]
struct TreeNode<T>{
    data: T,
    left: Option<Box<TreeNode<T>>>,
    right: Option<Box<TreeNode<T>>>,
}

#[derive(Debug)]
struct Pair<T> {
    node: Box<TreeNode<T>>,
    cnt: i32,
}


impl<T> TreeNode<T> {
    fn new(d: T) -> Self{
        TreeNode{
            data: d,
            left: None,
            right: None,
        }
    }
}



impl<T: Ord> TreeNode<T> {
    pub fn insert(&mut self, x: T) {
        if  x < self.data {
            match &mut self.left {
                Some(node) => node.insert(x),
                None => self.left = Some(Box::new(TreeNode::new(x))),
            }
        } else {
            match &mut self.right {
                Some(node) => node.insert(x),
                None => self.right = Some(Box::new(TreeNode::new(x))),
            }
        }
    }
}




impl<T: Clone + std::fmt::Debug> TreeNode<T> {
    pub fn pre_in_post_traversal(root: Option<Box<TreeNode<T>>>) -> (Vec<T>, Vec<T>, Vec<T>){
    
        let mut st: Vec<Pair<T>> = Vec::new();
        
        let mut pre_order: Vec<T> = Vec::new();
        let mut in_order: Vec<T> = Vec::new();
        let mut post_order: Vec<T> = Vec::new();
        
        if let Some(node) = root {
            st.push(Pair{
                node,
                cnt: 1,
            });
        }

        while let Some(mut pair) = st.pop() {
            
            match pair.cnt {
                1 => {
                    // Pre-Order Traversal
                    pre_order.push(pair.node.data.clone());
                    pair.cnt += 1;
                    
                    let left = pair.node.left.take();

                    st.push(pair);
                    if let Some(left_node) = left {
                        st.push(Pair{
                            node: left_node,
                            cnt: 1,
                        })
                    }
                }

                2 => {
                    // In-Order traversal
                    in_order.push(pair.node.data.clone());
                    pair.cnt += 1;

                    let right = pair.node.right.take();

                    st.push(pair);

                    if let Some(right_node) = right {
                        st.push(Pair{
                            node: right_node,
                            cnt: 1,
                        })
                    }
                }
                
                _ => {
                    // Post-Order Traversal
                    post_order.push(pair.node.data.clone());
                }
            }
        }

        println!("{:?}",st);
        return (pre_order, in_order, post_order);
    }
}


fn main(){
    let mut node: TreeNode<i32> = TreeNode::new(34);
    node.insert(25);
    node.insert(45);
    node.insert(20);
    node.insert(30);
    node.insert(40);
    node.insert(53);
    node.insert(60);

    let (pre_order, in_order, post_order) = TreeNode::pre_in_post_traversal(Some(Box::new(node)));
    println!("{:?} \n{:?} \n{:?}", pre_order, in_order, post_order); 
}