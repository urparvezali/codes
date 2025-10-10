use std::io;

macro_rules! read_integers {
    () => {{
        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .unwrap();
        input
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect::<Vec<isize>>()
    }};
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: isize = input.trim().parse().unwrap();
    let l = read_integers!();
    let mut p: isize = 0;
    let mut c: isize = 0;

    for x in l {
        if x < 0 {
            if p > 0 {
                p -= 1;
            } else {
                c += 1;
            }
        } else {
            p += x;
        }
    }

    println!("{}", c);
}
