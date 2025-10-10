#![allow(unused)]

use std::{collections::HashSet, ops::Range};

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let k: usize = scan.next();
    let mut v: Vec<i32> = scan.vec(n);

    v.sort();
    // v.println();

    let mut mx = 0;
    let mut cnt = 0;
    let mut prev = None;

    let mut l = 0;
    let mut st: HashSet<i32> = HashSet::new();
    // v.println();

    for i in 0..n {
		// print!("{} ", st.len());
        if prev == None {
            prev = Some(v[i]);
            cnt += 1;
            mx = mx.max(cnt);
			st.insert(v[i]);
            continue;
        }
        if v[i] == prev.unwrap() || v[i] == prev.unwrap() + 1 {
            if st.len() < k || (st.len() == k && st.contains(&v[i])) {
                st.insert(v[i]);
                cnt += 1;
                mx = mx.max(cnt);
                prev = Some(v[i]);
            } else {
                let x = v[l];
                while v[l] == x {
                    l += 1;
                    cnt -= 1;
                }
                st.remove(&x);
                cnt += 1;
                mx = mx.max(cnt);
                st.insert(v[i]);
                prev = Some(v[i]);
            }
        } else {
            st.clear();
            st.insert(v[i]);
            cnt = 1;
            mx = mx.max(cnt);
            prev = Some(v[i]);
            l = i;
        }
    }
	// println!();
    mx.println();
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    let t: usize = scan.next();
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
