#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;

template<class T>

istream& operator>>(istream& in, vector<T>& v) {
	for (T& x : v) in >> x;
	return in;
}
template<class T>
ostream& operator<<(ostream& out, vector<T>& v) {
	for (ll i = 0;i < v.size() - 1;i++)
		out << v[i] << ' ';
	out << v[v.size() - 1];
	return out;
}

vll bfs(ll s, vvll& graph, vll& ppd) {
	ll n = graph.size();
	vbl vs(n, false);
	vll lvl(n, 0LL);
	vll roses(32, 0LL);

	queue<ll> q;
	q.push(s);
	vs[s] = 1;
	roses[lvl[s]] = ppd[s];
	while (!q.empty()) {
		ll parent = q.front(); q.pop();

		for (auto node : graph[parent]) {
			if (!vs[node]) {
				q.push(node); vs[node] = 1;

				lvl[node] = lvl[parent] + 1LL;
				roses[lvl[node]] += ppd[node];
			}
		}
	}
	return roses;
}

void solution(ll& T) {
	ll n; cin >> n;
	vll ppd(n); cin >> ppd;
	vvll graph(n);
	for (ll i = 0; i < n - 1; i++) {
		ll x, y; cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}
	vvll roses;
	for (ll i = 0; i < n; i++) {
		auto x = bfs(i, graph, ppd);
		roses.push_back(x);
	}

	ll q; cin >> q;
	while (q--) {
		ll u, t; cin >> u >> t; u--;
		ll sum = 0, i = 0;
		while (t--) {
			sum += (t + 1) * roses[u][i++];
		}
		cout << sum << endl;
	}
}

signed main() {
	ll TT = 1;
	// cin>>TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}