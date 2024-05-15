impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn minimum_total(&self, triangle: Vec<Vec<i32>>) -> i32 {
        fn rec(
            i: usize,
            j: usize,
            triangle: &Vec<Vec<i32>>,
            map: &mut HashMap<(usize, usize), i32>,
        ) -> i32 {
            if i == triangle.len() {
                return 0;
            }
            if j > i + 1 {
                return i32::MAX / 2_i32;
            }
            if let Some(&res) = map.get(&(i, j)) {
                return res;
            }
            let res =
                triangle[i][j] + rec(i + 1, j, triangle, map).min(rec(i + 1, j + 1, triangle, map));
            map.insert((i, j), res);
            res
        }
        let mut map: HashMap<(usize, usize), i32> = HashMap::new();
        rec(0, 0, &triangle, &mut map)
    }
}