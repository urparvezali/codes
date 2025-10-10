#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll> vll;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1e9+7)

int main(){
    IOS;
    int t;
    cin>>t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;

        int l = stoi(s);
        if(l%5==0){cout<<"Yes"<<endl;}
        else{
        if (l >= 5)
        {
            stringstream ss[n];
            int token = 0;
            for (int i = 0; i < n; i++)
            {
                ss[i] << s[i];
                ss[i] >> l;
                if (l == 0 || l == 5)
                {
                    cout << "Yes" << endl;
                    token++;
                    break;
                }
            }
            if (token == 0)
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
        }
    }
    return 0;
}