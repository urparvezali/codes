#[derive(Debug, Clone)]
struct Link {
    val: i32,
    next: Option<Box<Link>>,
}
impl Link {
    fn new(val: i32) -> Self {
        Self { val, next: None }
    }
}

struct List {
	head: Option<Box<Link>>,
	
}


fn main() {
    let ll = Link::new(5);
    println!("{:?}", ll);
}
