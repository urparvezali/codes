#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let m: usize = scan.next();
    let mut v: Vec<usize> = Vec::with_capacity(n);
    let mut pos = vec![0; n + 1];
    let mut a = 0;
    let mut b = 0;
    let mut tmp = 0;
    for i in 0..n {
        tmp = scan.next();
        v.push(tmp);
        pos[tmp] = i;
    }
    let mut ans = 1;
    for i in 1..=n {
        ans += (pos[i] < pos[i - 1]) as isize;
    }
    for i in 0..m {
        (a, b) = (scan.next(), scan.next());
        (a, b) = (a - 1, b - 1);
        if v[a].min(v[b]) + 1 >= v[b].max(v[a]) - 1 {
            for r in v[a].min(v[b]).max(1)..=(v[b].max(v[a]) + 1).min(n) {
                ans -= (pos[r] < pos[r - 1]) as isize;
            }
        } else {
            for r in v[a].max(1)..=(v[a] + 1).min(n) {
                ans -= (pos[r] < pos[r - 1]) as isize;
            }
            for r in v[b].max(1)..=(v[b] + 1).min(n) {
                ans -= (pos[r] < pos[r - 1]) as isize;
            }
        }
        (pos[v[a]], pos[v[b]]) = (pos[v[b]], pos[v[a]]);
        (v[a], v[b]) = (v[b], v[a]);
        if v[a].min(v[b]) + 1 >= v[b].max(v[a]) - 1 {
            for r in v[a].min(v[b]).max(1)..=(v[b].max(v[a]) + 1).min(n) {
                ans += (pos[r] < pos[r - 1]) as isize;
            }
        } else {
            for r in v[a].max(1)..=(v[a] + 1).min(n) {
                ans += (pos[r] < pos[r - 1]) as isize;
            }
            for r in v[b].max(1)..=(v[b] + 1).min(n) {
                ans += (pos[r] < pos[r - 1]) as isize;
            }
        }
        ans.println();
    }
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    // let t: usize = scan.next();
    (1..=t).for_each(|case| solve(&mut scan, case));
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
        if let Some((last, elements)) = self.split_last() {
            for element in elements {
                print!("{} ", element);
            }
            println!("{}", last);
        }
    }
}
struct Scanner {
    arr: Vec<String>,
}
impl Scanner {
    fn new() -> Self {
        Self { arr: Vec::new() }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T
    where
        T::Err: std::fmt::Debug,
    {
        if self.arr.is_empty() {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            self.arr = input.split_whitespace().rev().map(String::from).collect();
        }
        self.arr.pop().unwrap().parse().unwrap()
    }

    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T>
    where
        T::Err: std::fmt::Debug,
    {
        (0..n).map(|_| self.next()).collect()
    }
}
