// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<char> vchar;
typedef vector<string> vstr;
#define endl '\n'
#define mod (1e9+7)
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL);}

int main(){
    IOS();
    int n;
    cin>>n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    int sum=0,sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        
        if(i==j){
            sum1+=a[i][j];
        }
        if(i==n-j-1){
            sum2+=a[i][j];
        }
    }
    }
    sum = abs(sum1-sum2);
    cout<<sum<<endl;
    return 0;
}