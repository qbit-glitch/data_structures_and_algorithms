/**
 * Topic: Build a Simple Stack in Rust
*/

struct Stack<T> {
    elements: Vec<T>,
}

impl<T> Stack<T>{
    fn new() -> Self {
        Stack{
            elements: Vec::new(),
        }
    }

    fn push(&mut self, item: T){
        self.elements.push(item)
    }

    fn pop(&mut self) -> Option<T>{
        self.elements.pop()
    }

    fn peek(&self) -> Option<&T> {
        self.elements.last()
    }

    fn is_empty(&self) -> bool {
        self.elements.is_empty()
    }

    fn len(&self) -> usize {
        self.elements.len()
    }
}


fn main() {
    let mut stack: Stack<i32> = Stack::new();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    let mut i = 7;
    while i >= 0 {
        match  &stack.peek() {
            Some(val) => println!("Top element: {}", val),
            None => println!("Nothing at top!"),
        }

        match &stack.pop() {
            Some(val) => println!("Popped element: {}", val),
            None => println!("Stack Empty!")
        }

        println!("Length of the stack: {}", stack.len());
        println!("Is the stack empty ? {}", stack.is_empty());

        i = i-1;
    }
}