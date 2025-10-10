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
constexpr ll mod = 1000000007;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
inline void YES(){cout<<"YES"<<endl;}
inline void NO(){cout<<"NO"<<endl;}
inline void MINUS(){cout<<-1<<endl;}

inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}template<class T>inline void print(vector<T> &v){for(auto &i:v){cout<<i;if(&i!=&v.back())cout<<' ';}cout<<endl;}inline void input(){}template<class H,class... T>inline void input(H &&h,T &&...t){cin>>h;input(forward<T>(t)...);}template<class T>inline void input(vector<T> &v){for(auto &i:v)cin>>i;}
#define print(...) print(__VA_ARGS__);
#define input(...) input(__VA_ARGS__);
bool isprime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
ll bpow(ll a,ll b){ll r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
ll mbpow(ll a,ll b){a%=mod;ll r=1;while(b>0){if(b&1)r=r*a%mod;a=a*a%mod;b>>=1;}return r;}
class Sieve{vbl vp;public:Sieve(ll np){vp.resize(np+1,true);vp[0]=vp[1]=false;for(ll i=2;i<=np;i++){if(vp[i]==true){for(ll j=2*i;j<=np;j+=i){vp[j]=false;}}}}bool getprime(ll n){return vp[n];}};
vector<ll> segmentedSieve(ll L, ll R){ll lim=sqrt(R);vbl mark(lim+1,false);vector<ll>primes;for(ll i=2;i<=lim;++i)if(!mark[i]){primes.push_back(i);for(ll j=i*i;j<=lim;j+=i)mark[j]=true;}vbl isPrime(R-L+1,true);for(ll p:primes)for(ll j=max(p*p,(L+p-1)/p*p);j<=R;j+=p)isPrime[j-L]=false;vector<ll>result;for(ll i=L;i<=R;++i)if(isPrime[i-L])result.push_back(i);return result;}
ll b2d(string& b){ll n=0;for(ll i=b.length()-1,j=0;i>=0;--i,++j){if(b[i]=='1'){n+=(1<<j);}}return n;}
vector<ll> d2b(ll n){vector<ll> b;ll r;while(n!=0){r=n&1;b.push_back(r);n>>=1;}reverse(all(b));return b;}
void dijkstra(ll s,vll& dist,const vector<vpll>& g){ll n=g.size();dist[s]=0;priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;pq.push({0,s});while(!pq.empty()){ll u=pq.top().second;ll d_u=pq.top().first;pq.pop();if(d_u>dist[u])continue;for(const auto& v_pair:g[u]){ll v=v_pair.first;ll w=v_pair.second;if(d_u+w<dist[v]){dist[v]=d_u+w;pq.push({dist[v],v});}}}}
void bfs(ll s,vbl& vs,vvll& v){queue<ll> q;q.push(s);vs[s]=1;while(!q.empty()){ll curr=q.front();q.pop();cout<<curr<<' ';for(ll sib:v[curr]){if(!vs[sib]){q.push(sib);vs[sib]=1;}}}}
void dfs(ll s,vbl& vs,vvll& v){if(vs[s])return;vs[s]=1;for(auto& c:v[s])dfs(c,vs,v);}
class segtree{ll size;vll sums;public:segtree(ll n){size=1;while(size<n)size*=2;sums.assign(2*size,0LL);}void set(ll i,ll v,ll x,ll lx,ll rx){if(rx-lx==1){sums[x]=v;return;}ll m=(lx+rx)/2;if(i<m){set(i,v,2*x+1,lx,m);}else{set(i,v,2*x+2,m,rx);}sums[x]=sums[2*x+1]+sums[2*x+2];}void set(ll i,ll v){set(i,v,0,0,size);}ll sum(ll l,ll r,ll x,ll lx,ll rx){if(lx>=r or l>=rx)return 0;if(lx>=l and rx<=r)return sums[x];ll m=(lx+rx)/2;return sum(l,r,2*x+1,lx,m)+sum(l,r,2*x+2,m,rx);}ll sum(ll l,ll r){return sum(l,r,0,0,size);}};


void solution(ll &T){
    ll n,x; input(n,x); vll v(n); input(v);
    ll ans=v[0];
    ll i=0;



    if(x>v[n-1]) ans=max(ans,2*(x-v[n-1]));

    for (i = 1; i < n; i++){
        if(x>v[i]){
            ans=max(ans,v[i]-v[i-1]);
        }
        else {
            ans=max(ans,2*(x-v[i-1]));
            break;
        }
    }
    print(ans);
}

signed main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}