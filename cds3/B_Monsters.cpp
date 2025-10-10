#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<string> vstr;
typedef vector<pair<ll,ll>> vpll;
typedef map<ll,ll> mll;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
const ll mod = 998244353;

void YES(){cout<<"YES"<<endl;} void NO(){cout<<"NO"<<endl;} void MINUS(){cout<<-1<<endl;} void print(){cout<<endl;} void print(const ll &x){cout<<x<<endl;} void print(const ll &x,const ll &y){cout<<x<<" "<<y<<endl;} void print(const float &x){cout<<x<<endl;} void print(const float &x,const float &y){cout<<x<<" "<<y<<endl;} void print(const double &x){cout<<x<<endl;} void print(const double &x,const double &y){cout<<x<<" "<<y<<endl;} void print(const char &c){cout<<c<<endl;} void print(const char &x,const char &y){cout<<x<<" "<<y<<endl;} void print(const string &s){cout<<s<<endl;} void print(const string &x,const string &y){cout<<x<<" "<<y<<endl;} void print(bool &x){cout<<(x?"true":"false")<<endl;} void vecin(vll &v){for(auto &i:v)cin>>i;} void vecout(vll &v){for(auto &i:v)cout<<i<<" ";cout<<endl;}
// ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
// ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
bool isprime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
ll bpow(ll a,ll b){ll r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
ll mbpow(ll a,ll b){a%=mod;ll r=1;while(b>0){if(b&1)r=r*a%mod;a=a*a%mod;b>>=1;}return r;}
ll fact(ll n){if(n<=1)return 1;return n*fact(n-1);}
ll mfact(ll n){if(n==1)return 1;return (n*mfact(n-1))%mod;}
class Sieve{private:vector<bool> vp;public:Sieve(ll np){vp.resize(np+1,true);vp[0]=vp[1]=false;for(ll i=2;i<=np;i++){if(vp[i]==true){for(ll j=2*i;j<=np;j+=i){vp[j]=false;}}}}bool getprime(ll n){return vp[n];}};
ll b2d(string &b){ll n=0;for(ll i=b.length()-1,j=0;i>=0;--i,++j){if(b[i]=='1'){n+=(1<<j);}}return n;}
vector<ll> d2b(ll n){vector<ll> b;ll r;while(n!=0){r=n&1;b.push_back(r);n>>=1;}reverse(all(b));return b;}
void dfs(ll n,vector<bool> &vs, vvll &v){if(vs[n])return;vs[n]=1;for(auto &i:v[n])dfs(i,vs,v);}


void solution(ll &T){
	/* ll n,k; cin>>n>>k;
	priority_queue<pair<ll,ll>> q;
	for (ll i = 0; i < n; i++)
	{
		ll x; cin>>x;
		q.push({x,n-i});
	}
	vll v;
	while (q.size())
	{
		pair<ll,ll> tmp=q.top();q.pop();
		// print(tmp.first,tmp.second);
		tmp.first-=k;
		if(tmp.first>0){
			q.push(tmp);
		}
		else{
			v.push_back(n-tmp.second+1);
		}
	}
	vecout(v); */

	ll n,k; cin>>n>>k;
	vpll v; 
	for (ll i = 0; i < n; i++){
		ll x; cin>>x; ll carry=x%k;
		if(carry==0) cout<<i+1<<" ";
		else v.push_back({carry,n-i});
	}
	sort(all(v),greater<pair<ll,ll>> ());
	for (ll i = 0; i < v.size(); i++){
		cout<<n-v[i].second+1<<" ";
	}
	print();
}

signed main(){
	Parvez Ali
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}