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

int main() {

  ll n, total;
  cin >> n >> total;
  vll mem(total + 1, 10000000000000000);
  vll coins(n);
  cin >> coins;
  mem[0] = 0;

  for (ll i = 1; i <= total; i++) {
    for (ll j = 0; j < coins.size(); j++) {
      if (i - coins[j] >= 0) {
        mem[i] = min(mem[i], mem[i - coins[j]] + 1);
      }
    }
  }
  cout << (mem[total] == 10000000000000000 ? -1 : mem[total]) << endl;

  return 0;
}
