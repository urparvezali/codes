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
    vpll v(n);
    for (ll i = 0; i < n; i++){
        input(v[i].first);v[i].second=i;
    }
    sort(rall(v));
    vll ans(n);

    vll pre(n+1);
    pre[1]=v[0].first;
    for (ll i = 1; i < n+1; i++){
        pre[i+1]+=v[i].first+pre[i];
    }
    // print(pre);

    for (ll i = 0; i < n; i++){

        ll score=pre[n]-pre[i];
        
        ans[v[i].second]+=n-i-1;
        // cout<<score<<' ';

        ll l=0,r=i,m=(l+r)/2,idx=-1;
        while(r>=l){
            m=(l+r)/2;
            if(score>=pre[i]-pre[m]){
                idx=m;
                r=m-1;
            } else {
                l=m+1;
            }
        }
        if(idx!=-1){
            // ans[v[i].second]+=i-idx;
            print("IDX",i-idx);
        }
        // print(idx);
    }
    print(ans);
    // print();
}

int32_t main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}