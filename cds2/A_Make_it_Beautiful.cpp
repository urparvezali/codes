#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<char> vchar;
typedef vector<string> vstr;
#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
#define rep(i,b) for(ll i=0;i<b;i++)
#define rrep(i,b) for(ll i=b-1;i>=0;i--)
#define repo(i,b) for(ll i=1;i<b;i++)
#define rrepo(i,b) for(ll i=b-1;i>=1;i--)
const ll mod = 998244353;
//const ll nprime = 10000000;
//vector<bool> prime(nprime,true);

void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void vecin(vll &v){for(auto &i:v)cin>>i;}
void vecout(vll &v){for(auto &i:v)cout<<i<<" ";}
ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
bool isprime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
ll bpow(ll a,ll b){if(b==0)return 1;ll r=bpow(a,b/2);if(b&1)return (a*(r*r));else return (r*r);}
ll mbpow(ll a,ll b){if(b==0)return 1;ll r=mbpow(a,b/2);if(b&1)return (a*(r*r)%mod)%mod;else return (r*r)%mod;}
ll fact(ll n){if(n<=1)return 1;return n*fact(n-1);}
ll mfact(ll n){if(n==1)return 1;return (n*mfact(n-1))%mod;}
// void sieve(){prime[0]=prime[1]=false;for(ll i=2;i<=nprime;i++){if(prime[i]==true){for(ll j=2*i;j<=nprime;j+=i){prime[j]=false;}}}}

void solution(ll &tc){
	ll n; cin>>n; deque<ll> v(n);
	for(auto &x:v) cin>>x;
	sort(v.begin(),v.end());
	vll vv;
	for (ll i = 0; i < n; i++){
		if(i%2==0){
			vv.push_back(v.front()); v.pop_front();
		}
		else{
			vv.push_back(v.back()); v.pop_back();
		}
	}
	ll sum=0;
	for (ll i = 0; i < vv.size(); i++)
	{
		if(sum==vv[i]){
			N(); return;
		}
		else sum+=vv[i];
	}
	Y();
	vecout(vv);cout<<endl;
}


signed main(){
	Parvez Ali
	ll tcs; tcs=1;
	cin>>tcs;
	for(ll tc=1;tc<=tcs;tc++)
		solution(tc);
	return 0;
}