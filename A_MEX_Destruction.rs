#![allow(unused)]

use std::collections::HashSet;

fn solve(scan: &mut Scanner, case: usize) {
	let n: usize = scan.next();
	let mut v = scan.vec::<usize>(n);
	let mut cnt = 0;
	let mut length = 0;
	for &ele in &v {
		if ele!=0 {
			length+=1;
		} else {
			if length>0 {
				cnt+=1;
			}
			length=0;
		}
	}
	if length>0 {
		cnt+=1;
	}
	// print!("{} ", cnt);
	if cnt==0 {
		println!("0");
	} else if cnt==1 {
		println!("1");
	} else {
		println!("2");
	}
}

fn main() {
	let mut scan = Scanner::new();
	let t: usize = 1;
	let t: usize = scan.next();
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