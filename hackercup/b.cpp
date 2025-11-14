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
template<class T>inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) { in >> x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v) { if (v.empty()) return out;for (ll i = 0;i < v.size() - 1;i++) { out << v[i] << ' '; }out << v[v.size() - 1];return out; }



struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n); r.assign(n, 0); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; if (r[a] < r[b]) swap(a, b); p[b] = a; if (r[a] == r[b]) r[a]++; return true; }
};

struct Edge {
    ll u, v;
    ll w;
};
void solution(ll& T) {
    ll n; cin >> n;
    vll a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];

    vector<Edge> edges; edges.reserve(2 * n);
    for (ll i = 1; i <= n; i++) {
        edges.push_back({0, i, a[i]});
    }
    for (ll i = 1; i < n; i++) {
        edges.push_back({i, i + 1, llabs(a[i] - a[i + 1])});
    }
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) { return a.w < b.w; });
    DSU dsu(n + 1);
    ll taken = 0, ans = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans = max(ans, e.w);
            if (++taken == n) break;
        }
    }
    cout << "Case #" << T << ": " << ans << '\n';

}


signed main() {
    Parvez();
    ll TT = 1;
    cin >> TT;
    for (ll T = 1;T <= TT;T++)
        solution(T);
    return 0;
}