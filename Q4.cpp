#include<bits/stdc++.h>
#define double long double
#define all(x) x.begin(),x.end()
#define px pair< double,pair< double, double>>
using namespace std;

bool cmp(px &a, px &b) {
    double F = a.first*a.second.first - (1.0f-a.first)*a.second.second; 
    double S = b.first*b.second.first - (1.0f-b.first)*b.second.second;
    return (F > S);
}

double maximumExpectedMoney(int n, int m,  double p[],  double x[],  double y[])
{
    vector<px> v(n);
    for(int i=0;i<n;i++) v[i] = {p[i],{x[i],y[i]}};
    sort(all(v),cmp);
    double ans = 0, temp = 0;
    for(int i=0;i<min(n,m);i++) {
        double P = v[i].first, X = v[i].second.first, Y = v[i].second.second, _P = 1.0f-P;
        double T = P*X - _P*Y;
        temp += T;
        ans = max(ans,temp);
    }
    return ans;
}

int main(){
    cout<<fixed<<setprecision(2);
    int n, m;

    cin >> n >> m;
    double p[n], x[n], y[n];

    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> y[i];

    double result=maximumExpectedMoney(n,m,p,x,y);
    result *= 10000;
    int ans = result;
    cout<<(1.0f*ans)/10000;
    return 0;
}
