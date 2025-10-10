// Parvez Ali, ICE-13 of PUST
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
    string s;
    cin>>s;
    char f = s[0];
    char l = s[s.length()-1];
    s.erase(0,1); s.erase(s.length()-1,1);

    if (isupper(f)&&(s[0]!='0')&&s.length()==6)
    {
        if (isupper(l))
        {
            int token = 0;
            for (long unsigned int i = 0; i < s.length(); i++)
            {
                if ((s[i] - '0') >= 0 && (s[i] - '0' <= 9))
                {
                    token = 0;
                    continue;
                }
                else
                {
                    token++;
                    break;
                }
            }
            if (token == 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}