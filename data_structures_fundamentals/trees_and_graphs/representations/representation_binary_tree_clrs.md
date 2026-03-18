## Binary Tree Representation in CLRS format

Array A[1...n] (1-indexed array), root at index-1, node at index i

```
left_child = 2i
right_child = 2i+1
```

*Note*: 

- Binary Trees are different from Binary Search Trees. 

- A Binary tree is just a structural concept where each node has atmost 2 children and there is no ordering rule whatsoever. Insertion simply fills the next available spot *level-order* (left to right) to maintain the complete tree shape. No Comparisons are needed.

- A Binary Search Tree is a Binary Tree + Ordering Invariant
```
For every node i,
    All Nodes in left subtree < A[i]
    All Node in Right Subtree > A[i]
```

BST array representation in uncommon and are always implemented with nodes and pointers because BST insertions can make the tree unbalanced and skewed which wastes enormous space in an array ($O(2^n)$ in the worst case).

Pseudo-Code for building the Binary Tree

```
BINARY-TREE-ARRAY
    Data: A[1..capacity]    // underlying array, 1-indexed
    size: integer

INIT-BINARY-TREE(capacity)
    A = new array[1..capacity] filled with NIL
    size=0
    return (A, size)

INSERT-BINARY-TREE(A, size, value)
    // inserts level order : left to right complete tree shaped
    size = size+1
    A[size] = value
    return size

DELETE-BINARY-TREE-NODE(A, size, i)
    // swap the ith node with the last node, then shrink size
    A[i] = A[size]
    A[size] = NIL
    size = size - 1
    return size

SEARCH-BINARY-TREE(A, size, value)
    // Linear scan - no ordering assumed (not a BST)
    for i = 1 to size
        if A[i] == value
            return i
    return NIL

INORDER-TRAVERSAL(A, size, i)
    // left -> node -> right
    if i > size or A[i] == NIL
        return
    INORDER-TRAVERSAL(A, size, 2i)
    visit A[i]
    INORDER-TRAVERSAL(A, size, 2i+1)

PREORDER-TRAVERSAL(A, size, i)
    // node -> left -> right
    if i > size or A[i] == NIL
        return
    visit A[i]
    PREORDER-TRAVERSAL(A, size, 2i)
    PREORDER-TRAVERSAL(A, size, 2i+1)

POSTORDER-TRAVERSAL(A, size, i)
    // left -> right -> node
    if i > size or A[i] == NIL
        return
    POSTORDER-TRAVERSAL(A, size, 2i)
    POSTORDER-TRAVERSAL(A, size, 2i+1)
    visit A[i]
```