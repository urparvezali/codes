use std::collections::VecDeque;

fn bfs(s: usize, g: &Vec<Vec<usize>>) {
    let n = g.len();
    let mut vs = vec![false; n];
    let mut q = VecDeque::new();

    q.push_back(s);
    vs[s] = true;
    while !q.is_empty() {
        let parent = q.pop_front().unwrap();
        for &node in g[parent].iter() {
            if !vs[node] {
                q.push_back(node);
                vs[node] = true;
                print!("{} ", node);
            }
        }
    }
}
fn main() {
    let g = vec![vec![1, 2], vec![2], vec![3, 4], vec![4], vec![]];
    bfs(0, &g);
}
