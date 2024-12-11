#[derive(Debug)]
struct Link {
    val: Option<i32>,
    next: Option<Box<Link>>,
}

impl Link {
    fn new(val: i32) -> Self {
        Self {
            val: Some(val),
            next: None,
        }
    }

    fn new_dummy() -> Self {
        Self {
            val: None,
            next: None,
        }
    }
}

#[derive(Debug)]
struct List {
    head: Option<Box<Link>>,
    curr: Option<*mut Link>,
}

impl List {
    fn new() -> Self {
        let dummy = Box::new(Link::new_dummy());
        let raw_dummy = Box::into_raw(dummy);

        Self {
            head: unsafe { Some(Box::from_raw(raw_dummy)) },
            curr: Some(raw_dummy),
        }
    }

    fn append(&mut self, val: i32) {
        let new_link = Box::new(Link::new(val));
        let raw_new_link = Box::into_raw(new_link);

        if let Some(curr) = self.curr {
            unsafe {
                (*curr).next = Some(Box::from_raw(raw_new_link));
            }
        }
        self.curr = Some(raw_new_link);
    }
    fn print_all(&self) {}
}

fn main() {
    let mut list = List::new();
    list.append(10);
    list.append(20);
    list.append(30);

    println!("{:?}", list.head);
}
