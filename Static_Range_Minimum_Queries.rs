#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n = scan.next::<usize>();
    let mut q = scan.next::<usize>();
    let v = scan.vec::<isize>(&n);
    let st = SparseTable::new(&v);
    while q > 0 {
        let l: usize = scan.next();
        let r: usize = scan.next();
        println!("{}", st.get((l - 1)..r));
        q -= 1;
    }
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    // let t: usize = scan.next();
    (0..t).for_each(|case| solve(&mut scan, case + 1));
}
trait Print {
    fn println(&self);
}
impl<T: std::fmt::Display> Print for T {
    fn println(&self) {
        println!("{}", self);
    }
}
trait Prints {
    fn println(&self);
}
impl<T: std::fmt::Display> Prints for Vec<T> {
    fn println(&self) {
        (0..self.len() - 1).for_each(|u| print!("{} ", self[u]));
        (0.max(self.len() - 1)..self.len()).for_each(|u| println!("{}", self[u]));
    }
}
struct Scanner {
    arr: Vec<String>,
}
impl Scanner {
    fn new() -> Self {
        Self {
            arr: Vec::default(),
        }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T
    where
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        match self.arr.pop() {
            Some(s) => s.parse().unwrap(),
            None => {
                let mut input = String::new();
                std::io::stdin().read_line(&mut input).unwrap();
                self.arr = input
                    .split_whitespace()
                    .rev()
                    .map(|s| s.to_string())
                    .collect();
                self.arr.pop().unwrap().parse().unwrap()
            }
        }
    }
    fn vec<T: std::str::FromStr>(&mut self, n: &usize) -> Vec<T>
    where
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        (0..*n)
            .map(|_| match self.arr.pop() {
                Some(s) => s.parse().unwrap(),
                None => {
                    let mut input = String::default();
                    std::io::stdin().read_line(&mut input).unwrap();
                    self.arr = input
                        .split_whitespace()
                        .rev()
                        .map(|s| s.to_string())
                        .collect();
                    self.arr.pop().unwrap().parse().unwrap()
                }
            })
            .collect()
    }
}
struct SparseTable {
    log: Vec<usize>,
    table: Vec<Vec<isize>>,
}
impl SparseTable {
    fn new(vec: &Vec<isize>) -> Self {
        let n = vec.len();
        let mut log = vec![0; n + 1];
        for i in 2..=n {
            log[i] = log[i / 2] + 1;
        }
        let m = log[n] + 1;
        let mut table = vec![vec![isize::MAX; m]; n];
        for i in 0..n {
            table[i][0] = vec[i];
        }
        for j in 1..m {
            for i in 0..n - (1 << j) + 1 {
                table[i][j] = table[i][j - 1].min(table[i + (1 << (j - 1))][j - 1]);
            }
        }
        Self { log, table }
    }
    fn get(&self, r: std::ops::Range<usize>) -> isize {
        let mut l = r.start;
        let r = r.end;
        let mut mx = isize::MAX;
        while l < r {
            let R = self.log[r - l];
            mx = mx.min(self.table[l][R]);
            l += 1 << R;
        }
        mx
    }
}
