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
  for (ll i = 0; i < v.size() - 1; i++) {
    out << v[i] << ' ';
  }
  out << v[v.size() - 1];
  return out;
}
inline void input() {}
template <class H, class... T> inline void input(H &&h, T &&...t) {
  cin >> h;
  input(forward<T>(t)...);
}
inline void print() { cout << endl; }
template <class H, class... T> inline void print(H &&h, T &&...t) {
  cout << h;
  if (sizeof...(t) != 0)
    cout << ' ';
  print(forward<T>(t)...);
}

void solution(ll &T) {
  vll v(3);
  cin >> v;
  ll k;
  cin >> k;
  sort(all(v));
  vvll ans;
  for (ll i = 1; i < v[0] + 1; i++) {
    for (ll j = 1; j < v[1] + 1; j++) {
      ll dfff = k / (i * j);
      if (dfff <= v[2] and k % (i * j) == 0) {
        ans.push_back({i, j, dfff});
      }
    }
  }
  if (!ans.size()) {
    print(0);
    return;
  }
  ll mx = 0;
  for (ll i = 0; i < ans.size(); i++) {
    if (v[0] >= ans[i][0] and v[1] >= ans[i][1] and v[2] >= ans[i][2]) {
      ll omg = (v[0] - ans[i][0] + 1) * (v[1] - ans[i][1] + 1) *
               (v[2] - ans[i][2] + 1);
      mx = max(mx, omg);
    }
  }
  print(mx);
}

signed main() {
  Parvez();
  ll TT = 1;
  cin >> TT;
  for (ll T = 1; T <= TT; T++)
    solution(T);
  return 0;
}