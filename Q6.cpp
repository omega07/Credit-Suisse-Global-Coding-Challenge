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
    string s;
    getline(cin,s);
    string temp = "", f = "";
    stringstream ss(s);
    while(ss >> temp) f += temp;
    int n = f.size();
    int x = sqrt(n), y = 0;
    while(x*x != f.size()) {
        f += '_';
        x = sqrt(f.size());
    }
    x = sqrt(f.size()), y = x;
    n = f.size();
    string ans[y];
    for(int i=0;i<y;i++) {
        ans[i] = f.substr(i*x,min(n-i*x,x));
    }
    
    string aa = "";
    for(int i=0;i<x;i++) {
        string aa = "";
        for(int j=0;j<y;j++) {
            if(ans[j][i] >= 'a' && ans[j][i] <= 'z') aa += ans[j][i];
        }
        cout<<aa<<" ";
    }
    cout<<aa;
}

signed main()
{
    fast;
    solve();
    return 0;   
}
