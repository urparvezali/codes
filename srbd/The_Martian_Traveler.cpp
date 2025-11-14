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
template<class T>inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) { in >> x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v) { if (v.empty()) return out; for (ll i = 0;i < v.size() - 1;i++) { out << v[i] << ' '; }out << v[v.size() - 1];return out; }


void dfs(ll s, vbl& vs, vvll& v, ll target, vvll& cc, vll& path) {
    if (s == target && vs[target]) {
        cc[target]=path;
        return;
    }
    if (vs[s])
        return;
    vs[s] = 1;
    path.push_back(s);
    for (auto& c : v[s])
        dfs(c, vs, v, target, cc, path);
    if (path.size()) path.pop_back();
}
void find_connected(vvll& g, vvll& cc) {
    for (ll i = 0; i < g.size(); i++) {
        vbl vs(g.size(), false);
        vll tmp;
        dfs(i, vs, g, i, cc, tmp);
    }
}
void solution(ll& T) {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> g(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vvll cc(g.size());
    find_connected(g, cc);

    for (auto xx : cc) {
        cout << xx << endl;
    }
}

signed main() {
    Parvez();
    ll TT = 1;
    cin >> TT;
    for (ll T = 1;T <= TT;T++)
        solution(T);
    return 0;
}