#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 1000000007;

inline void Parvez() { ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) { in >> x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v) { for (ll i = 0;i < v.size() - 1;i++) { out << v[i] << ' '; }out << v[v.size() - 1];return out; }
inline void inp() {}template<class H, class... T>inline void inp(H&& h, T &&...t) { cin >> h;inp(forward<T>(t)...); }inline void print() { cout << endl; }template<class H, class... T>inline void print(H&& h, T &&...t) { cout << h;if (sizeof...(t) != 0)cout << ' ';print(forward<T>(t)...); }

vll path;

void dijkstra(ll s, vll& dist, const vector<vpll>& g) {

	path[s] = -1;
	ll n = g.size();
	dist[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		ll u = pq.top().second;
		ll d_u = pq.top().first;
		pq.pop();
		if (d_u > dist[u])
			continue;
		for (const auto& v_pair : g[u]) {
			ll v = v_pair.first;
			ll w = v_pair.second;
			if (d_u + w < dist[v]) {
				dist[v] = d_u + w;
				path[v] = u;
				pq.push({ dist[v], v });
			}
		}
	}

}

void solution(ll& T) {

	ll n, m; cin >> n >> m;
	path.clear();
	path.assign(n + 1, 0);
	vector<vpll> v(n + 1);
	for (ll i = 0; i < m; i++) {
		ll x, y, z; cin >> x >> y >> z;
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}
	ll source, dest; cin >> source >> dest;
	vll dist(n + 1, LLONG_MAX);
	dijkstra(source, dist, v);
	ll current_vertex = dest;
	vll store;
	while (current_vertex != -1) {
		store.push_back(current_vertex);
		current_vertex = path[current_vertex];
	}
	reverse(all(store));
	print(dist[dest]);
	print(store);

}

signed main() {
	Parvez();
	ll TT = 1;
	// cin>>TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}
