#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<string> vstr;
typedef vector<pll> vpll;
typedef map<ll,ll> mll;
typedef map<string,ll> mstrl;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
const ll mod = 998244353;

void YES(){cout<<"YES"<<endl;}
void NO(){cout<<"NO"<<endl;}
void MINUS(){cout<<-1<<endl;}

void print(){cout<<endl;}template<typename T,typename... A>void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}
void input(){}template<typename T,typename... A>void input(T& a,A&... z){cin>>a;input(z...);}
template<typename T>void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}
template<typename T,typename S>void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;}
template<typename T>void input(vector<T>& v){for(auto& i:v)cin>>i;}

bool isprime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
ll bpow(ll a,ll b){ll r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
ll mbpow(ll a,ll b){a%=mod;ll r=1;while(b>0){if(b&1)r=r*a%mod;a=a*a%mod;b>>=1;}return r;}
class Sieve{private:vector<bool> vp;public:Sieve(ll np){vp.resize(np+1,true);vp[0]=vp[1]=false;for(ll i=2;i<=np;i++){if(vp[i]==true){for(ll j=2*i;j<=np;j+=i){vp[j]=false;}}}}bool getprime(ll n){return vp[n];}};
ll b2d(string& b){ll n=0;for(ll i=b.length()-1,j=0;i>=0;--i,++j){if(b[i]=='1'){n+=(1<<j);}}return n;}
vector<ll> d2b(ll n){vector<ll> b;ll r;while(n!=0){r=n&1;b.push_back(r);n>>=1;}reverse(all(b));return b;}

void dfs(ll s,vector<bool>& vs,vvll& v){if(vs[s])return;vs[s]=1;for(auto& c:v[s])dfs(c,vs,v);}
void bfs(ll s,vector<bool>& vs,vvll& v){queue<ll> q;q.push(s);vs[s]=1;while(!q.empty()){ll curr=q.front();q.pop();cout<<curr<<' ';for(ll sib:v[curr]){if(!vs[sib]){q.push(sib);vs[sib]=1;}}}}
void dijkstra(ll s,vll& dist,const vector<vpll>& g){ll n=g.size();dist[s]=0;priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;pq.push({0,s});while(!pq.empty()){ll u=pq.top().second;ll d_u=pq.top().first;pq.pop();if(d_u>dist[u])continue;cout<<"Node:"<<u<<",Distance:"<<d_u<<endl;for(const auto& v_pair:g[u]){ll v=v_pair.first;ll w=v_pair.second;if(d_u+w<dist[v]){dist[v]=d_u+w;pq.push({dist[v],v});}}}}
class segtree{public:ll size;vll sums;segtree(ll n){size=1;while(size<n)size*=2;sums.assign(2*size,0LL);}void set(ll i,ll v,ll x,ll lx,ll rx){if(rx-lx==1){sums[x]=v;return;}ll m=(lx+rx)/2;if(i<m){set(i,v,2*x+1,lx,m);}else{set(i,v,2*x+2,m,rx);}sums[x]=sums[2*x+1]+sums[2*x+2];}void set(ll i,ll v){set(i,v,0,0,size);}ll sum(ll l,ll r,ll x,ll lx,ll rx){if(lx>=r or l>=rx)return 0;if(lx>=l and rx<=r)return sums[x];ll m=(lx+rx)/2;return sum(l,r,2*x+1,lx,m)+sum(l,r,2*x+2,m,rx);}ll sum(ll l,ll r){return sum(l,r,0,0,size);}};


void solution(ll &T){
	ll n; input(n); vll v(n); input(v);
	vll ans;
	ans.push_back(v[0]);
	for (ll i = 1; i < n; i++)
	{
			if(v[i]>=v[i-1]){
				ans.push_back(v[i]);
			}
			else{
				ans.push_back(v[i]);
				ans.push_back(v[i]);
			}
	}
	print(ans.size());
	print(ans);
}

signed main(){
	Parvez Ali
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}