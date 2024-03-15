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

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}template<class T>inline void print(vector<T> &v){for(auto &i:v){cout<<i;if(&i!=&v.back())cout<<' ';}cout<<endl;}inline void input(){}template<class H,class... T>inline void input(H &&h,T &&...t){cin>>h;input(forward<T>(t)...);}template<class T>inline void input(vector<T> &v){for(auto &i:v)cin>>i;}

inline void print(vbl& v){for(bool i:v)cout<<(i?'1':'0')<<' ';print();}

void solution(ll &T){
    ll m; input(m);
    vector<ll> cnt(30); 
    for (int i=0; i<m; i++) {
        ll t,v; input(t,v);
        if(t==1){
            cnt[v]++;
        } else {
            for (ll j=29; j>=0; j--) {
                ll take = min(v>>j,cnt[j]);
                v-=take<<j;
            }
            print(v?"NO":"YES");
        }
    }
}

int32_t main(){
    Parvez();
    ll TT=1;
    // cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    // print(dp);
    return 0;
}