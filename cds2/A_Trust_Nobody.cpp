#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<string> vstr;
#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
#define forz(i,b) for(ll i=0;i<b;i++)
#define foro(i,b) for(ll i=1;i<=b;i++)
#define forr(i,b) for(ll i=b-1;i>=0;i--)
#define forro(i,b) for(ll i=b;i>=1;i--)
const ll mod = 998244353;
//const ll nprime = 10000000;
//vector<bool> prime(nprime,true);

void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void M(){cout<<-1<<endl;}
void vecin(vll &v){for(auto &i:v)cin>>i;}
void vecout(vll &v){for(auto &i:v)cout<<i<<" ";}
ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
bool isprime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
ll bpow(ll a,ll b){ll r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
ll mbpow(ll a,ll b){a%=mod;ll r=1;while(b>0){if(b&1)r=r*a%mod;a=a*a%mod;b>>=1;}return r;}
ll fact(ll n){if(n<=1)return 1;return n*fact(n-1);}
ll mfact(ll n){if(n==1)return 1;return (n*mfact(n-1))%mod;}
// void sieve(){prime[0]=prime[1]=false;for(ll i=2;i<=nprime;i++){if(prime[i]==true){for(ll j=2*i;j<=nprime;j+=i){prime[j]=false;}}}}
ll b2d(string &b){ll n=0;for(ll i=b.length()-1,j=0;i>=0;--i,++j){if(b[i]=='1'){n+=(1<<j);}}return n;}
vector<ll> d2b(ll n){vector<ll> b;ll r;while(n!=0){r=n&1;b.push_back(r);n>>=1;}reverse(all(b));return b;}


void solution(ll &T){
	ll n; cin>>n;
	vll v(n); vecin(v);
	map<ll,ll> mp;
	for(auto &i:v) mp[i]++;
	ll c=0;
	for (ll i = 0; i < n; i++)
	{
		if(n-mp[i+1]==i+1){
			cout<<i+1<<endl;
			return;
		}
	}
	
	
	cout<<-1<<endl;
}


signed main(){
	Parvez Ali
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}