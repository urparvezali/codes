use std::io;

const MOD: i64 = 1_000_000_007;

fn rec(x: i64, dp: &mut Vec<i64>) -> i64 {
    if x < 7 {
        return i64::pow(2, x as u32 - 1) % MOD;
    }

    let mut z = 0;
    for i in 1..7 {
        if dp[(x - i) as usize] != -1 {
            z = (z + dp[(x - i) as usize]) % MOD;
        } else {
            dp[(x - i) as usize] = rec(x - i, dp);
            z = (z + dp[(x - i) as usize]) % MOD;
        }
    }
    z
}

fn solution() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i64 = input.trim().parse().unwrap();

    let mut dp = vec![-1; 1_000_000];
    println!("{}", rec(n, &mut dp));
}

fn main() {
    let tt: i64 = 1;
    for _ in 0..tt {
        solution();
    }
}
