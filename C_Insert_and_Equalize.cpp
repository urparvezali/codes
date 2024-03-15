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
inline void YES(){cout<<"YES"<<endl;}
inline void NO(){cout<<"NO"<<endl;}
inline void MINUS(){cout<<-1<<endl;}

inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}template<class T>inline void print(vector<T> &v){for(auto &i:v){cout<<i;if(&i!=&v.back())cout<<' ';}cout<<endl;}inline void input(){}template<class H,class... T>inline void input(H &&h,T &&...t){cin>>h;input(forward<T>(t)...);}template<class T>inline void input(vector<T> &v){for(auto &i:v)cin>>i;}




void solution(ll &T){
    ll n; input(n);
    vll v(n); input(v);
    ll mn=*min_element(all(v));
    if(mn<0)
        for(ll& I:v)I-=mn;
    sort(rall(v));

    ll g=v[0];
    for(ll& I:v) g=gcd(g,v[0]-I);
    // print(g);


    ll ans=0;
    for(ll i=1;i<n;i++) ans+=(v[0]-v[i])/g;

    ll k=-1;
    for (ll i = 0,j=v[0]; i < n and j>0; i++,j-=g){
        if(v[i]!=j){
            k=j;break;
        }
    }
    if(k!=-1)
        ans+=min((v[0]-k)/g,n+1);
    else
        ans+=n;
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