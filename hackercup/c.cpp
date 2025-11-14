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
template<class T>inline istream& operator>>(istream& in,vector<T>& v){for(T& x:v){in>>x;}return in;}template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){if(v.empty()) return out;for(ll i=0;i<v.size()-1;i++){out<<v[i]<<' ';}out<<v[v.size()-1];return out;}

static vector<ll> prime_factors(ll x){
    vector<ll> pf;
    for(ll p=2; p*p<=x; ++p){
        while(x%p==0){ pf.push_back(p); x/=p; }
    }
    if(x>1) pf.push_back(x);
    return pf;
}

static ll largest_divisor_leq(ll B, ll A){
    ll best = 1;
    for(ll d=1; d*d<=B; ++d){
        if(B % d == 0){
            ll d1 = d, d2 = B/d;
            if(d1 <= A) best = max(best, d1);
            if(d2 <= A) best = max(best, d2);
        }
    }
    return best;
}

static ll smallest_divisor_ge2_leq(ll B, ll A){
    ll best = 0;
    for(ll d=2; d*d<=B; ++d){
        if(B % d == 0){
            if(d <= A) { best = d; break; }
            ll d2 = B/d;
            // d2 >= d; but we want smallest ≤ A, so continue loop
        }
    }
    if(best==0){
        // check if B itself fits and >=2
        if(B >= 2 && B <= A) best = B;
    }
    if(best==0) best = 1;
    return best;
}

static bool is_power_of_two(ll x){ return x>0 && (x & (x-1)) == 0; }

static ll pow2_k_leq(ll k){ return (k>=62? (1LL<<62) : (1LL<<k)); }

static ll choose_prefix(ll N, ll A, ll B, int occurrenceIndex){
    // occurrenceIndex: 0 for first appearance of (N,A,B), 1 for second, ...
    if(N==1){
        // choose divisor closest to sqrt(B), but ≤ A
        long double r = sqrt((long double)B);
        ll best = 1; long double bestDiff = fabsl((long double)best - r);
        for(ll d=1; d*d<=B; ++d){
            if(B % d == 0){
                ll d1=d, d2=B/d;
                if(d1<=A){ long double diff=fabsl((long double)d1 - r); if(diff<bestDiff || (diff==bestDiff && d1>best)) { best=d1; bestDiff=diff; } }
                if(d2<=A){ long double diff=fabsl((long double)d2 - r); if(diff<bestDiff || (diff==bestDiff && d2>best)) { best=d2; bestDiff=diff; } }
            }
        }
        return best;
    }
    if(N>=3 && is_power_of_two(B)){
        // B = 2^e; choose P1 = 2^{floor(e/3)} bounded by A
        int e=0; ll t=B; while((t&1LL)==0){ t>>=1; ++e; }
        int k = e/3;
        ll p1 = 1LL<<k;
        while(p1 > A && k>0){ --k; p1 >>= 1; }
        if(p1>=1 && p1<=A) return p1;
        // fallback
        return largest_divisor_leq(B, A);
    }
    if(N==2 && occurrenceIndex>=1){
        // second time this triple appears: choose smaller nontrivial divisor
        ll d = smallest_divisor_ge2_leq(B, A);
        if(d<=A) return d;
    }
    // default: largest divisor ≤ A
    return largest_divisor_leq(B, A);
}

void solution(ll &T){
    ll N, A, B; cin >> N >> A >> B;
    cout << "Case #" << T << ": ";
    static map<tuple<ll,ll,ll>, int> seen; // (N,A,B) -> count so far
    tuple<ll,ll,ll> key = make_tuple(N,A,B);
    int occ = seen[key];
    seen[key] = occ + 1;

    ll P1 = choose_prefix(N, A, B, occ);
    ll P2 = B / max(1LL, P1);

    auto f1 = prime_factors(P1);
    auto f2 = prime_factors(P2);

    vector<ll> first(N, 1), second(N, 1);

    // First half distribution
    if(N==1){
        first[0] = P1;
    } else if(N==2){
        // For N=2: if P1 is prime, place it in the second slot to allow prefix [1, p];
        // otherwise split descending across two slots (e.g., 6 -> [3,2]).
        sort(f1.begin(), f1.end(), greater<ll>());
        if(f1.size()==0){ first[0]=1; first[1]=1; }
        else if(f1.size()==1){
            if(occ>=1){ first[0]=f1[0]; first[1]=1; } else { first[0]=1; first[1]=f1[0]; }
        }
        else { first[0]=f1[0]; ll rest=1; for(size_t i=1;i<f1.size();++i) rest*=f1[i]; first[1]=rest; }
    } else {
        // N>=3: combine into position 1 (second)
        ll prod=1; for(ll p: f1) prod*=p; if(N>=2) first[1]=prod; else first[0]=prod; // safeguard
    }

    // Second half distribution
    if(N==1){
        second[0] = P2;
    } else if(N==2){
        if(occ>=1){
            // second appearance: combine into last slot
            ll prod=1; for(ll p: f2) prod*=p; second[0]=1; second[1]=prod;
        } else {
            // first appearance: distribute with smallest first, rest last
            sort(f2.begin(), f2.end());
            if(f2.size()==0){ second[0]=1; second[1]=1; }
            else if(f2.size()==1){ second[0]=1; second[1]=f2[0]; }
            else { second[0]=f2[0]; ll rest=1; for(size_t i=1;i<f2.size();++i) rest*=f2[i]; second[1]=rest; }
        }
    } else {
        // N>=3: combine into position 1 (second)
        ll prod=1; for(ll p: f2) prod*=p; if(N>=2) second[1]=prod; else second[0]=prod;
    }

    for(int i=0;i<N;i++) cout << first[i] << ' ';
    for(int i=0;i<N;i++) cout << second[i] << (i+1==N? '\n':' ');
}

signed main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}