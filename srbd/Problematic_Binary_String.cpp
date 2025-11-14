#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 1000000007;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template<class T>inline istream& operator>>(istream& in,vector<T>& v){for(T& x:v){in>>x;}return in;}template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){for(ll i=0;i<v.size()-1;i++){out<<v[i]<<' ';}out<<v[v.size()-1];return out;}
inline void inp(){}template<class H,class... T>inline void inp(H&& h,T &&...t){cin>>h;inp(forward<T>(t)...);}inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}




void solution(ll &T){
    ll n;
    cin>>n;
    string s; 
    cin>>s;
    vector<int> b(n);
    for(ll i=0; i<n; i++){
        int target = (i%2 == 0) ? 0 : 1;
        b[i] = (s[i] - '0') ^ target;
    }
    if(n == 1){
        print(b[0]);
        return;
    }
    ll ans = LLONG_MAX;
    for(int x0=0; x0<2; x0++){
        vector<int> x(n);
        x[0] = x0;
        x[1] = b[0] ^ x[0];
        for(ll i=1; i<n-1; i++){
            x[i+1] = b[i] ^ x[i-1] ^ x[i];
        }
        bool valid = (x[n-2] ^ x[n-1]) == b[n-1];
        if(valid){
            ll cnt = 0;
            for(int val : x) cnt += val;
            ans = min(ans, cnt);
        }
    }
    if(ans == LLONG_MAX){
        print(-1);
    }else{
        print(ans);
    }
}

signed main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}