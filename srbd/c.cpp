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




vector<vector<ll>> sccs;
vector<ll> ids, low, on_stack, st;
ll id_counter;

void dfs(ll at, const vector<vector<ll>>& adj) {
    st.push_back(at);
    on_stack[at] = 1;
    ids[at] = low[at] = id_counter++;

    for (ll to : adj[at]) {
        if (ids[to] == -1) dfs(to, adj);
        if (on_stack[to]) low[at] = min(low[at], low[to]);
    }

    if (ids[at] == low[at]) {
        vector<ll> scc;
        while (true) {
            ll node = st.back();
            st.pop_back();
            on_stack[node] = 0;
            scc.push_back(node);
            if (node == at) break;
        }
        sccs.push_back(scc);
    }
}

vector<vector<ll>> connected(ll n, const vector<vector<ll>>& adj) {
    sccs.clear();
    ids.assign(n + 1, -1);
    low.assign(n + 1, 0);
    on_stack.assign(n + 1, 0);
    st.clear();
    id_counter = 0;

    for (ll i = 1; i <= n; i++) {
        if (ids[i] == -1) {
            dfs(i, adj);
        }
    }

    return sccs;
}

vector<set<ll>> build(ll n, const vector<vector<ll>>& adj, const vector<ll>& scc_id) {
    ll num_sccs = sccs.size();
    vector<set<ll>> scc_adj(num_sccs);
    for (ll u = 1; u <= n; u++) {
        for (ll v : adj[u]) {
            if (scc_id[u] != scc_id[v]) {
                scc_adj[scc_id[u]].insert(scc_id[v]);
            }
        }
    }
    return scc_adj;
}

ll rec_dp(ll scc, ll r, const vector<set<ll>>& scc_adj, vector<vector<ll>>& dp) {
    if (r <= 0) return 0;
    if (dp[scc][r] != -1) return dp[scc][r];

    ll result = sccs[scc].size();

    if (r > 1) {
        for (ll next_scc : scc_adj[scc]) {
            result = max(result, (ll)sccs[scc].size() + rec_dp(next_scc, r - 1, scc_adj, dp));
        }
    }

    return dp[scc][r] = result;
}

void solution(ll& T) {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<vector<ll>> components = connected(n, adj);

    vector<ll> scc_id(n + 1);
    for (ll i = 0; i < components.size(); i++) {
        for (ll city : components[i]) {
            scc_id[city] = i;
        }
    }

    vector<set<ll>> scc_adj = build(n, adj, scc_id);

    ll num_sccs = components.size();
    vector<vector<ll>> dp(num_sccs, vector<ll>(k + 1, -1));

    ll ans = 0;
    for (ll i = 0; i < num_sccs; i++) {
        ans = max(ans, rec_dp(i, k, scc_adj, dp));
    }

    print(ans);
}

signed main() {
    Parvez();
    ll TT = 1;
    cin >> TT;
    for (ll T = 1;T <= TT;T++)
        solution(T);
    return 0;
}