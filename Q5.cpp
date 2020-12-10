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

int toint(string s) {
    stringstream ss;
    ss << s;
    int x;
    ss >> x;
    return x;
}

bool cmp(pair<int,vi> &a, pair<int,vi> &b) {
    return a.second.size() < b.second.size();
}

map<int,set<int>> convert(string s) {
    map<int,string> b;
    int k = 1;
    string temp = "";
    for(int i=0;i<s.size();i++) {
        if(s[i] == ',') {
            b[k] = temp;
            k++;
            temp = "";
            continue;
        }
        temp += s[i];
        b[k] = temp;
    }
    // see(b);
    map<int,set<int>> bank;
    temp = "", k = 1;
    for(auto i : b) {
        temp = "";
        for(int j=0;j<i.second.size();j++) {
            if(i.second[j] == '&') {
                bank[i.first].insert(toint(temp));
                temp = "";
                continue;   
            }
            temp += i.second[j];
            // bank[k].pb(toint(temp));
        }
        if(temp.size()) bank[i.first].insert(toint(temp));
    }
    return bank;
}



void solve() {
    int n;
    string s;
    int m;
    string f;
    cin>>n>>s>>m>>f;
    map<int,set<int>> bank = convert(s);
    map<int,set<int>> cust = convert(f);
    int ans = 0;
    for(auto i : bank) {
        for(auto j : i.second) {
            cust[j].insert(i.first);
        }
    }
    for(auto i : cust) {
        for(auto j : i.second) {
            bank[j].insert(i.first);
        }
    }
    for(auto i : bank) {
        ans = max(ans,(int)i.second.size());
    }
    for(auto i : cust) {
        ans = max(ans,(int)i.second.size());
    }
    cout<<ans;
}

signed main()
{
    fast;
    solve();
    return 0;   
}
