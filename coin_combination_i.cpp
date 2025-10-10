#include <array>
#include <iostream>
#include <string>
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

template <class T> inline istream &operator>>(istream &in, vector<T> &v) {
    for (T &x : v) {
        in >> x;
    }
    return in;
}
template <class T> inline ostream &operator<<(ostream &out, vector<T> &v) {
    for (ll i = 0; i < v.size() - 1; i++) {
        out << v[i] << ' ';
    }
    out << v[v.size() - 1];
    return out;
}
array<ll, 1000001> mem;
void solution() {
    mem.fill(0);

    ll n, x;
    cin >> n >> x;
    vll coins(n);
    cin >> coins;

    for (ll i = 0; i <= x; i += 1) {
        for (ll j = 0; j < n; j += 1) {
            if (i - coins[j] < 0)
                continue;
            mem[i] = (mem[i]+ mem[i - coins[j]] + (i-coins[j]==0?1:0))%1000000007;
        }
    }
    cout<<mem[x]<<endl;
}
int main() {
    int T = 1;
    // cin >> T;
    while (T--)
        solution();
    return 0;
}
