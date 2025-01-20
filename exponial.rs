#![allow(unused)]
use std::ops::{
    Add, AddAssign, BitAnd, BitAndAssign, BitOr, BitXor, Div, DivAssign, Mul, MulAssign, Rem,
    RemAssign, Sub, SubAssign,
};

fn solve(sc: &mut Scanner, case: usize) {
    let mut n: u32 = sc.next();
    let m: u32 = sc.next();

    let mut res = n;
    for i in n - 1..1 {
        res = res.mod_pow(i, m);
    }
    res.println();
}

/// A generic `ModPow` trait for types that support modular exponentiation
pub trait ModPow {
    fn mod_pow(self, exp: Self, modulus: Self) -> Self;
}
impl<T> ModPow for T
where
    T: Copy
        + PartialEq
        + PartialOrd
        + From<u8>
        + Rem<Output = T>
        + Add<Output = T>
        + Mul<Output = T>
        + Div<Output = T>
        + Sub<Output = T>,
{
    fn mod_pow(mut self, mut exp: T, modulus: T) -> T {
        if modulus == T::from(1) {
            return T::from(0); // Anything mod 1 is 0
        }

        let mut result = T::from(1);
        self = self % modulus;

        while exp > T::from(0) {
            if exp % T::from(2) == T::from(1) {
                result = (result * self) % modulus;
            }
            exp = exp / T::from(2);
            self = (self * self) % modulus;
        }
        result
    }
}

fn main() {
    let mut sc = Scanner::new();
    let t: usize = 1;
    // let t: usize = sc.next();
    (1..=t).for_each(|case| solve(&mut sc, case));
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
