#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
constexpr ll mod = 1000000007;

inline void Parvez() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
template <class T> inline istream &operator>>(istream &in, vector<T> &v) {
    for (T &x : v) {
        in >> x;
    }
    return in;
}
template <class T> inline ostream &operator<<(ostream &out, vector<T> &v) {
    if (v.empty())
        return out;
    for (ll i = 0; i < v.size() - 1; i++) {
        out << v[i] << ' ';
    }
    out << v[v.size() - 1];
    return out;
}
inline void inp() {}
template <class H, class... T> inline void inp(H &&h, T &&...t) {
    cin >> h;
    inp(forward<T>(t)...);
}
inline void print() { cout << endl; }
template <class H, class... T> inline void print(H &&h, T &&...t) {
    cout << h;
    if (sizeof...(t) != 0)
        cout << ' ';
    print(forward<T>(t)...);
}

void solution(ll &T) {
    ll n;
    cin >> n;
    vll v(n);
    cin >> v;
    vector<ll> diffs(n, 0);
    vector<ll> counts(32, 0);
    ll ans = 0;
    for (ll b = 0; b < 32; b++) {
        for (ll i = 0; i < n; i++) {
            if (v[i] & (1 << b)) {
                counts[b]++;
            }
        }
        for (ll i = 0; i < n; i++) {
            ll bit = (v[i] & (1 << b)) ? 1 : 0;
            ll ones = counts[b];
            ll zeros = n - counts[b];

            if (bit == 1) {
                diffs[i] += zeros * (1LL << b);
            } else {
                diffs[i] += ones * (1LL << b);
            }
        }
    }
    ll mx_idx = max_element(all(diffs)) - diffs.begin();
    for (ll &x : v)
        ans += (x ^ v[mx_idx]);
    cout << ans << endl;
}

signed main() {
    Parvez();
    ll TT = 1;
    cin >> TT;
    for (ll T = 1; T <= TT; T++)
        solution(T);
    return 0;
}