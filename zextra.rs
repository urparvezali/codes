
fn main() {
    let mut n = 0b11111111;
    println!("{:b}", n);
    let mut ans = 0;
    while n > 0 {
        n = n & (n - 1);
        ans += 1;
    }
    println!("{}", ans);

}
