fn bin_exp(x: i64, p: i64) -> i64 {
    match p {
        0 => 1,
        1 => x,
        _ if p & 1 == 1 => x * bin_exp(x, p - 1),
        _ => {
            let x = bin_exp(x, p / 2);
            x * x
        }
    }
}

fn bin_exp_itr(x: i64, p: i64) -> i64 {
    let mut x = x;
    let mut p = p;
    let mut res = 1_i64;

    while p > 0 {
        if p & 1 == 1 {
            res *= x;
        }
        x *=x;
        p >>= 1;
    }
    res
}
fn main() {
    println!("{}", bin_exp_itr(2, 32));
}
