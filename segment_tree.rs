struct SegmentTree {
    n: usize,
    sz: usize,
    tree: Vec<isize>,
}
impl SegmentTree {
    fn new(n: &usize) -> Self {
        let sz = n * 2 - 1;
        let tree = vec![isize::default(); sz];
        Self { n, sz, tree }
    }
    fn show(&self) {
        println!("{:?}", self.tree);
    }
    fn set(&self, i: usize, v: isize) {
        fn _set(i: usize, v: isize) {}
    }
}

fn main() {
    let vec = vec![1_isize, 3, 6, 7];
    let st = SegmentTree::new(&vec.len());
    for i in 0..vec.len() {
        st.set(i, vec[i]);
    }
    st.show();
}
