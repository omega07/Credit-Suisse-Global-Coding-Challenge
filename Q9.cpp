#include <bits/stdc++.h>
#define int long long
#define inf 5e18
#define MOD (int)(1e9 + 7)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define pii pair<int,int>
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

void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define see(x...)
#endif

void solve() {
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        int sum = 0;
        for(int j=0;j<n;j++) {
            sum += a[j][i];
        }
        sum -= a[i][i];
        mp[sum]++;
    }
    int f = 0; 
    for(auto i : mp) {
        f += (i.second%2);
    }
    cout<<(f <= 1 ? "Possible":"Impossible");
    return;
}

signed main()
{
    fast;
    test {
        solve();
        if(t > 0) cout<<",";
    }
    return 0;   
}
