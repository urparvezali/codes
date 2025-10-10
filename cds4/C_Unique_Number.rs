// #![allow(dead_code)]
// #![allow(unused)]
// #![allow(unused_imports)]
// #![allow(unused_import_braces)]

use std::io::stdin;

fn main() {
    let mut input = "".to_string();
    stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
    for _ in 0..t {
        solution();
    }
}
fn solution() {
    let mut input = "".to_string();
    stdin().read_line(&mut input).unwrap();
    let mut x: usize = input.trim().parse().unwrap();
    if x > 45 {
        println!("-1");
        return;
    } else if x < 10 {
        println!("{x}");
        return;
    }
    let mut now = 9;
    let mut v = Vec::new();
    while x > now {
        v.push(now);
        x -= now;
        now -= 1;
    }
    v.push(x);
    v.sort();
    for i in v {
        print!("{i}");
    }
    println!();
}
