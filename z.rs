#[derive(Debug)]
struct Link {
    data: isize,
    next: Option<Box<Link>>,
}

#[derive(Debug)]
struct LinkedList {
    head: Option<Box<Link>>,
}
impl LinkedList {
    fn new() -> Self {
        LinkedList { head: None }
    }
    // fn append(&mut self, d: isize) {
    //     let new_link = Box::new(Link {
    //         data: d,
    //         next: None,
    //     });

    //     if let Some(curr) = self.head {
			
	// 	} else {
	// 		self.head=Some(new_link);
	// 	}
    // }
}

fn main() {
	let ll = LinkedList::new();
    println!("{:?}", ll);
}
