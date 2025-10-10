/// .
fn main() {
    let weights = vec![2, 3, 4, 5];
    let prices = vec![1, 2, 5, 6];
    let w = 8;
    let mut table = vec![vec![0; w + 1]; weights.len() + 1];

    for i in 1..=weights.len() {
        for j in 1..=w {
            if j >= weights[i - 1] as usize {
                table[i][j] =
                    table[i - 1][j].max(prices[i - 1] + table[i - 1][j - weights[i - 1] as usize]);
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    println!("{:?}", table);
    println!("{}", table.last().unwrap().last().unwrap())
}
