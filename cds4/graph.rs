// #[allow(unused)]
use std::{io::stdin, ops::Rem};

struct Graph {
    n: usize,
    graph: Vec<Vec<usize>>,
    vs: Vec<bool>,
}

impl Graph {
    fn new(num: usize) -> Self {
        Graph {
            n: num,
            graph: vec![vec![]; num + 1],
            vs: vec![false; num + 1],
        }
    }

    fn dfs(&mut self, u: usize) {
        fn dfs_in(u: usize, graph: &Vec<Vec<usize>>, vs: &mut Vec<bool>) {
            if vs[u] == true {
                return;
            }
            vs[u] = true;
            print!("{u} ");
            for &chld in &graph[u] {
                dfs_in(chld, graph, vs);
            }
        }
        dfs_in(u, &self.graph, &mut self.vs);
    }
}

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<usize>().unwrap();
    let mut graph = Graph::new(n);
    for _ in 0..n {
        input.clear();
        stdin().read_line(&mut input).unwrap();
        let mut it = input.trim().split_whitespace();
        let (x, y) = (
            it.next().unwrap().parse::<usize>().unwrap(),
            it.next().unwrap().parse::<usize>().unwrap(),
        );
        graph.graph[x].push(y);
        graph.graph[y].push(x);
    }
    graph.dfs(0);
    println!("\n{}", gcd(10, 5));
}