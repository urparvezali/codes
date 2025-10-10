
use std::collections::BTreeSet;

fn dijkstra(s: usize, g: &Vec<Vec<(usize, usize)>>) -> Vec<usize> {
    let mut dist = vec![usize::MAX; g.len()];
    let mut pq: BTreeSet<(usize, usize)> = BTreeSet::new();
    dist[s] = 0;
    pq.insert((0, s));

    while !pq.is_empty() {
        let (parent_dist, parent) = *pq.first().unwrap();
        pq.remove(&(parent_dist, parent));

        for &(node, wt) in g[parent].iter() {
            if dist[node] > parent_dist + wt {
                dist[node] = parent_dist + wt;
                pq.insert((dist[node], node));
            }
        }
    }
    dist
}