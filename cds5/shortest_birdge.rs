use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn shortest_bridge(grid: Vec<Vec<i32>>) -> i32 {
        let mut graph: Vec<Vec<usize>> = vec![vec![0; grid[0].len()]; grid.len()];
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                graph[i][j] = grid[i][j] as usize;
            }
        }
        fn distance(graph: &[Vec<usize>]) -> usize {
            let n = graph.len();
            let m = graph[0].len();
            let mut vs: HashMap<(usize, usize), bool> = HashMap::new();
            fn find_sources(graph: &[Vec<usize>]) -> Vec<(usize, usize)> {
                let n = graph.len();
                let m = graph[0].len();
                let mut vs: HashMap<(usize, usize), bool> = HashMap::new();
                fn find_first_source(graph: &[Vec<usize>]) -> (usize, usize) {
                    let found = (0, 0);
                    for (i, v) in graph.iter().enumerate() {
                        for (j, item) in v.iter().enumerate() {
                            if *item == 1 {
                                return (i, j);
                            }
                        }
                    }
                    (0, 0)
                }

                let found = find_first_source(graph);
                let mut sources: Vec<(usize, usize)> = Vec::new();
                // println!("{:?}",found);
                let mut q: VecDeque<(usize, usize)> = VecDeque::new();

                q.push_back(found);
                sources.push(found);
                vs.insert(found, true);

                while !q.is_empty() {
                    let (i, j) = q.pop_front().unwrap();

                    if i != 0 && !*vs.entry((i - 1, j)).or_insert(false) && graph[i - 1][j] == 1 {
                        q.push_back((i - 1, j));
                        vs.insert((i - 1, j), true);
                        sources.push((i - 1, j));
                    }
                    if j != 0 && !*vs.entry((i, j - 1)).or_insert(false) && graph[i][j - 1] == 1 {
                        q.push_back((i, j - 1));
                        vs.insert((i, j - 1), true);
                        sources.push((i, j - 1));
                    }
                    if i != n - 1 && !*vs.entry((i + 1, j)).or_insert(false) && graph[i + 1][j] == 1
                    {
                        q.push_back((i + 1, j));
                        vs.insert((i + 1, j), true);
                        sources.push((i + 1, j));
                    }
                    if j != m - 1 && !*vs.entry((i, j + 1)).or_insert(false) && graph[i][j + 1] == 1
                    {
                        q.push_back((i, j + 1));
                        vs.insert((i, j + 1), true);
                        sources.push((i, j + 1));
                    }
                }
                // println!("{:?}", sources);
                sources
            }
            let mut sources: Vec<(usize, usize)> = find_sources(graph);

            let mut q: VecDeque<(usize, usize)> = VecDeque::new();

            let mut level: HashMap<(usize, usize), usize> = HashMap::new();

            for &pair in &sources {
                q.push_back(pair);
                vs.insert((pair), true);
                level.insert(pair, 0);
            }

            while !q.is_empty() {
                let parent = q.pop_front().unwrap();
                let (i, j) = parent;

                if i != 0 && !*vs.entry((i - 1, j)).or_insert(false) {
                    if graph[i - 1][j] == 0 {
                        q.push_back((i - 1, j));
                        vs.insert((i - 1, j), true);
                        level.insert((i - 1, j), level.get(&parent).unwrap() + 1);
                    } else {
                        return *level.get(&parent).unwrap();
                    }
                }
                if j != 0 && !*vs.entry((i, j - 1)).or_insert(false) {
                    if graph[i][j - 1] == 0 {
                        q.push_back((i, j - 1));
                        vs.insert((i, j - 1), true);
                        level.insert((i, j - 1), level.get(&parent).unwrap() + 1);
                    } else {
                        return *level.get(&parent).unwrap();
                    }
                }
                if i != n - 1 && !*vs.entry((i + 1, j)).or_insert(false) {
                    if graph[i + 1][j] == 0 {
                        q.push_back((i + 1, j));
                        vs.insert((i + 1, j), true);
                        level.insert((i + 1, j), level.get(&parent).unwrap() + 1);
                    } else {
                        return *level.get(&parent).unwrap();
                    }
                }
                if j != m - 1 && !*vs.entry((i, j + 1)).or_insert(false) {
                    if graph[i][j + 1] == 0 {
                        q.push_back((i, j + 1));
                        vs.insert((i, j + 1), true);
                        level.insert((i, j + 1), level.get(&parent).unwrap() + 1);
                    } else {
                        return *level.get(&parent).unwrap();
                    }
                }
                // println!("{:?}", q);
            }
            0
        }
        distance(&graph) as i32
    }
}
