use std::io::{stdin, BufRead};

fn main() {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line.clear();

    stdin().read_line(&mut line).unwrap();

    let vec: Vec<isize> = line
        .split_whitespace()
        .map(|f| f.parse().unwrap())
        .collect();

    let st = SegmentTree::new(&vec);
    st.print();
}

struct SegmentTree {
    n: usize,
    tree: Vec<isize>,
}

impl SegmentTree {
    fn new(vec: &Vec<isize>) -> Self {
        let n = vec.len();
        let mut tree = vec![0; 2 * n];
        tree[0..n].copy_from_slice(vec);
        for i in (0..n).rev() {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
        SegmentTree { n, tree }
    }

    fn print(&self) {
        println!("{:?}", self.tree);
        println!("Length: {:?}", self.tree.len());
    }
}
