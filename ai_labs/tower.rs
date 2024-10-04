use std::io::{stdin, stdout, BufRead, Write};
fn main() {
    print!("Enter number of disks: ");
    stdout().flush().unwrap();
    let n = stdin()
        .lock()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .parse::<isize>()
        .unwrap();
    let mut count = 0;
    recursion(n, &'A', &'B', &'C', &mut count);
    println!("The number of total moves needed: {}", count);
    stdout().flush().unwrap();
}
fn recursion(n: isize, source: &char, helper: &char, dest: &char, count: &mut usize) {
    if n == 0 {
        return;
    }
    recursion(n - 1, source, dest, helper, count);
    // println!("Disk {} moved from {} to {}", n, source, dest);
    *count += 1;
    recursion(n - 1, helper, source, dest, count);
}
