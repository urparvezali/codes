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



void solution(ll& T) {
    ll a, v, l, n; cin >> a >> v >> l >> n;
    if(v>=2 && n<a && a-n>=2){
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
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
