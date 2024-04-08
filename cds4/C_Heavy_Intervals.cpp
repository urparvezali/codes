#include <algorithm>
#include <any>
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

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
inline void print(){ cout<<endl; }template<class H,class... T>inline void print(H&& h,T &&...t){ cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }template<class T>inline void print(vector<T>& v){ for(auto& i:v){ cout<<i;if(&i!=&v.back())cout<<' '; }cout<<endl; }inline void input(){}template<class H,class... T>inline void input(H&& h,T &&...t){ cin>>h;input(forward<T>(t)...); }template<class T>inline void input(vector<T>& v){ for(auto& i:v)cin>>i; }

bool comp(vll& a,vll& b){
    return a[0]<b[0] and a[0]<a[1] and b[0]<b[1] and a[1]<b[1];
}

void solution(ll& T){
    ll n; input(n);
    vll l(n),r(n),u(n);
    input(l); input(r); input(u);
    multiset<ll> st;
    for(auto& x:l) st.insert(x);
    sort(all(r));

    vll inv;
    for(ll& x: r){
        auto lb=prev(st.lower_bound(x));
        inv.push_back(x-*lb);
        st.erase(*lb);
    }
    sort(rall(inv)); sort(all(u));
    ll ans=0;
    for(ll i = 0; i < n; i++){
        ans+=inv[i]*u[i];
    }
    print(ans);
}
int32_t main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}