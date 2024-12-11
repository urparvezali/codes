use std::collections::HashSet;
struct Solution;
impl Solution {
    fn new() -> Self {
        Self
    }
    pub fn find_order(&self, num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let n = num_courses as usize;
        let mut graph: Vec<Vec<usize>> = vec![vec![]; num_courses as usize];
        for vec in &prerequisites {
            graph[vec[0] as usize].push(vec[1] as usize);
        }
        fn dfs(
            src: usize,
            vs: &mut Vec<bool>,
            graph: &Vec<Vec<usize>>,
            order: &mut Vec<usize>,
            trace: &mut HashSet<usize>,
        ) -> bool {
            if vs[src] {
                if trace.contains(&src) {
                    return true;
                }
                return false;
            }
            vs[src] = true;
            trace.insert(src);
            let mut res = false;
            for &node in &graph[src] {
                res |= dfs(node, vs, graph, order, trace);
            }
            order.push(src);
            trace.remove(&src);
            res
        }
        let (mut order, mut vs) = (Vec::new(), vec![false; n]);
        let mut looping = false;
        let mut trace = HashSet::new();
        for node in 0..n {
            if !vs[node] {
                looping |= dfs(node, &mut vs, &graph, &mut order, &mut trace);
            }
        }
        if !looping {
            order.into_iter().map(|val| val as i32).collect()
        } else {
            vec![]
        }
    }
}

fn main() {
    let st = Solution::new();
    println!(
        "{:?}",
        st.find_order(4, vec![vec![1, 0], vec![2, 0], vec![3, 1], vec![3, 2]])
    );
    println!("{:?}", st.find_order(2, vec![vec![0, 1], vec![1, 0]]));
}
