use std::io::stdin;

fn solution() {
    let mut input: String = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse::<usize>().unwrap();
    input.clear();
    stdin().read_line(&mut input).unwrap();
    let v: Vec<isize> = input
        .trim()
        .split_whitespace()
        .map(|f: &str| f.parse().unwrap())
        .collect::<Vec<isize>>();

    let mut f: Vec<isize> = vec![0; n];
    f[1] = 1;
    for i in 1..n - 1 {
        if v[i] - v[i - 1] < v[i + 1] - v[i] {
            f[i + 1] = v[i + 1] - v[i];
        } else {
            f[i + 1] = 1;
        }
        f[i] += f[i - 1];
    }
    f[n - 1] += f[n - 2];

    let mut r: Vec<isize> = vec![0; n];
    r[n - 2] = 1;
    for i in (1..n - 1).rev() {
        if v[i] - v[i - 1] > v[i + 1] - v[i] {
            r[i - 1] = v[i] - v[i - 1];
        } else {
            r[i - 1] = 1;
        }
        r[i] += r[i + 1];
    }
    r[0] += r[1];

    input.clear();
    stdin().read_line(&mut input).unwrap();
    let mut q: isize = input.trim().parse::<isize>().unwrap();
    // println!("{:?}", f);
    // println!("{:?}", r);
    while q > 0 {
        input.clear();
        stdin().read_line(&mut input).unwrap();
        let mut itr = input.trim().split_whitespace();
        let x: usize = itr.next().unwrap().parse::<usize>().unwrap() - 1;
        let y: usize = itr.next().unwrap().parse::<usize>().unwrap() - 1;
        if x == y {
            println!("0");
        } else if y > x {
            println!("{}", f[y] - f[x]);
        } else {
            println!("{}", r[y] - r[x]);
        }
        q -= 1;
    }
}
fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let t = input.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        solution();
    }
}
