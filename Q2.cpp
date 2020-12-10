#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
int dp[(int)1e6+1][2];
int inf = 1e6;
int f(int id, int which) {
    if(id >= n) {
        return (!which ? 0 : -inf);
    }
    if(dp[id][which] != -1) return dp[id][which];
    // 0 -> minus, 1 -> plus
    int ans = 0;
    if(!which) {
        ans = max({ans,f(id+1,1)-a[id],f(id+1,0)});
    } else {
        ans = max({ans,f(id+1,0)+a[id],f(id+1,1)});
    }
    return dp[id][which] = ans;
} 


int findMaxProfit(int N, vector<int> A) {
    n = N, a = A;
    memset(dp,-1,sizeof(dp));
    int ans = max(-a[0]+f(1,1),f(1,0));
    // Participant's code will go here
    return ans;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int numOfPredictedTimes = firstLineVec[0];
    vector<int> predictedSharePrices(firstLineVec.begin()+1, firstLineVec.end());


    int result = findMaxProfit(numOfPredictedTimes, predictedSharePrices);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
