#[derive(Debug)]
struct Node {
    data: isize,
    next: Option<Box<Node>>,
}
#[derive(Debug)]
struct List {
    head: Option<Box<Node>>,
}
impl List {
    fn new() -> Self {
        List { head: None }
    }
    fn push(&mut self, d: isize) {
        let newnode = Node {
            data: d,
            next: None,
        };
        let curr = self.head;
    }
}

fn main() {
    let something = List::new();
    println!("{:?}", something);
}
