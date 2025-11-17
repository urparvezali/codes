#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize, phi: &Vec<usize>) {
	let n: usize = scan.next();
	phi[n].println();
}

fn main() {
	let mut phi = vec![0; 1000001];
	for i in 0..=1000000{phi[i]=i;}
	for i in 2..=1000000{
		if phi[i]==i {
			for j in (2*i..=1000000).step_by(i){
				phi[j]-=phi[j]/i;
			}
			phi[i]-=1;
		}
	}
	// println!("{:?}", phi[..15].to_vec());
	let mut scan = Scanner::new();
	let t: usize = 1;
	let t: usize = scan.next();
	(1..=t).for_each(|case| solve(&mut scan, case,&phi));
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