struct SparseTable {
    log: Vec<usize>,
    table: Vec<Vec<isize>>,
}
impl SparseTable {
    fn new(vec: &[isize]) -> Self {
        let n = vec.len();
        let mut log = vec![0; n + 1];
        for i in 2..=n {
            log[i] = log[i / 2] + 1;
        }
        let m = log[n] + 1;
        let mut table = vec![vec![isize::MIN; m]; n];
        for i in 0..n {
            table[i][0] = vec[i];
        }
        for j in 1..m {
            for i in 0..n - (1 << j) + 1 {
                table[i][j] = table[i][j - 1].max(table[i + (1 << (j - 1))][j - 1]);
            }
        }
        Self { log, table }
    }
    fn get(&self, r: std::ops::Range<usize>) -> isize {
        let mut l = r.start;
        let r = r.end;
        let mut mx = isize::MIN;
        while l < r {
            let R = self.log[r - l];
            mx = mx.max(self.table[l][R]);
            l += 1 << R;
        }
        mx
    }
}
fn main() {
    let vec: Vec<isize> = (1..=1_000_000).collect();
    let sp = SparseTable::new(&vec);
    println!("{}", sp.get(0..vec.len()) == *vec.iter().max().unwrap());
}
