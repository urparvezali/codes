use std::collections::VecDeque;

fn bfs(s: usize, g: &Vec<Vec<usize>>) {
    let n = g.len();
    let mut vs = vec![false; n];
    let mut q = VecDeque::new();
    let mut lvl = vec![0; n];

    q.push_back(s);
    vs[s] = true;
    lvl[0] = 1;
    print!("{} ", s);
    while !q.is_empty() {
        let parent = q.pop_front().unwrap();
        for &node in g[parent].iter() {
            if !vs[node] {
                q.push_back(node);
                vs[node] = true;
                print!("{} ", node);
                lvl[node] = lvl[parent] + 1;
            }
        }
    }
    println!("\n{:?}", lvl);
}
fn main() {
    let g = vec![
        vec![1, 2],
        vec![3, 4],
        vec![5, 6],
        vec![],
        vec![],
        vec![],
        vec![],
    ];
    bfs(0, &g);
}
