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
constexpr ll mod=1000000007;

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in,vector<T>& v){ for(T& x:v){ in>>x; }return in; }template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){ for(ll i=0;i<v.size()-1;i++){ out<<v[i]<<' '; }out<<v[v.size()-1];return out; }
inline void input(){}template<class H,class... T>inline void input(H&& h,T &&...t){ cin>>h;input(forward<T>(t)...); }inline void print(){ cout<<endl; }template<class H,class... T>inline void print(H&& h,T &&...t){ cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }
ll digitsum(ll n){
	ll sum=0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
vector<ll> segmentedSieve(ll L,ll R){
	ll lim=sqrt(R);
	vbl mark(lim + 1,false);
	vector<ll> primes;
	for(ll i=2; i <= lim; ++i)
		if(!mark[i]){
			primes.push_back(i);
			for(ll j=i * i; j <= lim; j+=i)
				mark[j]=true;
		}
	vbl isPrime(R - L + 1,true);
	for(ll p:primes)
		for(ll j=max(p * p,(L + p - 1) / p * p); j <= R; j+=p)
			isPrime[j - L]=false;
	vector<ll> result;
	for(ll i=L; i <= R; ++i)
		if(isPrime[i - L])
			result.push_back(i);
	return result;
}
class Sieve{
	vector<bool> vp;

public:
	Sieve(ll np){
		vp.resize(np + 1,true);
		vp[0]=vp[1]=false;
		for(ll i=2; i <= np; i++){
			if(vp[i] == true){
				for(ll j=2 * i; j <= np; j+=i){
					vp[j]=false;
				}
			}
		}
	}
	bool getprime(ll n){ return vp[n]; }
};
bool check(ll n){

}
void solution(ll& T){
	ll n; input(n);
	vll v=segmentedSieve(2,n);
	Sieve s(100);
	ll ans=0;
	for(auto& i:v){
		if(s.getprime(digitsum(i))){
			
		}
	}
	print(ans);
}

int32_t main(){
	Parvez();
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}