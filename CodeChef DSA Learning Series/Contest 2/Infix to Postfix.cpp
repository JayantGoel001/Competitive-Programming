#include<bits/stdc++.h>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
#define forr(a,n) for(int i=a;i<=n;i++)
#define MAX 1000000007LL
#define mod 998244353
#define forn(n,a) for(int i=n;i>=a;i--)
#define all(x) x.begin() , x.end()
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define ll long long
const int N = (int)1e5 + 9;
ll power(ll x,ll y)
{
    if(y == 0)
        return 1;
    ll temp = power(x,y/2);
    if(y%2 == 1)
        return temp*temp*x;
    else    
        return temp*temp;
}

int check(char c)
{
    if(c == '^')
        return 4;
    else if(c == '*' || c == '/')
        return 3;
    else if(c == '+' || c == '-')
        return 2;
    else
        return 0;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        s = "(" + s + ")";

        stack<char> st;
        string ans = "";

        forr(0,s.size()-1)
        {
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                ans += s[i];
            }
            else if(s[i] == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }   
            else{
                while(!st.empty() && check(st.top()) >= check(s[i]) && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }     
                st.push(s[i]);
            }
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}