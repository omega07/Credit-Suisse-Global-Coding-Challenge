#include <bits/stdc++.h>
#define int long long
#define inf 5e18
#define MOD (int)(1e9 + 7)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                       \
    ios_base ::sync_with_stdio(0); \
    cin.tie(NULL);                 \
    cout.tie(NULL)
using namespace std;


void solve()
{
    int n, d;
    cin >> n >> d;
    vi a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    string ans = "";
        
    while(d--)
    {
        map<int, int> mp;
        int p;
        cin >> p;
        int f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > p && mp[a[i] - p])
            {
                ans += to_string(mp[a[i]-p]), ans += " ", ans += to_string(i), ans += ",";
                f = 1;
            }
            if(f) break;
            mp[a[i]] = i;
        }
        if (!f) {
            ans += "-1", ans += ",";
        }
        
    }
    ans.pop_back();
    cout<<ans;
    return;
}


signed main()
{
    solve();
    return 0;
}
